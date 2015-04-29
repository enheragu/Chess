// Clase derivada Pieza:

#pragma once

#include "Pieza.h"

class Rey : public Pieza
{

public:
	Rey( int t, int x, int y);
	~Rey(void);
	//restricciones de movimiento
	void mueveRey (void);
	void comeRey (void);
	void enrocar (bool movido);
};



