#pragma once

#include "Tablero.h"

enum jugador {BLANCAS=0, NEGRAS};
enum pieza {C_VACIA=0, PEON_SIN_MOVER, PEON_MOVIDO, CABALLO, ALFIL, TORRE_NO_MOVIDA, TORRE_MOVIDA, DAMA, REY_NO_MOVIDO, REY_MOVIDO};

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
protected:
	int tipo;
	casilla casillaActual;
	Tablero* s;

	static int numJugadas;

public:
	
	Pieza(int t, int x, int y);
	~Pieza(void);

	jugada* generador();
	void escribirPosicion(int id);
};

