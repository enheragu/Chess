#include "Jugador.h"


Jugador::Jugador(int color)
{
	if (color==BLANCAS) 
	{
		for (int i=0; i<8; i++)
			peones[i] = new Peon ((i+2),2,BLANCAS);

		for (int i=0; i<2; i++)
			alfiles[i] = new Alfil ((i+4)*(7/5),1,BLANCAS);
			//alfiles en 2 y en 5, contando con las 2 columnas prohibidas

		for (int i=0; i<2; i++)
			torres[i] = new Torre ((i+2)*(9/3),1,BLANCAS);
			//torres en 0 y en 7, contando con las 2 columnas prohibidas

		for (int i=0; i<2; i++)
			caballos[i] = new Caballo ((i+3)*(8/4),1,BLANCAS);
			//caballos en 1 y en 6, contando con las 2 columnas prohibidas

		rey = new Rey (6,1,BLANCAS);
		dama = new Dama (5,1,BLANCAS);
	}
	else if (color==NEGRAS)
	{
		for (int i=0; i<8; i++)
			peones[i] = new Peon (i+2,7,NEGRAS);

		for (int i=0; i<2; i++)
			alfiles[i] = new Alfil ((i+4)*(7/5),8,NEGRAS);

		for (int i=0; i<2; i++)
			torres[i] = new Torre ((i+2)*(9/3),8,NEGRAS);

		for (int i=0; i<2; i++)
			caballos[i] = new Caballo ((i+3)*(8/4),8,NEGRAS);

		rey = new Rey (6,8,NEGRAS);
		dama = new Dama (5,8,NEGRAS);
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
