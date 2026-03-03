#include "Compare.h"
#include <cstring>

int ComparareNume(const Student& s1, const Student& s2) {
	int result = strcmp(s1.getNume(), s2.getNume());

	if (result == 0) return 0;
	if (result > 0) return 1;
	return -1;
}

int ComparareMate(const Student& s1, const Student& s2) {
	if (s1.getNotaMate() == s2.getNotaMate()) return 0;
	if (s1.getNotaMate() > s2.getNotaMate()) return 1;
	return -1;
}

int ComparareEngleza(const Student& s1, const Student& s2) {
	if (s1.getNotaEngleza() == s2.getNotaEngleza()) return 0;
	if (s1.getNotaEngleza() > s2.getNotaEngleza()) return 1;
	return -1;
}

int ComparareIstorie(const Student& s1, const Student& s2) {
	if (s1.getNotaIstorie() == s2.getNotaIstorie()) return 0;
	if (s1.getNotaIstorie() > s2.getNotaIstorie()) return 1;
	return -1;
}

int ComparareMedie(const Student& s1, const Student& s2) {
	if (s1.getMedia() == s2.getMedia()) return 0;
	if (s1.getMedia() > s2.getMedia()) return 1;
	return -1;
}