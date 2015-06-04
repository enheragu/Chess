#pragma once

#include "Pieza.h"

class Rey : public Pieza
{
public:
	Rey(void);
	virtual ~Rey(void);

	bool mover (struct jugada&);
	int setTipo (int turno);
};

