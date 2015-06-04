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

class LogicaAjedrez
{
private:
	LogicaAjedrez(void);
	~LogicaAjedrez(void);
	bool dirigirPuntero (struct jugada&);
	int leerCasilla (Casilla &);

	int getTurno();

	int turno; //BLANCAS o NEGRAS
	Pieza *pieza;

	Peon peon;
	Torre torre;
	Caballo caballo;
	Alfil alfil;
	Rey rey;
	Dama dama;

public:
	Tablero tableroAjedrez;
	
	friend int Pieza::leerCasilla (Casilla &);
	friend int Pieza::getTurno();

	bool jugadaAjedrez (struct jugada &);
};

