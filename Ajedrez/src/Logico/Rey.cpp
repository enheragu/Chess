#include "Rey.h"
#include <math.h>

Rey::Rey(void)
{
}


Rey::~Rey(void)
{
}

/**************************************************************************
 *			  Comportamiento Rey				  *
 **************************************************************************/

int Rey::setTipo (int turno)
{
	//set tipo se utiliza para sobreescribir posicion, si se usa significa que se mueve el rey
	return REY_MOVIDO*turno;
}

bool Rey::mover (struct jugada & jugadaActual)
{
	bool error = 0;
	Casilla diferenciaAbs;
	Casilla diferenciaMov;
	Casilla posTorre;
	/*
	==== Restriccion propia de cada pieza ====
	*/
	diferenciaMov = (jugadaActual.destino - jugadaActual.origen);
	diferenciaAbs = ((jugadaActual.destino - jugadaActual.origen)).valAbsoluto();

			//O una de las componentes es 1 o ambas son 1
	if ((diferenciaAbs.x + diferenciaAbs.y ==1)||(diferenciaAbs.x==1 && diferenciaAbs.y==1))
		error = Pieza::mover( jugadaActual );
			
			//Enroque mover 2 en x, rey no movido y torre no movida
	else if ( ((diferenciaAbs.x == 0) && abs(diferenciaMov.y ==2)) && (abs(leerCasilla(jugadaActual.origen)) == REY_NO_MOVIDO))


		/***************************************************************
		 *			   enroque largo		       *
		 ***************************************************************/
		posTorre.y = 7;
		posTorre.x = jugadaActual.destino.x;

		if ( (diferenciaMov.y == 2) && (abs(leerCasilla (posTorre)) == TORRE_NO_MOVIDA) )
		{
			error = Pieza::mover( jugadaActual );
			if (error == 1)
			{
				escribirPosicion(posTorre, C_VACIA);
				posTorre.y = 4;
				posTorre.x = jugadaActual.destino.x;
				escribirPosicion(posTorre, TORRE_MOVIDA);
			}
		}

		/***************************************************************
		 *			   enroque corto		       *
		 ***************************************************************/
		posTorre.y = 0;
		posTorre.x = jugadaActual.destino.x;

		if ( (diferenciaMov.y == -2) && (abs(leerCasilla (posTorre)) == TORRE_NO_MOVIDA) )
		{
			error = Pieza::mover( jugadaActual );
			if (error == 1)
			{
				escribirPosicion(posTorre, C_VACIA);
				posTorre.y = 2;
				posTorre.x = jugadaActual.destino.x;
				escribirPosicion(posTorre, TORRE_MOVIDA);
			}
		}
	return error;
}

/*
Casilla Rey::buscarRey ()
{
	for (int i=0; i<8; i++)
		for (int j=0; j<8; j++)
		{
			Casilla posicion (i,j);
			if (leerCasilla (posicion) == getTurno()*REY_NO_MOVIDO || leerCasilla (posicion) ==  getTurno()*REY_MOVIDO )
				return posicion;
		}
}
*/