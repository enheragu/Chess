#include "LogicaAjedrez.h"
#include <math.h>


LogicaAjedrez::LogicaAjedrez(void)
{
	pieza = 0;
	turno = BLANCAS;
	Pieza.punteroTablero = &tableroAjedrez;
}


LogicaAjedrez::~LogicaAjedrez(void)
{
}

void LogicaAjedrez::dirigirPuntero (struct jugada* jugadaActual)
{
	int piezaEnCasilla = abs(leerCasilla (&(*jugadaActual).origen));

	switch (piezaEnCasilla)
	{
		case PEON_SIN_MOVER: 
			pieza = &peon;
			//Clase Peon (peon no movido) hereda de PeonMovido2, que a su vez hereda de pieza
			break;
		case PEON_MOVIDO: 
			pieza = &peonMovido2;
			break;
		case CABALLO: 
			pieza = &caballo;
			break;
		case ALFIL: 
			pieza = &alfil;
			break;
		case TORRE_NO_MOVIDA: 
			pieza = &torre;
			break;
		case TORRE_MOVIDA: 
			pieza = &torre;
			break;
		case DAMA: 
			pieza = &dama;
			break;
		case REY_NO_MOVIDO: 
			pieza = &rey;
			//Clase Rey (rey no movido) hereda de ReyMovido, que a su vez hereda de pieza
			break;
		case REY_MOVIDO: 
			pieza = &reyMovido;
			break;
		case C_VACIA: 
			pieza = 0;
			//devuelve mensaje de error "casilla vacia" por pantalla
			break;
	}
}

int LogicaAjedrez::leerCasilla (struct Casilla * casilla)
{
	return tableroAjedrez.tablero[(*casilla).x][(*casilla).y];
}

int LogicaAjedrez::getTurno () 
{
	return turno;
}