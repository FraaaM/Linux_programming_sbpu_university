#include <iostream>
#include <fstream>
#include <string>

class File {
private:
    std::fstream file;

public:
    File(const std::string& filename) {
        file.open(filename, std::ios::out | std::ios::in | std::ios::trunc);
        check(file.is_open(), "Error opening file");
    }
	// Деструктор
    ~File() {
        if (file.is_open()) {
            file.close();
        }
    }

    void write(const std::string& data) {
        file << data;
        check(!file.fail(), "Error writing to file");
    }

    std::string read() {
        std::string data;
        file.seekg(0, std::ios::beg); // Устанавливаем позицию для чтения в начало файла
        std::getline(file, data, '\0');
        check(!file.fail(), "Error reading from file");
        return data;
    }

private:
    void check(bool condition, const std::string& errorMessage) {
        if (!condition) {
            std::cerr << errorMessage << std::endl;
        }
    }
};

int main() {
    File myFile("example.txt");

    myFile.write("write in file");

    std::string data = myFile.read();
    std::cout << "Data read from file: " << data << std::endl;

    // Файл будет автоматически закрыт при выходе из области видимости
    return 0;
}

