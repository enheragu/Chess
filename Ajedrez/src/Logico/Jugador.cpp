#include "Jugador.h"


Jugador::Jugador(int color)
{
	if (color==BLANCAS) 
	{
		for (int i=0; i<8; i++)
			peones[i] = new Peon (i,1,BLANCAS);

		rey = new Rey (4,0,BLANCAS);
		dama = new Dama (3,0,BLANCAS);
	}
	else if (color==NEGRAS)
	{
		for (int i=0; i<8; i++)
			peones[i] = new Peon (i,6,NEGRAS);

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
