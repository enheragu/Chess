#include "Alfil.h"
#include <math.h>


Alfil::Alfil(void)
{
}


Alfil::~Alfil(void)
{
}


/**************************************************************************
 *		  	  Comportamiento Alfil				  *
 **************************************************************************/

int Alfil::setTipo (int turno)
{
	return ALFIL*turno;
}

bool Alfil::mover (struct jugada & jugadaActual)
{
	int error;

	Casilla aux =  jugadaActual.destino - jugadaActual.origen;
	aux = aux.unitario();

	if ( abs(aux.x)==1 || abs(aux.y)==1)
		error = Pieza::mover(  jugadaActual  );

	return error;
}
