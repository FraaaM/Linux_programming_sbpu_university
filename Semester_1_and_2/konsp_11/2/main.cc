/*clang++ -fsanitize=address -fno-omit-frame-pointer -o otv main.cc
*/
#include <iostream>
#include <cstring>
#include <sys/mman.h>
#include <unistd.h>

class ByteBuffer {
public:
    // Конструктор по умолчанию
    ByteBuffer() : data(nullptr), size(0) {}

    // Конструктор, инициализирующий буфер с указанным размером
    explicit ByteBuffer(size_t size) : size(size) {
        data = static_cast<uint8_t*>(mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));

        if (data == MAP_FAILED) {
            perror("failed use mmap");
            exit(EXIT_FAILURE);
        }
    }

    // Конструктор перемещения
    ByteBuffer(ByteBuffer&& dif) noexcept : data(dif.data), size(dif.size) {
        // Не забываем обнулить данные у временного объекта
        dif.data = nullptr;
        dif.size = 0;
    }

    // Оператор перемещения
    ByteBuffer& operator=(ByteBuffer&& dif) noexcept {
        if (this != &dif) {
            // Освобождаем текущие ресурсы
            if (data != nullptr) {
                if (munmap(data, size) == -1) {
                    perror("failed to deallocate memory using munmap");
                    exit(EXIT_FAILURE);
                }
            }

            // Перемещаем ресурсы
            data = dif.data;
            size = dif.size;

            // Обнуляем данные у временного объекта
            dif.data = nullptr;
            dif.size = 0;
        }

        return *this;
    }

    // Деструктор
    ~ByteBuffer() {
        if (data != nullptr) {
            if (munmap(data, size) == -1) {
                perror("Failed to deallocate memory using munmap");
                exit(EXIT_FAILURE);
            }
        }
    }
    // Метод для получения указателя на данные
    uint8_t* go_Data() const {
        return data;
    }
    // Метод для получения размера буфера
    size_t go_Size() const {
        return size;
    }

private:
    uint8_t* data;  // Указатель на данные
    size_t size;    // Размер буфера
};

int main() {
    
    // buffer.go_Data() получение доступа к данным
    // buffer.go_Size() получениe размера буферa
    
    // Пример использования
    size_t bufferSize = 100;  // pазмер буфера 100 байт

    ByteBuffer buffer(bufferSize);

    std::cout << "ByteBuffers size: " << buffer.go_Size() << " bytes" << std::endl;
    //конструктор перемещения
    ByteBuffer firstBuffer = std::move(buffer);
    //оператор перемещения
    ByteBuffer secondBuffer;
    secondBuffer = std::move(firstBuffer);

    return 0;
}
