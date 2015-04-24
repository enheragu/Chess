#pragma once

#include "Situacion.h"

enum jugador{A, B};
enum pieza {CABALLO=0, REINA, REY, TORRE, PEON, ALFIL};
struct casilla{
	int x;
	int y;
};
 struct jugada{
	 casilla origen;
	 casilla destino;
 };


class Pieza
{
	int tipo;
	int casilla;
	Situacion* s;
public:

	Pieza(void);
	~Pieza(void);

	jugada* generador();
};

