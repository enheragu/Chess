#pragma once

#include "Pieza.h"

class Rey : public ReyMovido
{
public:
	Rey(void);
	virtual ~Rey(void);

	bool mover (struct jugada*);
	int setTipo (int turno);
};

