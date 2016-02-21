#pragma once

#include "Pieza.h"

class Dama : public Pieza
{
public:
	Dama(void);
	virtual ~Dama(void);

	bool mover (struct jugada&);
	int setTipo (int turno);
};

