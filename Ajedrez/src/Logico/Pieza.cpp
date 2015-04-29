#include "Pieza.h"
#include "Tablero.h"


int numJugadasBlancas = 0;
int numJugadasNegras = 0;

Pieza::Pieza(int t, int x, int y)
{
	casillaActual.x = x;
	casillaActual.y = y;
	tipo = t;
}


Pieza::~Pieza(void)
{
}

void Pieza::escribirPosicion(int id)
{
	Tablero.tablero[casillaActual.x][casillaActual.y] = id;
}
