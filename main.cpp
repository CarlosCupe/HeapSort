#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>
#include <math.h>

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsort(int* array, size_t size);
bool validate(int* array, size_t size);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    printArray(numbers, numberOfElements);
    heapsort(numbers, numberOfElements);
    printArray(numbers, numberOfElements);
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");

    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max); 
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int parent (int n){
    return floor((n-1)/2);
}

void heapify(int* array, int child, int p) {
    if (p < 0 || p == child)
        return;
    if (array[p] > array[child])
        return;
    else
        swap(array[child], array[p]);
        heapify(array, p, parent(p));
}

void heap(int* array, size_t size) {
    for (int i = 0; i < size; ++i) {
        heapify(array, i, parent(i));
    }
}

void heapsort(int* array, size_t size) {
    // TODO
    for (int i = size; i > 0; --i) {
        heap(array, i);
        swap(array[0], array[i - 1]);
    }
}

bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}