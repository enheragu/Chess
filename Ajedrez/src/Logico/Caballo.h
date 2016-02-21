#pragma once

#include "Pieza.h"

class Caballo : public Pieza
{
public:
	Caballo(void);
	virtual ~Caballo(void);

	bool mover (struct jugada&);
	int setTipo (int turno);
};

