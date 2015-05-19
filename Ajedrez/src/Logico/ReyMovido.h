#pragma once

#include "Pieza.h"

class ReyMovido : public Pieza
{
public:
	ReyMovido(void);
	~ReyMovido(void);

	bool mover (struct jugada*);
	int setTipo (int turno);
};

