#include "Pieza.h"
#include "Tablero.h"
#include "LogicaAjedrez.h"
#include <math.h>

Tablero * Pieza::punteroTablero=0;

Pieza::Pieza(void)
{
}


Pieza::~Pieza(void)
{
}

/**************************************************************************
 *		  Funciones comunes a las piezas			  *
 **************************************************************************/

int Pieza::getTurno ()
{
	return LogicaAjedrez::getTurno();
}
bool Pieza::mover (struct jugada & jugada)
{
	int piezaDestino = punteroTablero->leerCasilla ( jugada.destino );

	//si en destino no hay pieza, o hay pieza enemiga, Y no hay colision devuelve 1
	if ( (piezaDestino == 0 || (piezaDestino<0?-1:1 != getTurno()) ) && (comprobarColision( jugada ))) 
	{
		return 1;
	}

	//movimiento no permitido
	else return 0;
}

void Pieza::sobreescribirPosicion (struct jugada & jugadaActual)
{
	(*punteroTablero).tablero[jugadaActual.destino.x][jugadaActual.destino.y] = (*this).setTipo(getTurno());
	(*punteroTablero).tablero[jugadaActual.origen.x][jugadaActual.origen.y]=0;
}

void Pieza::escribirPosicion (Casilla & destino, int tipo)
{
	(*punteroTablero).tablero[destino.x][destino.y] = tipo*(getTurno());
}

/*
void Pieza::deshacerMovimiento (struct jugada & jugadaActual)
{
	jugada aux;
	//el origen pasa a ser el destino y viceversa
	aux.origen = jugadaActual.destino;
	aux.destino = jugadaActual.origen;

	(*punteroTablero).tablero[aux.destino.x][aux.destino.y] = (*this).setTipo(getTurno());
	(*punteroTablero).tablero[aux.origen.x][aux.origen.y]=0;
}
*/

bool Pieza::comprobarColision (struct jugada & jugadaActual)
{
	int piezaCasilla;
	Casilla aux, aux2;
	aux = jugadaActual.destino - jugadaActual.origen;

	//movimiento vertical
	if (aux.y == 0)
	{
		  for(int i = 1 ; i < abs(aux.x) ; i++)
		  {
			  aux2.x = jugadaActual.origen.x + i*(aux.x<0?-1:1); ;
			  aux2.y = jugadaActual.origen.y;
			
			  if (punteroTablero->leerCasilla (aux) != 0)
				return 0;
		  }
	}

	//movimiento horizontal
	else if (aux.x == 0)
	{
		  for(int i = 1 ; i < abs(aux.y) ; i++)
		  {
			  aux2.x = jugadaActual.origen.x; 
			  aux2.y = jugadaActual.origen.y + i*(aux.y<0?-1:1); ;
			
			  if (punteroTablero->leerCasilla (aux) != 0)
				return 0;
		  }
	}

	//Movimiento diagonal
	else if(abs(aux.x) == abs(aux.y)) 
	{
		for(int i = 1 ; i < abs(aux.y) ; i++)
		{
			 aux2.y = jugadaActual.origen.y + i*(aux.y<0?-1:1); 
			 aux2.x = jugadaActual.origen.x + i*(aux.x<0?-1:1);
			
			 if (punteroTablero->leerCasilla (aux2) != 0)
				return 0;
		}
	}

	return 1;

	/*
	aux2 = aux/aux;
	//hay que recorrer la trayectoria desde origen hasta destino
	//El destino no se evalua, ya que se evalua al mover
	while (aux != jugadaActual.destino) 
	{
		int index=1;
		aux = jugadaActual.origen + aux2*index;
		if (punteroTablero->leerCasilla (aux) != 0)
			return 0;
		index++;
	}
	return 1;
	*/
}

int Pieza::leerCasilla (Casilla & casilla)
{
	return punteroTablero->leerCasilla ( casilla );
}


