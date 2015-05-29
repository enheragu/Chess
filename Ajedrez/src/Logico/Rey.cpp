#include "Rey.h"


Rey::Rey(void)
{
}


Rey::~Rey(void)
{
}

int Rey::setTipo (int turno)
{
	//set tipo se utiliza para sobreescribir posicion, si se usa significa que se mueve el rey
	return REY_MOVIDO*turno;
}

bool Rey::mover (struct jugada * jugadaActual)
{
	bool error;
	/*
	==== Restriccion propia de cada pieza ====
	*/
	error = Pieza::mover(  &(*jugadaActual)  );

	return error;
}
