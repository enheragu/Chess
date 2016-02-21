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
class Pieza;
class LogicaAjedrez
{
private:
	bool dirigirPuntero (struct jugada&);
	static int turno; //BLANCAS o NEGRAS
	Pieza *pieza;

	Peon peon;
	Torre torre;
	Caballo caballo;
	Alfil alfil;
	Rey rey;
	Dama dama;
	
	bool escribirMovimiento (struct jugada &);
public:
	LogicaAjedrez(void);
	~LogicaAjedrez(void);
	Tablero tableroAjedrez;
	void reset();
	int leerCasilla (Casilla &);

	bool jugadaAjedrez (struct jugada &);
	Casilla jaque ();
	static int getTurno();
	bool jaqueRey;
};

