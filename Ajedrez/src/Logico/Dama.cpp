#include "Dama.h"
#include <math.h>


Dama::Dama(void)
{
}


Dama::~Dama(void)
{
}

/**************************************************************************
 *					  	  Comportamiento Dama							  *
 **************************************************************************/

int Dama::setTipo (int turno)
{
	return DAMA*turno;
}

bool Dama::mover (struct jugada & jugadaActual)
{
	bool error = 0;

	Casilla aux =  jugadaActual.destino - jugadaActual.origen;

	if ( abs(aux.x)==abs(aux.y) || aux.x==0 || aux.y==0)
		error = Pieza::mover(  jugadaActual  );

	return error;
}
