#include "Pieza.h"
#include "Tablero.h"

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
class LogicaAjedrez;

bool Pieza::mover (struct jugada & jugada)
{
	int piezaDestino = punteroTablero->leerCasilla ( jugada.destino );

	//si en destino no hay pieza, o hay pieza enemiga, Y no hay colision sobreescribe y coloca la propia pieza
	if ((piezaDestino == 0 || ((piezaDestino/piezaDestino) != getTurno())) && (comprobarColision( jugada ))) 
	{
		sobreescribirPosicion ( jugada );
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

bool Pieza::comprobarColision (struct jugada & jugadaActual)
{
	int piezaCasilla;
	Casilla aux, aux2;
	aux = jugadaActual.destino - jugadaActual.origen;
	aux2 = aux.unitario();
	//hay que recorrer la trayectoria desde origen hasta destino
	//El destino no se evalua, ya que se evalua al mover
	while (aux != jugadaActual.destino) 
	{
		int index=1;
		aux = jugadaActual.origen + aux2*index;
		piezaCasilla = punteroTablero->leerCasilla (aux);
		if (piezaCasilla != 0)
			return 0;
		index++;
	}
	return 1;
}

int Pieza::leerCasilla (Casilla & casilla)
{
	return punteroTablero->leerCasilla ( casilla );
}
