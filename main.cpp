#include <iostream>
#include <stdexcept>

class smart_array {
public:
    smart_array(size_t size) : size_(0), capacity_(size), array_(new int[size]) {
    }

    ~smart_array() {
        delete[] array_;
    }

    void add_element(int value) {
        if (size_ == capacity_) {
            throw std::out_of_range("add_element error: array if full");
        }
        array_[size_] = value;
        ++size_;
    }

    int get_element(size_t idx) const {
        if (idx >= size_) {
            throw std::out_of_range("idx is more than array size");
        }
        return array_[idx];
    }

    int& get_element(size_t idx) {
        if (idx >= size_) {
            throw std::out_of_range("idx is more than array size");
        }
        return array_[idx];
    }

private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    int* array_ = nullptr;
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
