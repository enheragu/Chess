#pragma once

#include "Pieza.h"
#include "Peon.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Rey.h"
#include "Torre.h"
#include "Dama.h"

class Jugador
{
public:
	//1 blancas, -1 negras
	int color;

	Peon *peones[8];
	Torre *torres[2];
	Alfil *alfiles[2];
	Caballo *caballos[2];
	Rey *rey;
	Dama *dama;

	Jugador(int color);
	virtual ~Jugador(void);
};

