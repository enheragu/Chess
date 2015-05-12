// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Torre : public Pieza
{

public:
	Torre(int x, int y, int color);
	~Torre(void);
	//restricciones de movimiento
	virtual void moverPieza (struct jugada*);
	void comeTorre (void);
};

