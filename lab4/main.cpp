
#include <iostream>
#include <ctime>
#include "Sort.h"

int main() {
    srand((unsigned int)time(nullptr));

    std::cout << "BubbleSort Crescator:\n";
    Sort s1("1,67,2,69,420,4");
    s1.Print();
    s1.BubbleSort(true);
    s1.Print();
    std::cout << "Nr elemente: " << s1.GetElementsCount() << "\n\n";

    std::cout << "InsertSort Descrescator:\n";
    Sort s2({ 45, 12, 89, 2, 33 });
    s2.Print();
    s2.InsertSort(false);
    s2.Print();
    std::cout << "Elementul cu index 2: " << s2.GetElementFromIndex(2) << "\n\n";

    std::cout << "QuickSort Crescator:\n";
    int arr[] = { 100, 50, 300, 20, 400 };
    Sort s3(arr, 5);
    s3.Print();
    s3.QuickSort(true);
    s3.Print();
    std::cout << "\n";

    std::cout << "BubbleSort Descrescator:\n";
    // 6 este numarul de elemente, urmat de cele 6 numere efective
    Sort s4(6, 15, 8, 99, 42, 7, 21);
    s4.Print();
    s4.BubbleSort(false);
    s4.Print();
    std::cout << "\n";

    std::cout << "QuickSort Descrescator:\n";
    Sort s5("10,40,100,5,70");
    s5.Print();
    s5.QuickSort(false);
    s5.Print();

    return 0;
}