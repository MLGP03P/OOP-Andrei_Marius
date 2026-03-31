#include "RangeRover.h"

double RangeRover::GetFuelCapacity() const { return 90.0; }
double RangeRover::GetFuelConsumption() const { return 12.0; }
double RangeRover::GetAverageSpeed(Weather w) const {
    if (w == Weather::Sunny) return 140.0;
    if (w == Weather::Rain) return 110.0;
    return 90.0;
}
const char* RangeRover::GetName() const { return "RangeRover"; }