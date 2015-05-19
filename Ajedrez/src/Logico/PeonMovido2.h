#pragma once

#include "Pieza.h"

class PeonMovido2 : public Pieza
{
public:
	PeonMovido2(void);
	~PeonMovido2(void);

	bool mover (struct jugada*);
	int setTipo (int turno);
};

