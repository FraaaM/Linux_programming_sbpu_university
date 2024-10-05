#include <iostream>
#include <cstring>
#include <sys/mman.h>
#include <unistd.h>

class ByteBuffer {
public:
    // Конструктор по умолчанию
    ByteBuffer() : data(nullptr), size(0) {}
    
    // Конструктор перемещения
    ByteBuffer(ByteBuffer&& dif) noexcept : data(dif.data), size(dif.size) {
        // Не забываем обнулить данные у временного объекта
        dif.data = nullptr;
        dif.size = 0;
    }
// Конструктор, инициализирующий буфер с указанным размером
    explicit ByteBuffer(size_t size) : size(size) {
        data = static_cast<uint8_t*>(mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));

        if (data == MAP_FAILED) {
            perror("Failed to allocate memory using mmap");
            exit(EXIT_FAILURE);
        }
    }

    // Оператор перемещения
    ByteBuffer& operator=(ByteBuffer&& dif) noexcept {
        if (this != &dif) {
            // Освобождаем текущие ресурсы
            if (data != nullptr) {
                if (munmap(data, size) == -1) {
                    perror("Failed to deallocate memory using munmap");
                    exit(EXIT_FAILURE);
                }
            }
            // перемещаем 
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

    // Метод получения указателя на данные
    uint8_t* go_Data() const {
        return data;
    }

    // Метод получения размера буфера
    size_t go_Size() const {
        return size;
    }

    // Метод изменения размера выделенной области памяти
    void resize(size_t n_Size) {
        uint8_t* n_Data = static_cast<uint8_t*>(mremap(data, size, n_Size, MREMAP_MAYMOVE));

        if (n_Data == MAP_FAILED) {
            perror("Failed to resize memory using mremap");
            exit(EXIT_FAILURE);
        }

        data = n_Data;
        size = n_Size;
    }

private:
    uint8_t* data;  // Указатель на данные
    size_t size;    // Размер буфера
};

int main() {
	
     // buffer.go_Data() получение доступа к данным
    // buffer.go_Size() получениe размера буферa	
	
    // Пример использования
    size_t bufferSize = 100;  // Размер буфера 100 байт

    ByteBuffer buffer(bufferSize);

    std::cout << "ByteBuffer created with size: " << buffer.go_Size() << " bytes" << std::endl;

    // Изменение размера буфера 200
    size_t  firstBufferSize = 200;
    buffer.resize( firstBufferSize);

    std::cout << "ByteBuffer resized to: " << buffer.go_Size() << " bytes" << std::endl;

    return 0;
}
