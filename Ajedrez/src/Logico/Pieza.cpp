#include "Pieza.h"


Pieza::Pieza(void)
{
}


Pieza::~Pieza(void)
{
}

bool Pieza::mover (struct jugada * jugada)
{
	int piezaDestino = leerCasilla (&(*jugada).destino);

	//si en destino no hay pieza, o hay pieza enemiga, Y no hay colision sobreescribe y coloca la propia pieza
	if ((piezaDestino == 0 || ((piezaDestino/piezaDestino) != getTurno())) && (comprobarColision(&(*jugada)))) 
	{
		sobreescribirPosicion (&(*jugada));
		return 1;
	}

	//movimiento no permitido
	else return 0;
		
}

void Pieza::sobreescribirPosicion (struct jugada * jugadaActual)
{
	(*punteroTablero).tablero[(*jugadaActual).destino.x][(*jugadaActual).destino.y] = (*this).setTipo(getTurno());
	(*punteroTablero).tablero[(*jugadaActual).origen.x][(*jugadaActual).origen.y]=0;

	/****************************************************************************************
											ERROR!
	*****************************************************************************************

	en [(*jugadaActual) señala el primer parentesis diciendo que la expresion debe tener un tipo integral o enum

	*/
}

bool Pieza::comprobarColision (struct jugada * jugadaActual)
{
	int piezaCasilla;
	Casilla aux, aux2;
	aux = (*jugadaActual).destino - (*jugadaActual).origen;
	aux2 = aux.unitario();
	//hay que recorrer la trayectoria desde origen hasta destino
	//El destino no se evalua, ya que se evalua al mover
	while (aux != (*jugadaActual).destino) 
	{
		int index=1;
		aux = (*jugadaActual).origen + aux2*index;
		piezaCasilla = leerCasilla (&aux);
		if (piezaCasilla != 0)
			return 0;
		index++;
	}
	return 1;
}


