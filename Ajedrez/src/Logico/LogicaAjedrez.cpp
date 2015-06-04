#include "LogicaAjedrez.h"
#include <math.h>

/**************************************************************************
 *			  Constructor/Destructor			  *
 **************************************************************************/
LogicaAjedrez::LogicaAjedrez(void)
{
	pieza = 0;
	turno = BLANCAS;
	Pieza.punteroTablero = &tableroAjedrez;
}


LogicaAjedrez::~LogicaAjedrez(void)
{
}


/**************************************************************************
 *		Interfaz de la lógica del ajedrez			  *
 **************************************************************************/

/* En caso de movimiento correcto deovolverá un 1, si el movimiento no está permitido devolverá un 0 */
bool LogicaAjedrez::jugadaAjedrez (struct jugada &jugadaActual)
{
	bool error;
	error = dirigirPuntero ( jugadaActual );

	if (error == 1 && turno == BLANCAS)
		turno == NEGRAS;
	else if (error == 1 && turno == NEGRAS)
		turno == BLANCAS;
	return error;
}

/*
struct needed by the function:
	 struct jugada{
		 Casilla origen;
		 Casilla destino; 
	 };
	
Class "Casilla" used in the structure 
	class Casilla
	{
	public:
		int x;
		int y;
		
		// --- operators ---
	};

*/


/**************************************************************************
 *			Funciones lógica ajedrez			  *
 **************************************************************************/
bool LogicaAjedrez::dirigirPuntero (struct jugada & jugadaActual)
{
	int piezaEnCasilla = abs(leerCasilla (jugadaActual.origen));

	switch (piezaEnCasilla)
	{
		case PEON_SIN_MOVER: 
			pieza = &peon;
			break;
		case PEON_MOVIDO: 
			pieza = &peon;
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
			break;
		case REY_MOVIDO: 
			pieza = &rey;
			break;
		case C_VACIA: 
			pieza = 0;
			//devuelve mensaje de error "casilla vacia" por pantalla
			break;
	}
	if (pieza != 0)
		if (pieza->mover(jugadaActual)) return 0; 
		// devuelve 0 si hay error en el movimiento
}

int LogicaAjedrez::leerCasilla (Casilla & casilla)
{
	return tableroAjedrez.tablero[casilla.x][casilla.y];
}

int LogicaAjedrez::getTurno () 
{
	return turno;
}
