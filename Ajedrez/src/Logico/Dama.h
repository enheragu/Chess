// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Dama : public Pieza
{
public:
	Dama(int x, int y, int color);
	~Dama(void);
	//restricciones de movimiento
	virtual void moverPieza (struct jugada*);
	void comeDama (void);
};

