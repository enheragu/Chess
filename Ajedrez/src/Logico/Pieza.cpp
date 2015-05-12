#include "Pieza.h"
#include <math.h>

int numJugadasBlancas = 0;
int numJugadasNegras = 0;

Pieza::Pieza(int x, int y, int t, int color)
{
	jugadaPieza.origen.x = x;
	jugadaPieza.origen.y = y;
	tipo = t*color;
}


Pieza::~Pieza(void)
{
}

void Pieza::escribirPosicion(struct jugada* jugadaActual)
{
	(*punteroTablero).tablero[(*jugadaActual).destino.x][(*jugadaActual).destino.y] = tipo;
	(*punteroTablero).tablero[(*jugadaActual).origen.x][(*jugadaActual).origen.y]=0;
	
	//se copia el destino a la casilla origen y la casilla destino se resetea
	(*jugadaActual).origen.x = (*jugadaActual).destino.x;
	(*jugadaActual).origen.y = (*jugadaActual).destino.y;
	(*jugadaActual).destino.x = (*jugadaActual).destino.y = 0;
}

int Pieza::leerCasilla (struct jugada* jugada)
{
	return (*punteroTablero).tablero[(*jugada).destino.x][(*jugada).destino.y];
}

void Pieza::pedirDestino (int x, int y) 
{

}

void Pieza::moverPieza (struct jugada* jugada)
{
	int pieza;
	pieza = abs(leerCasilla (jugada));

	switch (pieza)
	{
		case PEON_SIN_MOVER: 
			Peon.moverPieza(jugada);
			break;
		case PEON_MOVIDO: 
			Peon.moverPieza(jugada);
			break;
		case CABALLO: 
			Caballo.moverPieza(jugada);
			break;
		case ALFIL: 
			Alfil.moverPieza(jugada);
			break;
		case TORRE_NO_MOVIDA: 
			Torre.moverPieza(jugada);
			break;
		case TORRE_MOVIDA: 
			Torre.moverPieza(jugada);
			break;
		case DAMA: 
			Dama.moverPieza(jugada);
			break;
		case REY_NO_MOVIDO: 
			Rey.moverPieza(jugada);
			break;
		case REY_MOVIDO: 
			Rey.moverPieza(jugada);
			break;
		case C_VACIA: 
			//devuelve mensaje de error por pantalla
			break;
		case C_PROHIBIDA: 
			//devuelve mensaje de error por pantalla
			break;
	}
}

bool Pieza::evaluarMovimiento (struct jugada * jugada)
{
	if (leerCasilla (jugada)==(-color)||leerCasilla (jugada)==0)
		return true;
	else if (leerCasilla (jugada)==color||leerCasilla (jugada)==255)
		return false;
}
