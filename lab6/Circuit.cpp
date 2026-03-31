#include <iostream>
#include "Circuit.h"

Circuit::Circuit() {
	nrConcurenti = 0;
	lungimeCircuit = 0;
	vreme = Weather::Sunny;
	nrFinished = 0;
	nrDNF = 0;
}

Circuit::~Circuit() {
	for (int i = 0; i < nrConcurenti; i++) {
		delete concurenti[i];
	}
}

void Circuit::SetLength(double length) {
	lungimeCircuit = length;
}

void Circuit::SetWeather(Weather weather) {
	vreme = weather;
}

void Circuit::AddCar(Car* car) {
	if (nrConcurenti < 100) {
		concurenti[nrConcurenti++] = car;
	}
}

void Circuit::Race() {
	nrFinished = 0;
	nrDNF = 0;

	for (int i = 0; i < nrConcurenti; i++) {
		Car* masinaCurenta = concurenti[i];

		double necesarCombustibil = (masinaCurenta->GetFuelConsumption() * lungimeCircuit) / 100.0;

		if (necesarCombustibil <= masinaCurenta->GetFuelCapacity()) {
			finished[nrFinished] = masinaCurenta;
			timpi[nrFinished] = lungimeCircuit / masinaCurenta->GetAverageSpeed(vreme);
			nrFinished++;
		}
		else {
			DNF[nrDNF++] = masinaCurenta;
		}
	}

	for (int i = 0; i < nrFinished - 1; i++) {
		for (int j = i + 1; j < nrFinished; j++) {
			if (timpi[i] > timpi[j]) {
				double aux = timpi[i];
				timpi[i] = timpi[j];
				timpi[j] = aux;

				Car* masinaTemp = finished[i];
				finished[i] = finished[j];
				finished[j] = masinaTemp;
			}
		}
	}
}

void Circuit::ShowFinalRanks() {
	std::cout << "\n=== CLASAMENT FINAL ===" << std::endl;
	for (int i = 0; i < nrFinished; i++) {
		std::cout << i + 1 << ". " << finished[i]->GetName()
			<< " -> Timp: " << timpi[i] << " ore" << std::endl;
	}
}

void Circuit::ShowWhoDidNotFinish() {
	std::cout << "\n------DNF (Did Not Finish - FARA COMBUSTIBIL)------" << std::endl;
	if (nrDNF == 0) {
		std::cout << "Au terminat toti concurentii" << std::endl;
		return;
	}

	for (int i = 0; i < nrDNF; i++) {
		std::cout << "- " <<DNF[i]->GetName() << std::endl;
	}
	std::cout << std::endl;
}