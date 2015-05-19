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
