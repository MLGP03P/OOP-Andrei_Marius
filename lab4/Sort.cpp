#include "Sort.h"
#include <iostream>
#include <cstdarg>
#include <cstdlib>
#include <cstring>


static int Partition(int* arr, int low, int high, bool crescator) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        bool conditie = crescator ? (arr[j] < pivot) : (arr[j] > pivot);
        if (conditie) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

static void QuickSortRecursive(int* arr, int low, int high, bool crescator) {
    if (low < high) {
        int pi = Partition(arr, low, high, crescator);
        QuickSortRecursive(arr, low, pi - 1, crescator);
        QuickSortRecursive(arr, pi + 1, high, crescator);
    }
}


Sort::Sort(int nrVal, int minVal, int maxVal) {
    this->nrElemente = nrVal;
    this->elemente = new int[nrVal];
    for (int i = 0; i < nrVal; i++) {
        this->elemente[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

Sort::Sort(std::initializer_list<int> list) {
    this->nrElemente = (int)list.size();
    this->elemente = new int[this->nrElemente];
    int i = 0;
    for (int val : list) {
        this->elemente[i++] = val;
    }
}

Sort::Sort(int* vector, int size) {
    this->nrElemente = size;
    this->elemente = new int[size];
    for (int i = 0; i < size; i++) {
        this->elemente[i] = vector[i];
    }
}

Sort::Sort(int size, ...) {
    this->nrElemente = size;
    this->elemente = new int[size];

    va_list args;
    va_start(args, size);
    for (int i = 0; i < size; i++) {
        this->elemente[i] = va_arg(args, int);
    }
    va_end(args);
}

Sort::Sort(const char* str) {
    int size = 0, putere = 1, numar = 0, current = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ',') size++;
    }
    size++;

    this->elemente = new int[size];
    this->nrElemente = size;

    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] != ',') {
            numar += putere * (str[i] - '0');
            putere *= 10;
        }
        else {
            this->elemente[current] = numar;
            current++;
            numar = 0;
            putere = 1;
        }
    }
    this->elemente[current] = numar;

    for (int i = 0; i < size / 2; i++) {
        int temp = this->elemente[i];
        this->elemente[i] = this->elemente[size - 1 - i];
        this->elemente[size - 1 - i] = temp;
    }
}

void Sort::InsertSort(bool crescator) {
    for (int i = 1; i < nrElemente; i++) {
        int key = elemente[i];
        int j = i - 1;

        if (crescator) {
            while (j >= 0 && elemente[j] > key) {
                elemente[j + 1] = elemente[j];
                j--;
            }
        }
        else {
            while (j >= 0 && elemente[j] < key) {
                elemente[j + 1] = elemente[j];
                j--;
            }
        }
        elemente[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < nrElemente - 1; i++) {
            bool conditie = ascendent ? (elemente[i] > elemente[i + 1]) : (elemente[i] < elemente[i + 1]);
            if (conditie) {
                int temp = elemente[i];
                elemente[i] = elemente[i + 1];
                elemente[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}

void Sort::QuickSort(bool ascendent) {
    QuickSortRecursive(this->elemente, 0, this->nrElemente - 1, ascendent);
}

void Sort::Print() {
    for (int i = 0; i < nrElemente; i++) {
        std::cout << elemente[i];
        if (i < nrElemente - 1) std::cout << ", ";
    }
    std::cout << "\n";
}

int Sort::GetElementsCount() {
    return nrElemente;
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < nrElemente) {
        return elemente[index];
    }
    return -1;
}