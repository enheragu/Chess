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

	Peon peones[8];
	Torre torres[2];
	Alfil alfiles[2];
	Caballo caballos[2];
	Rey rey;
	Dama dama;

	Jugador(void);
	~Jugador(void);
};

