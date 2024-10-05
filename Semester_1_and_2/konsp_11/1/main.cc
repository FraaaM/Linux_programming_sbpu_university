#include <sys/mman.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

class ByteBuffer {
public:
    // Конструктор инициализирующий буфер с указанным размером
    ByteBuffer(size_t size) : size(size) {
        data = static_cast<uint8_t*>(mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));

        if (data == MAP_FAILED) {
            perror("fail allocate memory usе mmap");
            exit(EXIT_FAILURE);
        }
    }
    // деструктор освобождающий выделенную память
    ~ByteBuffer() {
        if (munmap(data, size) == -1) {
            perror("failе deallocate memory usе munmap");
            exit(EXIT_FAILURE);
        }
    }
    // метод получения указателя на данные
    uint8_t* go_Data() const {
        return data;
    }
    // метод получения размера буфера
    size_t go_Size() const {
        return size;
    }
    
private:
    uint8_t* data;  // указатель на данные
    size_t size;    // размер буфера
};

int main() {
    // buffer.go_Data() доступ к данным
    // buffer.go_Size() получениe размера буфера
    
    // Пример использования
    size_t bufferSize = 100;  // pазмер буфера 100 байm

    ByteBuffer buffer(bufferSize);

    std::cout << "ByteBuffers size: " << buffer.go_Size() << " bytes" << std::endl;

    return 0;
}
