#pragma once
using namespace System::Drawing;
using namespace System::Threading;
using namespace System;
using namespace std;

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int indiceX, indiceY;
public:
	Entidad();
	~Entidad();

	int getX();
	int getY();
	int getDx();
	int getDy();
	int getAncho();
	int getAlto();
	int getIndiceX();
	int getIndiceY();

	void setX(int x);
	void setY(int y);
	void setDx(int dx);
	void setDy(int dy);
	void setAncho(int ancho);
	void setAlto(int alto);
	void setIndiceX(int indiceX);
	void setIndiceY(int indiceY);

	virtual void Mostrar(Graphics^ g, Bitmap^ bmp);
	virtual void Mover(Graphics^ g);
	
};

Entidad::Entidad()
{
}

Entidad::~Entidad()
{
}

void Entidad::setX(int x) { this->x = x; };
void Entidad::setY(int y) { this->y = y; };
void Entidad::setDx(int dx) { this->dx = dx; };
void Entidad::setDy(int dy) { this->dy = dy; };
void Entidad::setAncho(int ancho) { this->ancho = ancho; };
void Entidad::setAlto(int alto) { this->alto = alto; };
void Entidad::setIndiceX(int indiceX) { this->indiceX = indiceX; };
void Entidad::setIndiceY(int indiceY) { this->indiceY = indiceY; };

int Entidad::getX() { return this->x; };
int Entidad::getY() { return this->y; };
int Entidad::getDx() { return this->dx; };
int Entidad::getDy() { return this->dy; };
int Entidad::getAncho() { return this->ancho; };
int Entidad::getAlto() { return this->alto; };

int Entidad::getIndiceX() { return this->indiceX; };
int Entidad::getIndiceY() { return this->indiceY; };

void Entidad::Mostrar(Graphics^ g, Bitmap^ bmp) {};
void Entidad::Mover(Graphics^ g) {};



