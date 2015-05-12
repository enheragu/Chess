
// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Alfil : public Pieza
{


public:
	Alfil(int x, int y, int color);
	~Alfil(void);
	//restricciones de movimiento
	virtual void moverPieza (struct jugada*);
	void comeAlfil (void);
};

