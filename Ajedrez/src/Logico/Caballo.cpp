#include "Caballo.h"
#include <math.h>


Caballo::Caballo(void)
{
}


Caballo::~Caballo(void)
{
}


/**************************************************************************
 *					  	  Comportamiento Caballo						  *
 **************************************************************************/

int Caballo::setTipo (int turno)
{
	return CABALLO*turno;
}

bool Caballo::mover (struct jugada & jugadaActual)
{
	bool error;
	Casilla diferenciaMov;
	/*
	==== Restriccion propia de cada pieza ====
	*/
	diferenciaMov = (jugadaActual.destino - jugadaActual.origen);

				//Avanzar una casilla hacia alante			//Avanzar dos casillas hacia alante
	if(((abs(diferenciaMov.x) == 2) && (abs(diferenciaMov.y) == 1))||((abs(diferenciaMov.x) == 1) && (abs(diferenciaMov.y) == 2)))
			error = Pieza::mover( jugadaActual );

	return error;
}