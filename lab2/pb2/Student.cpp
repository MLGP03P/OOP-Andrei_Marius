#include "Student.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

Student::Student() {
	strncpy(nume, "Necunoscut", sizeof(nume) - 1 );
	nume[sizeof(nume) - 1] = '\0';

	nota_mate = 1.0f;
	nota_engleza = 1.0f;
	nota_istorie = 1.0f;
}

void Student::setNume(const char* numeStudent){
	strncpy(nume, numeStudent, sizeof(nume) - 1);
	nume[sizeof(nume) - 1] = '\0';
}

const char* Student::getNume() const {
	return nume;
}

void Student::setNotaMate(float nota) {
	if (nota >= 1.0f && nota <= 10.0f) {
		nota_mate = nota;
	}
}

float Student::getNotaMate()const {
	return nota_mate;
}

void Student::setNotaEngleza(float nota) {
	if (nota >= 1.0f && nota <= 10.0f) {
		nota_engleza = nota;
	}
}

float Student::getNotaEngleza()const {
	return nota_engleza;
}

void Student::setNotaIstorie(float nota) {
	if (nota >= 1.0f && nota <= 10.0f) {
		nota_istorie = nota;
	}
}

float Student::getNotaIstorie() const {
	return nota_istorie;
}

float Student::getMedia() const {
	return (nota_mate + nota_engleza + nota_istorie) / 3.0f;
}