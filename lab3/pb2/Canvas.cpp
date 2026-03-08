#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height){
	this->width = width;
	this->height = height;

	matrix = new char* [height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new char[width];
	}
	Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	int d = 3 - 2 * ray;
	int _x = 0;
	int _y = ray;

	while (_x <= _y) {
		SetPoint(x + _x, y + _y, ch);
		SetPoint(x - _x, y + _y, ch);
		SetPoint(x + _x, y - _y, ch);
		SetPoint(x - _x, y - _y, ch);
		SetPoint(x + _y, y + _x, ch);
		SetPoint(x - _y, y + _x, ch);
		SetPoint(x + _y, y - _x, ch);
		SetPoint(x - _y, y - _x, ch);
		if (d < 0) {
			d = d + 4 * _x + 6;
		}
		else {
			d = d + 4 * (_x - _y) + 10;
			_y--;
		}
		_x++;
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch){
	for(int i = -ray; i <= ray; i++) {
		for(int j = -ray; j <= ray; j++) {
			if (i * i + j * j <= ray * ray) {
				SetPoint(x + i, y + j, ch);
			}
		}
	}

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch){
	DrawLine(left, top, right, top, ch); 
	DrawLine(right, top, right, bottom, ch);
	DrawLine(right, bottom, left, bottom, ch);
	DrawLine(left, bottom, left, top, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch){
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			SetPoint(j, i, ch);
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch){
	if (x >= 0 && x < width && y >= 0 && y < height) {
		matrix[y][x] = ch;
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch){
	int dx = std::abs(x2 - x1);
	int sx = x1 < x2 ? 1 : -1;
	int dy = -std::abs(y2 - y1);
	int sy = y1 < y2 ? 1 : -1;
	int err = dx + dy;

	while (true) {
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) break;

		int err2 = 2 * err;
		if (err2 >= dy) {
			err += dy;
			x1 += sx;
		}
		if (err2 <= dx) {
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::Print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << matrix[i][j];
		}
	}
}

void Canvas::Clear() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = ' ';
		}
	}
}