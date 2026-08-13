// gcc -std=c17 -Wall -Wextra -o task34 task34.c && ./task34

#include <iostream>

class IntBuffer {
public:
    explicit IntBuffer(std::size_t size)
        : size_(size), data_(new int[size]) {
        std::cout << "Конструктор: выделено " << size_ << " элементов\n";
        for (std::size_t i = 0; i < size_; ++i) data_[i] = 0;
    }

    ~IntBuffer() {
        std::cout << "Деструктор: освобождение памяти\n";
        delete[] data_;
    }

    IntBuffer(const IntBuffer&) = delete;
    IntBuffer& operator=(const IntBuffer&) = delete;

    int& at(std::size_t index) { return data_[index]; }
    std::size_t size() const { return size_; }

private:
    std::size_t size_;
    int* data_;
};

int main() {
    {
        IntBuffer buffer(5);
        for (std::size_t i = 0; i < buffer.size(); ++i) buffer.at(i) = static_cast<int>(i * i);
        for (std::size_t i = 0; i < buffer.size(); ++i) std::cout << buffer.at(i) << ' ';
        std::cout << '\n';
    } // деструктор вызывается автоматически здесь

    std::cout << "После выхода из блока ресурс уже освобождён\n";
    return 0;
}
