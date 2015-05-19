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
