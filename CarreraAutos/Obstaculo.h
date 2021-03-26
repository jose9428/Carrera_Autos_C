#pragma once
#include "Entidad.h"

class Obstaculo:public Entidad
{
private:
	bool movimiento;
public:
	Obstaculo(int x , int y);
	~Obstaculo();
	void Mostrar(Graphics^ g);
	void Mover();
	void setMovimiento(bool movimiento);
	bool getMovimiento();
	Rectangle Area();
};

Obstaculo::Obstaculo(int x , int y)
{
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 6;
	ancho = 35;
	alto = 35;
	this->movimiento = false;
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::Mostrar(Graphics^ g) {
	g->FillEllipse(Brushes::DarkGreen, x, y, ancho, alto);
}
void Obstaculo::Mover() {
	x += dx;
	y += dy;
}


bool Obstaculo::getMovimiento() {
	return this->movimiento;
}
void Obstaculo::setMovimiento(bool movimiento) {
	this->movimiento = movimiento;
}

Rectangle Obstaculo::Area() {
	return Rectangle(x, y, ancho, alto);
}