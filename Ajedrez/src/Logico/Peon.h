// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Peon : public Pieza
{
	
public:
	Peon(int x, int y, int color);
	~Peon(void);
	//restricciones de movimiento
	virtual void moverPieza (struct jugada*);
	void comePeon (void);
};



