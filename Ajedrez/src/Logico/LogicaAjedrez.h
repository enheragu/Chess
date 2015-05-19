#pragma once

#include "Pieza.h"
#include "Tablero.h"

class LogicaAjedrez
{
public:
	LogicaAjedrez(void);
	~LogicaAjedrez(void);
	void dirigirPuntero (struct jugada*);
	int leerCasilla (struct casilla *);

	int getTurno();

	//¿Privadas?
	int turno; //BLANCAS o NEGRAS
	Pieza *pieza;

	Tablero tableroAjedrez;
	Peon peon;
	Torre torre;
	Caballo caballo;
	Alfil alfil;
	Rey rey;
	Dama dama;
	PeonMovido2 peonMovido2;
	ReyMovido reyMovido;
};

