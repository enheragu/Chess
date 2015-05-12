// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Caballo : public Pieza
{
public:
	Caballo(int x, int y, int color);
	~Caballo(void);
	//restricciones de movimiento
	virtual void moverPieza (struct jugada*);
	void comeCaballo (void);
};

