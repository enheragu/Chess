#pragma once

#include "Pieza.h"
#include "Tablero.h"
#include "Tablero.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Dama.h"
#include "Peon.h"
#include "Rey.h"
#include "Torre.h"
#include "PeonMovido2.h"
#include "ReyMovido.h"

class LogicaAjedrez
{
public:
	LogicaAjedrez(void);
	~LogicaAjedrez(void);
	void dirigirPuntero (struct jugada*);
	int leerCasilla (struct Casilla *);

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

	friend int Pieza::leerCasilla(struct Casilla *);
	friend int Pieza::getTurno();
};

