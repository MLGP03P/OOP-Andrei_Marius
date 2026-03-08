#include <iostream>
#include "Canvas.h"

int main() {
	Canvas canvas(60, 25);

	canvas.DrawRect(0, 0, 59, 24, '#');

	canvas.FillRect(5, 5, 20, 10, '@');

	canvas.DrawLine(2, 2, 40, 20, '*');

	canvas.DrawCircle(40, 7, 5, 'O');

	canvas.FillCircle(40, 18, 4, '.');

	canvas.SetPoint(30, 12, 'X');
	canvas.SetPoint(31, 12, 'X');
	canvas.SetPoint(30, 13, 'X');
	canvas.SetPoint(31, 13, 'X');

	std::cout << "--- Canvas Render ---" << std::endl;
	canvas.Print();

	std::cout << "\n--- Canvas Cleared ---" << std::endl;
	canvas.Clear();
	canvas.SetPoint(10, 2, 'C');
	canvas.SetPoint(11, 2, 'L');
	canvas.SetPoint(12, 2, 'E');
	canvas.SetPoint(13, 2, 'A');
	canvas.SetPoint(14, 2, 'R');
	canvas.Print();

	return 0;
}