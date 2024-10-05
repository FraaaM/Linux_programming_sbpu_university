#include <fstream>
#include <iostream>
#include <cerrno>

class File {
public:
    // Конструктор по умолчанию
    File() : file() {}

    // Конструктор с параметрами
    explicit File(const char* filename, std::ios_base::openmode mode) : file(filename, mode) {
        if (!file.is_open()) {
            check(errno, "File opening failed");
        }
    }

    // Конструктор перемещения
    File(File&& other) noexcept {
        file = std::move(other.file);
        other.file.close(); // Закрываем старый файл, чтобы избежать двойного закрытия
    }

    // Оператор перемещения
    File& operator=(File&& other) noexcept {
        if (this != &other) {
            file = std::move(other.file);
            other.file.close(); // Закрываем старый файл
        }
        return *this;
    }

    // Деструктор
    ~File() {
        if (file.is_open()) {
            file.close();
        }
    }

    // Метод записи в файл
    void write(const std::string& data) {
        file << data;
        file.flush(); // Принудительная сброс буфера на диск
        if (!file.good()) {
            check(errno, "Error occurred while writing to file");
        }
    }

    // Метод чтения из файла
    std::string read() {
        // Устанавливаем позицию указателя в файле в начало
        file.seekg(0, std::ios::beg);

        std::string data;
        std::string line;
        while (std::getline(file, line)) {
            data += line + "\n";
        }
        return data;
    }

private:
    std::fstream file; // Файловый поток

    // Вспомогательная функция для проверки ошибок
    void check(int errnum, const char* msg) {
        if (errnum != 0) {
            perror(msg);
        }
    }
};

int main() {
    {
        File myFile("test.txt", std::ios::out | std::ios::in | std::ios::trunc);
        myFile.write("ono rabotaet!!!!!!\n");
        std::cout << "Data read from file: " << myFile.read() << std::endl;
    } // myFile выходит из области видимости и будет уничтожен здесь, вызывая деструктор

    return 0;
}

