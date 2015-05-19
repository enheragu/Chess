#include "Pieza.h"


Pieza::Pieza(void)
{
	punteroTablero = &LogicaAjedrez::tableroAjedrez;
}


Pieza::~Pieza(void)
{
}

bool Pieza::mover (struct jugada * jugada)
{
	int piezaDestino = LogicaAjedrez::leerCasilla (&(*jugada).destino);

	//si en destino no hay pieza, o hay pieza enemiga, sobreescribe y coloca la propia pieza
	if (piezaDestino == 0 || piezaDestino/piezaDestino != LogicaAjedrez::getTurno()) 
	{
		sobreescribirPosicion (&(*jugada));
		return 1;
	}

	//movimiento no permitido
	else return 0;
		
}

void Pieza::sobreescribirPosicion (struct jugada * jugadaActual)
{
	(*punteroTablero).tablero[(*jugadaActual).destino.x][(*jugadaActual).destino.y] = (*this).setTipo(LogicaAjedrez::getTurno());
	(*punteroTablero).tablero[(*jugadaActual).origen.x][(*jugadaActual).origen.y]=0;
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
		piezaCasilla = LogicaAjedrez::leerCasilla (&aux);
		if (piezaCasilla != 0)
			return 0;
		index++;
	}
	return 1;
}


