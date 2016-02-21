#include "LogicaAjedrez.h"
#include <math.h>

/**************************************************************************
 *			  Constructor/Destructor			  *
 **************************************************************************/
LogicaAjedrez::LogicaAjedrez(void)
{
	pieza = 0;
	turno = BLANCAS;
	Pieza::punteroTablero = &tableroAjedrez;
	jaqueRey = false;
}

int LogicaAjedrez::turno=1;

LogicaAjedrez::~LogicaAjedrez(void)
{
}


/**************************************************************************
 *		Interfaz de la lógica del ajedrez			  *
 **************************************************************************/

/* En caso de movimiento correcto deovolverá un 1, si el movimiento no está permitido devolverá un 0 */

bool LogicaAjedrez::jugadaAjedrez (struct jugada &jugadaActual)
{
	bool error = false;
	error = escribirMovimiento ( jugadaActual );

	/*
	if (error == true && jaque() != (-100,-100) )
	{
		pieza->deshacerMovimiento ( jugadaActual );
		jaqueRey = true;
	}
	*/

	if (error == true && turno == BLANCAS)
		turno = NEGRAS;
	else if (error == true && turno == NEGRAS)
		turno = BLANCAS;
	return error;
}

/*
--------------		Sintaxyx Summary		--------------		

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
	if (pieza != 0 && (leerCasilla (jugadaActual.origen)<0?-1:1 == turno) )
	{
		if (pieza->mover(jugadaActual)) return 1;
		else return 0;
		// devuelve 0 si hay error en el movimiento
	}
}

/*
Casilla LogicaAjedrez::jaque ()
{
	Casilla posRey = rey.buscarRey();

	jugada jugadaAtaque;
	jugadaAtaque.destino = posRey;

	for (int i=0; i<8; i++)
		for (int j=0; j<8; j++)
		{
			jugadaAtaque.origen = (i,j);
			if ( dirigirPuntero (jugadaAtaque) ) return posRey;
		}
	return (-100,-100);
}
*/


bool LogicaAjedrez::escribirMovimiento (struct jugada &jugadaActual)
{
	if ( dirigirPuntero (jugadaActual) )
	{
		pieza->sobreescribirPosicion(jugadaActual);
		return 1;
	}
	else return 0;
}

int LogicaAjedrez::leerCasilla (Casilla & casilla)
{
	return tableroAjedrez.tablero[casilla.x][casilla.y];
}

int LogicaAjedrez::getTurno () 
{
	return turno;
}

void LogicaAjedrez::reset()
{
	tableroAjedrez.reset();
}
