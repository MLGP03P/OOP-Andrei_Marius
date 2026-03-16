#ifndef SORT_H
#define SORT_H

#include <initializer_list>

class Sort {
    private:
        int* elemente;
		int nrElemente;

    public:
        Sort(int nrVal, int minVal, int maxVal);
        Sort(std::initializer_list<int> list);
		Sort(int* vector, int size);
        Sort(int size...);
		Sort(const char* str);

        void InsertSort(bool ascendent = false);
        void QuickSort(bool ascendent = false);
        void BubbleSort(bool ascendent = false);
        void Print();
        int  GetElementsCount();
        int  GetElementFromIndex(int index);
};

#endif