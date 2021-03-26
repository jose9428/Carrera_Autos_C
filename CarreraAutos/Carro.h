#pragma once
#include "Entidad.h"

class Carro:public Entidad
{
private:
	int puesto;
	int nroCarro;
public:
	Carro();
	Carro(int x , int y , int tipo, int nroCarro);
	~Carro();
	void Mostrar(Graphics^ g, Bitmap^ bmp);
	void Mover(Graphics^ g);
	void setX(int x);
	void DisminuirVelocidad();
	Rectangle Area();

	void setPuesto(int puesto);
	int getPuesto();
	void setNroCarro(int nroCarro);
	int getNroCarro();
};

Carro::Carro()
{
	Random r;
	x = 250;
	y = 0;
	dy = 0;
	ancho = alto = 0;
	indiceX = indiceY = 0;

	Thread::Sleep(15);
	dx = -1 * r.Next(1, 4) * 5;
	puesto = 0;
}

Carro::Carro(int x, int y , int tipo , int nroCarro) {
	this->x = x;
	this->y = y;
	this->nroCarro = nroCarro;

	Random r;
	dy = 0;
	ancho = alto = 0;
	indiceX = tipo;
	indiceY = 0;
	puesto = 0;

	Thread::Sleep(20);
	dx = -1 * r.Next(1, 4) * 5;
	if (dx == 0) {
		dx = -1;
	}
}

Carro::~Carro()
{
}

void Carro::Mostrar(Graphics^ g, Bitmap^ bmp) {
	ancho = bmp->Width / 7;
	alto = bmp->Height / 7;

	Rectangle porcion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);


}
void Carro::Mover(Graphics^ g) {
//	int alturaPantalla = g->VisibleClipBounds.Bottom;
	// int bajoPantalla = g->VisibleClipBounds.Right;

	x += dx;
}

void Carro::setX(int x) {
	this->x = x;
}

void Carro::DisminuirVelocidad() {
	this->dx = this->dx + 5;

	if (this->dx >= 0) {
		this->dx = -5;
	}
}

Rectangle Carro::Area() {
	return Rectangle(x, y, ancho, alto);
}

void Carro::setPuesto(int puesto) {
	this->puesto = puesto;
}
int Carro::getPuesto() {
	return this->puesto;
}

void Carro::setNroCarro(int nroCarro) {
	this->nroCarro = nroCarro;
}
int Carro::getNroCarro() {
	return this->nroCarro;
}