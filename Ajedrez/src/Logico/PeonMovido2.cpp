#include "PeonMovido2.h"


PeonMovido2::PeonMovido2(void)
{
}


PeonMovido2::~PeonMovido2(void)
{
}

int PeonMovido2::setTipo (int turno)
{
	return PEON_MOVIDO*turno;
}

bool PeonMovido2::mover (struct jugada * jugadaActual)
{
	int error;
	/*
	==== Restriccion propia de cada pieza ====
	*/
	error = Pieza::mover(  &(*jugadaActual)  );

	return error;
}
