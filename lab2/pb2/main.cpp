#include "Student.h"
#include "Compare.h"
#include <iostream>

void PrintRezultat(const char* criteriu, int result, const Student& s1, const Student& s2) {
	std::cout << "Comparare dupa " << criteriu << ": ";
	if (result == 0) std::cout << s1.getNume() << " si " << s2.getNume() << " au nota egala.\n";
	else if (result == 1) std::cout << s1.getNume() << " are nota mai mare.\n";
	else std::cout << s2.getNume() << " are nota mai mare.\n";
}

int main() {
	Student student1;
	student1.setNume("Maria");
	student1.setNotaMate(9.5f);
	student1.setNotaEngleza(8.0f);
	student1.setNotaIstorie(7.5f);

	Student student2;
	student2.setNume("Marius");
	student2.setNotaMate(8.5f);
	student2.setNotaEngleza(10.0f);
	student2.setNotaIstorie(7.0f);


	std::cout << student1.getNume() << " are media: " << student1.getMedia() << "\n";
	std::cout << student2.getNume() << " are media: " << student2.getMedia() << "\n";

	PrintRezultat("nume", ComparareNume(student1, student2), student1, student2);
	PrintRezultat("nota la mate", ComparareMate(student1, student2), student1, student2);
	PrintRezultat("nota la engleza", ComparareEngleza(student1, student2), student1, student2);
	PrintRezultat("nota la istorie", ComparareIstorie(student1, student2), student1, student2);
	PrintRezultat("media", ComparareMedie(student1, student2), student1, student2);

	return 0;
}
