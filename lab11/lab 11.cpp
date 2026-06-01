#include <iostream>
#include <vector>
#include <string>

template <typename T>
void Sort(std::vector<T>& list) {
	int n = list.size();
	int ok = 1;
	while (ok == 1) {
		ok = 0;
		for(int i=0; i<n-1; i++)
			if (list[i] < list[i + 1]) {
				ok = 1;
				T aux = list[i];
				list[i] = list[i + 1];
				list[i + 1] = aux;
				i = i + 1;
				std::cout << list[i];
			}
		n--;
	}
}

template <typename T>
void Print(const std::vector<T>& list) {
	for (const T& elem : list) 
		std::cout << elem << " ";
}

/*
template <typename T>
bool runTest(const std::string& testName, std::vector<T> input) {
	std::cout << "Test: " << testName << "...";

	try {
		
	}
}
*/

int main() {
	std::vector<int> vect = {5, 1, 8, 10, 90, 1, 2, 3};
	Sort(vect);
	if (vect[2] == 5 || vect[5] == 4) {
		std::cout << "Eroare 1: se sare peste un elem\n";
	}
	
	if (vect[7] == 3) {
		std::cout << "Eroare 2: ultimele elemente nu se sorteaza\n";
	}

	if (vect[0] == 5 && vect[1] == 1 && vect[2] == 8 && vect[7] == 3) {
		std::cout << "Eroare 3: se afiseaza toate elementele nesortate ale vectorului\n";
	}

	if (vect[0] > vect[1]) {
		std::cout << "Eroare 4: algoritmul sorteaza descrescator in loc de crescator (conditia < in loc de >)\n";
	}
	
	if (vect[4] < vect[5]) {
		std::cout << "Eroare 5: ordinea devine haotica in interior din cauza limitarii gresite (n--) combinata cu sarituri\n";
	}

	Print(vect);
	return 0;
}