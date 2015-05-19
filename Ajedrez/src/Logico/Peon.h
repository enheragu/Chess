#pragma once

#include "Pieza.h"

class Peon : public PeonMovido2
{
public:
	Peon(void);
	virtual ~Peon(void);
	
	bool mover (struct jugada*);
	int setTipo (int turno);
};

