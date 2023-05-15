#include <iostream>

class DynamicArray {
private:
    int* arr;
    int size;

public:
    DynamicArray(int n) : size(n) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                arr[i] = i - 1;
            } else {
                arr[i] = i;
            }
        }
    }

    ~DynamicArray() {
        delete[] arr;
    }

    int getSumOfPositiveElements() const {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] > 0) {
                sum += arr[i];
            }
        }
        return sum;
    }
};

int main() {
    // Створення об'єкту класу DynamicArray з розміром 14
    DynamicArray array(14);

    // Знаходження суми додатніх елементів
    int sum = array.getSumOfPositiveElements();

    // Виведення результату
    std::cout << "Sum of positive elements: " << sum << std::endl;

    return 0;
}