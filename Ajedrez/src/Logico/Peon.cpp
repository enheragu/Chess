#include "Peon.h"


Peon::Peon(void)
{
}


Peon::~Peon(void)
{
}


int Peon::setTipo (int turno)
{
	return PEON_SIN_MOVER*turno;
}

bool Peon::mover (struct jugada * jugadaActual)
{
	bool error;
	/*
	==== Restriccion propia de cada pieza ====
	*/
	error = Pieza::mover(  &(*jugadaActual)  );

	return error;
}