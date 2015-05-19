#include "Caballo.h"


Caballo::Caballo(void)
{
}


Caballo::~Caballo(void)
{
}

int Caballo::setTipo (int turno)
{
	return CABALLO*turno;
}

bool Caballo::mover (struct jugada * jugadaActual)
{
	int error;
	/*
	==== Restriccion propia de cada pieza ====
	*/
	error = Pieza::mover(  &(*jugadaActual)  );

	return error;
}