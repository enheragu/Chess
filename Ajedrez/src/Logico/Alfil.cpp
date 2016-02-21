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
	bool error = 0;

	Casilla aux =  jugadaActual.destino - jugadaActual.origen;
	//aux = aux.unitario();

	if ( abs(aux.x)==abs(aux.y))
		error = Pieza::mover(  jugadaActual  );

	return error;
}
