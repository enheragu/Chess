#pragma once
#include "Grafico\GraficosAjedrez.h"
#include "Logico\Comun\Casilla.h"
#include "Logico\LogicaAjedrez.h"
#include "Grafico\OpenGL.h"
#include "Piezas.h"

class CoordinadorAjedrez
{
protected:
	enum Estado {INICIO=0, JUEGO, FIN};
	Estado estado;
	GraficosAjedrez graficosAjedrez;
	LogicaAjedrez logicaAjedrez;
	Piezas piezas;
	bool error;

public:
	CoordinadorAjedrez(void);
	~CoordinadorAjedrez(void);
	int getEstado(){return estado;}
	//void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
	void raton (Casilla &);
	void dibujaPiezas();
	void processMenuEvents(unsigned char option);
	Casilla origen, destino, jaque;
};

