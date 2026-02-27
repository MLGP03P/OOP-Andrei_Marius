#include "NumberList.h"
#include <iostream>
#include <algorithm>

void NumberList::Init() {
	count = 0;
}

bool NumberList::Add(int x) {
	if (count >= 10) {
		return false;
	}

	numbers[count] = x;
	count++;

	return true;
}

void NumberList::Sort() {
	bool ok;
	do
	{
		ok = true;
		for (int i = 0; i < count - 1; i++)
			if (numbers[i] > numbers[i + 1])
			{
				int aux = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = aux;
				ok = false;
			}
	} while (!ok);
}

void NumberList::Print() {
	if (count == 0) {
		std::cout << "Lista e goala" << std::endl;
		return;
	}

	for (int i = 0; i < count; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}