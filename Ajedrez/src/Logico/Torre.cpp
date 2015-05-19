#include "Torre.h"


Torre::Torre(void)
{
}


Torre::~Torre(void)
{

}

int Torre::setTipo (int turno)
{
	return TORRE_MOVIDA*turno;
}

