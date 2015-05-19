#include "ReyMovido.h"


ReyMovido::ReyMovido(void)
{
}


ReyMovido::~ReyMovido(void)
{
}

int ReyMovido::setTipo (int turno)
{
	return REY_MOVIDO*turno;
}

bool ReyMovido::mover (struct jugada * jugadaActual)
{
	int error;
	/*
	==== Restriccion propia de cada pieza ====
	*/
	error = Pieza::mover(  &(*jugadaActual)  );

	return error;
}