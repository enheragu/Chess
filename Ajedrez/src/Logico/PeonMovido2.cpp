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
