#include "Pieza.h"
#include <math.h>

int numJugadasBlancas = 0;
int numJugadasNegras = 0;

Pieza::Pieza(int t, int x, int y, int color)
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

void Pieza::moverFicha (struct jugada* jugada)
{
	int pieza;
	pieza = abs(leerCasilla (jugada));

	switch (pieza)
	{
		case PEON_SIN_MOVER: 
			Peon::muevePeon(jugada);
			break;
		case PEON_MOVIDO: 
			Peon::muevePeon(jugada);
			break;
		case CABALLO: 
			Caballo::mueveCaballo(jugada);
			break;
		case ALFIL: 
			Alfil::mueveAlfil(jugada);
			break;
		case TORRE_NO_MOVIDA: 
			Torre::mueveTorre(jugada);
			break;
		case TORRE_MOVIDA: 
			Torre::mueveTorre(jugada);
			break;
		case DAMA: 
			Dama::mueveDama(jugada);
			break;
		case REY_NO_MOVIDO: 
			Rey::mueveRey(jugada);
			break;
		case REY_MOVIDO: 
			Rey::mueveRey(jugada);
			break;
		case C_VACIA: 
			//devuelve mensaje de error por pantalla
			break;
		case C_PROHIBIDA: 
			//devuelve mensaje de error por pantalla
			break;
	}
}
