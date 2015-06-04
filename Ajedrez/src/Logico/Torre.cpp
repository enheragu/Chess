#include "Torre.h"


Torre::Torre(void)
{
}


Torre::~Torre(void)
{

}

/**************************************************************************
 *			  Comportamiento Torre				  *
 **************************************************************************/

int Torre::setTipo (int turno)
{
	return TORRE_MOVIDA*turno;
}

bool Torre::mover (struct jugada & jugadaActual)
{
	bool error=0;

	Casilla aux =  jugadaActual.destino - jugadaActual.origen;

	if ( aux.x==0 || aux.y==0 )
		error = Pieza::mover(  jugadaActual  );
	return error;
}
