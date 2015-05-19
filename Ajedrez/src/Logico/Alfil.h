#pragma once

#include "Pieza.h"

class Alfil : public Pieza
{
public:
	Alfil(void);
	virtual ~Alfil(void);

	bool mover (struct jugada*);
	int setTipo (int turno);
};

