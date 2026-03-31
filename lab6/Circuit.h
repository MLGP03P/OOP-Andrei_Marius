#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit {
private:
	Car* concurenti[100];
	int nrConcurenti;

	double lungimeCircuit;

	Weather vreme;

	Car* finished[100];
	double timpi[100];
	int nrFinished;

	Car* DNF[100];
	int nrDNF;

public:
	Circuit();
	~Circuit();

	void SetLength(double length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);

	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};
