#include "Dama.h"
#include <math.h>


Dama::Dama(void)
{
}


Dama::~Dama(void)
{
}

int Dama::setTipo (int turno)
{
	return DAMA*turno;
}

bool Dama::mover (struct jugada * jugadaActual)
{
	int error;

	Casilla aux2, aux =  (*jugadaActual).destino - (*jugadaActual).origen;
	aux2 = aux.unitario();

	if ( abs(aux2.x)==1 || abs(aux2.y)==1 || aux.x==0 || aux.y==0)
		error = Pieza::mover(  &(*jugadaActual)  );

	return error;
}
