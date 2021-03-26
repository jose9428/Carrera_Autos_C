#pragma once
#include "Carro.h"
#include "Obstaculo.h"

class Juego
{
private:
	Carro** carros;
	Obstaculo** obstaculos;
	int cantCarros;
	int cantObstaculos;
	int llegada;
public:
	Juego();
	~Juego();

	void AgregarCarros(int num, Graphics^ g, Bitmap^ bmp);
	void AnimacionCarros(Graphics^ g, Bitmap^ bmp);
	void AgregarObstaculos(int num);
	void AnimacionObstaculos(Graphics^ g);
	void EliminarObstaculo(int indice);
	void MoverObstaculo();
	void Colision();
	bool LlegoCarrosMeta();
	void OrdenarPuestos();

	int getCantCarros();
	Carro* ObtenerCarro(int indice);
};

Juego::Juego()
{
	llegada = 1;
	cantCarros = cantObstaculos = 0;
	carros = new Carro*[cantCarros];
	obstaculos = new Obstaculo * [cantObstaculos];

	AgregarObstaculos(10);
}

Juego::~Juego()
{
}

void Juego::AgregarCarros(int num , Graphics ^g , Bitmap ^bmp) {
	int x , y;

	for (int i = 0; i < num;i++) {
		Carro** aux = new Carro*[cantCarros + 1];

		for (int j = 0; j < cantCarros;j++) {
			aux[j] = carros[j];
		}

		x =  (int)g->VisibleClipBounds.Right - (bmp->Width / 6);
		y = (i + 2)*(bmp->Height / 7);

		aux[cantCarros] = new Carro(x, y , i , (i+1));

		if (carros != nullptr) {
			delete carros;
		}

		carros = aux;
		cantCarros++;
	}
}


void Juego::AgregarObstaculos(int num) {

	for (int i = 0; i < num; i++) {
		Obstaculo** aux = new Obstaculo * [cantObstaculos + 1];

		for (int j = 0; j < cantObstaculos; j++) {
			aux[j] = obstaculos[j];
		}

		aux[cantObstaculos] = new Obstaculo( 80 * (i  + 1), 10);

		if (obstaculos != nullptr) {
			delete obstaculos;
		}

		obstaculos = aux;
		cantObstaculos++;
	}
}

void Juego::AnimacionCarros(Graphics^ g, Bitmap^ bmp) {
	for (int i = 0; i < cantCarros;i++) {
		Carro* objCarro = carros[i];
		objCarro->Mover(g);
		objCarro->Mostrar(g, bmp);
		
	}
}

void Juego::AnimacionObstaculos(Graphics^ g) {
	for (int i = 0; i < cantObstaculos; i++) {
		obstaculos[i]->Mostrar(g);
		if (obstaculos[i]->getMovimiento()) {
			obstaculos[i]->Mover();
		}
	}
}

void Juego::MoverObstaculo() {
	for (int i = cantObstaculos-1; i >=0; i--) {
		if (!obstaculos[i]->getMovimiento()) {
			obstaculos[i]->setMovimiento(true);
			break;
		}
	}
}

void Juego::Colision(){
	inicio:
	for (int i = 0; i < cantObstaculos;i++) {
		for (int j = 0; j < cantCarros;j++) {
			if (carros[j]->Area().IntersectsWith(obstaculos[i]->Area())) {
				// Hay colision
				carros[j]->DisminuirVelocidad(); 
				EliminarObstaculo(i);
				goto inicio;
			}
		}
	}
}

void Juego::EliminarObstaculo(int indice) {

	Obstaculo** aux = new Obstaculo * [cantObstaculos - 1];

	delete obstaculos[indice];

	for (int i = 0; i < indice; i++) {
		aux[i] = obstaculos[i];
	}

	for (int i = indice; i < cantObstaculos-1; i++) {
		aux[i] = obstaculos[i+1];
	}

	if (obstaculos != nullptr) {
		delete obstaculos;
	}

	obstaculos = aux;

	cantObstaculos--;
}

bool Juego::LlegoCarrosMeta() {
	int llegoMeta = 0;
	for (int i = 0; i < cantCarros;i++) {
		Carro* obj = carros[i];

		if (obj->getX() <= 0 && obj->getPuesto() == 0) {
			carros[i]->setPuesto(llegada);
			llegada++;
		}

		if (obj->getPuesto() > 0) {
			llegoMeta++;
		}
	}

	if (llegoMeta == cantCarros) {
		return true;
	}
	else {
		return false;
	}
}

int Juego::getCantCarros() {
	return this->cantCarros;
}

Carro* Juego::ObtenerCarro(int indice) {
	return carros[indice];
}

void Juego::OrdenarPuestos() {

	for (int i = 0; i < cantCarros - 1; i++) {
		for (int j = i + 1; j < cantCarros; j++) {
			if (carros[i]->getPuesto() > carros[j]->getPuesto()) {
				Carro *aux = carros[i];
				carros[i] = carros[j];
				carros[j] = aux;
			}
		}
	}
}
