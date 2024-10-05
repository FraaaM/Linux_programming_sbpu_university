#include <fstream>
#include <iostream>
#include <vector>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <fcntl.h>

class File {
public:
    File() : fileDescriptor(-1) {} // Конструктор по умолчанию, инициализирует fileDescriptor значением -1 (нейтральное состояние)

    explicit File(const char* filename, int flags) { // Конструктор с параметрами
        fileDescriptor = open(filename, flags, 0666); // Открытие файла и сохранение его дескриптора
        check(fileDescriptor, "File opening failed");
    }

    File(const File& other) { // Конструктор копирования
        fileDescriptor = dup(other.fileDescriptor); // Копирование файлового дескриптора с помощью функции dup
        check(fileDescriptor, "File descriptor copy failed");
    }

    File& operator=(const File& other) { // Оператор копирования
        if (this != &other) {
            close(fileDescriptor); // Закрытие текущего файла
            fileDescriptor = dup(other.fileDescriptor); // Копирование файлового дескриптора с помощью функции dup
            check(fileDescriptor, "File descriptor copy failed");
        }
        return *this;
    }

    File(File&& other) noexcept { // Конструктор перемещения
        fileDescriptor = other.fileDescriptor; // Перемещение файлового дескриптора
        other.fileDescriptor = -1; // Установка нейтрального состояния для другого объекта
    }

    File& operator=(File&& other) noexcept { // Оператор перемещения
        if (this != &other) {
            std::swap(fileDescriptor, other.fileDescriptor); // Обмен файловыми дескрипторами для обеспечения безопасного перемещения
        }
        return *this;
    }

    ~File() { // Деструктор
        if (fileDescriptor != -1) {
            close(fileDescriptor); // Закрытие файла, если он был открыт
        }
    }

    // Метод записи в файл
    void write(const std::string& data) {
        ssize_t bytesWritten = ::write(fileDescriptor, data.c_str(), data.size());
        check(bytesWritten, "Error occurred while writing to file");
    }

    // Метод чтения из файла
    std::string read(size_t size) {
        char* buffer = new char[size + 1];
        ssize_t bytesRead = ::read(fileDescriptor, buffer, size);
        check(bytesRead, "Error occurred while reading from file");
        buffer[bytesRead] = '\0'; // Добавляем завершающий нулевой символ, чтобы создать корректную строку C
        std::string data(buffer);
        delete[] buffer; // Освобождаем буфер
        return data;
    }

private:
    int fileDescriptor; // Файловый дескриптор

    void check(int result, const char* msg) { // Вспомогательная функция для проверки ошибок при системных вызовах
        if (result == -1) {
            perror(msg);
        }
    }
};

int main() {
    {
        File myFile("test.txt", O_RDWR|O_CREAT); // Создание объекта myFile, который открывает и создает файл "example.txt"
        myFile.write("ONO RABOTAET!!!!\n"); // Запись в файл
        std::string data = myFile.read(12); // Чтение из файла
        // ... использование объекта myFile
    } // myFile выходит из области видимости и будет уничтожен здесь, вызывая деструктор

    return 0;
}


