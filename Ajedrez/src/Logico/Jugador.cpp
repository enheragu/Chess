#include "Jugador.h"


Jugador::Jugador(int color)
{
	if (color==BLANCAS) 
	{
		for (int i=0; i<8; i++)
			peones[i] = new Peon (i,1,BLANCAS);

		for (int i=0; i<2; i++)
			alfiles[i] = new Alfil ((i+2)*(5/2),0,BLANCAS);
			//alfiles en 2 y en 5

		for (int i=0; i<2; i++)
			torres[i] = new Torre (i*7,0,BLANCAS);
			//torres en 0 y en 7

		for (int i=0; i<2; i++)
			caballos[i] = new Caballo ((i+1)*(6/2),0,BLANCAS);
			//caballos en 1 y en 6

		rey = new Rey (4,0,BLANCAS);
		dama = new Dama (3,0,BLANCAS);
	}
	else if (color==NEGRAS)
	{
		for (int i=0; i<8; i++)
			peones[i] = new Peon (i,6,NEGRAS);

		for (int i=0; i<2; i++)
			alfiles[i] = new Alfil ((i+2)*(5/2),7,NEGRAS);

		for (int i=0; i<2; i++)
			torres[i] = new Torre (i*7,7,NEGRAS);

		for (int i=0; i<2; i++)
			caballos[i] = new Caballo ((i+1)*(6/2),7,NEGRAS);

		rey = new Rey (4,7,NEGRAS);
		dama = new Dama (3,7,NEGRAS);
	}

}


Jugador::~Jugador(void)
{
	for (int i=0; i<8; i++) delete [i] peones;
	for (int i=0; i<2; i++) delete [i] torres;
	for (int i=0; i<2; i++) delete [i] alfiles;
	for (int i=0; i<2; i++) delete [i] caballos;
	delete rey;
	delete dama;
}
