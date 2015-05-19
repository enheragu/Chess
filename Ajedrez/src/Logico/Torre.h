#pragma once

#include "Pieza.h"

class Torre : public Pieza
{
public:
	Torre(void);
	virtual ~Torre(void);

	bool mover (struct jugada*);
	int setTipo (int turno);
};

