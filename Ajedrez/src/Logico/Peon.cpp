#include "Peon.h"
#include <math.h>


Peon::Peon(void)
{
}


Peon::~Peon(void)
{
}

/**************************************************************************
 *					  	  Comportamiento Peon							  *
 **************************************************************************/

int Peon::setTipo (int turno)
{
	return PEON_MOVIDO*turno;
}

bool Peon::mover (struct jugada &jugadaActual)
{
	bool error;
	Casilla diferenciaMov;
	/*
	==== Restriccion propia de cada pieza ====
	*/
	diferenciaMov = (jugadaActual.destino - jugadaActual.origen);

				//Avanzar una casilla hacia alante			
	if ((diferenciaMov.y == 1 && diferenciaMov.x ==0) || 
				//Avanzar dos casillas hacia alante si el peon no se ha movido
		( (diferenciaMov.y == 2 && diferenciaMov.x ==0) && abs(leerCasilla(jugadaActual.origen)) == PEON_SIN_MOVER))

		error = Pieza::mover( jugadaActual );

	return error;
}
