#include "Rey.h"
#include <math.h>

Rey::Rey(void)
{
}


Rey::~Rey(void)
{
}

/**************************************************************************
 *					  	  Comportamiento Rey							  *
 **************************************************************************/

int Rey::setTipo (int turno)
{
	//set tipo se utiliza para sobreescribir posicion, si se usa significa que se mueve el rey
	return REY_MOVIDO*turno;
}

bool Rey::mover (struct jugada & jugadaActual)
{
	bool error;
	Casilla diferenciaAbs;
	Casilla diferenciaMov;
	Casilla posTorre;
	/*
	==== Restriccion propia de cada pieza ====
	*/
	diferenciaMov = (jugadaActual.destino - jugadaActual.origen);
	diferenciaAbs = ((jugadaActual.destino - jugadaActual.origen)).valAbsoluto();

			//Modulo igual a 1 o igual a raiz de dos
	if (diferenciaAbs.modulo()==1 || diferenciaAbs.modulo() == 1.4142)
		error = Pieza::mover( jugadaActual );
			
			//Enroque mover 2 en x, rey no movido y torre no movida
	else if ( (diferenciaMov.y == 0 && abs(diferenciaMov.x ==2)) && (abs(leerCasilla(jugadaActual.origen)) == REY_NO_MOVIDO))


		/***************************************************************
		 *						enroque corto						   *
		***************************************************************/
		posTorre.x = 7;
		posTorre.y = jugadaActual.destino.y;

		if ( (diferenciaMov.x == 2) && (abs(leerCasilla (posTorre)) == TORRE_NO_MOVIDA) )
			error = Pieza::mover( jugadaActual );
			if (error == 1)

				posTorre.x = 5;
				posTorre.y = jugadaActual.destino.y;
				Torre::escribirPosicion(posTorre, TORRE_MOVIDA);


		/***************************************************************
		*						enroque largo						   *
		***************************************************************/
		posTorre.x = 0;
		posTorre.y = jugadaActual.destino.y;

		if ( (diferenciaMov.x == -2) && (abs(leerCasilla (posTorre)) == TORRE_NO_MOVIDA) )
			error = Pieza::mover( jugadaActual );
			if (error == 1)

				posTorre.x = 3;
				posTorre.y = jugadaActual.destino.y;
				Torre::escribirPosicion(posTorre, TORRE_MOVIDA);

	return error;
}