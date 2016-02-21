#include "CoordinadorAjedrez.h"


CoordinadorAjedrez::CoordinadorAjedrez(void)
{
	estado = INICIO;
	error = 1;
	origen.x = -100;
	origen.y = -100;
	destino.x = -100;
	destino.y = -100;
}

CoordinadorAjedrez::~CoordinadorAjedrez(void)
{
}

void CoordinadorAjedrez::Dibuja()
{
	if(estado==INICIO)
	{
		graficosAjedrez.dibujaInicio();
	}
	else if(estado==JUEGO)
	{
		graficosAjedrez.Inicializa();
		dibujaPiezas();
		graficosAjedrez.dibujarTurno(logicaAjedrez.getTurno());

		if (origen.x == -100 && origen.y == -100)
		{
			graficosAjedrez.introduzcaOrigen();
			graficosAjedrez.introduzcaOpciones();
		}
		else if (destino.x == -100 && destino.y == -100 && origen.x != -100 && origen.y != -100)
		{
			graficosAjedrez.dibujarDisco(origen.x,origen.y, 255, 0, 0, 0.43);
			//graficosAjedrez.dibujarJaque(origen);
			graficosAjedrez.introduzcaDestino();
			graficosAjedrez.introduzcaOpciones();
		}
		if (error == 0) 
		{
			graficosAjedrez.Error();
		}
		/*
		if (logicaAjedrez.jaqueRey == true)
		{
			graficosAjedrez.ErrorJaque();
			graficosAjedrez.dibujarJaque(logicaAjedrez.jaque());
			logicaAjedrez.jaqueRey = false;
		}
		*/
	}
}

/*
void CoordinadorAjedrez::Tecla(unsigned char key)
{
	if(estado==INICIO)
	{
		if(key=='e')
		{
			graficosAjedrez.Inicializa();
			estado=JUEGO;
		}
		if(key=='s')
			exit(0);
	}
	else if(estado==JUEGO)
	{		
		if(key=='s')
			exit(0);
		if (key == 'r')
			logicaAjedrez.reset();
	}
	else if(estado==FIN)
	{
		if(key=='c')
			estado=INICIO;
	}

}
*/

void CoordinadorAjedrez::raton (Casilla &casilla)
{
	if (casilla.x>-1 && casilla.x<8 && casilla.y>-1 && casilla.y<8) 
	{
		if ((origen.x == -100 && origen.y == -100) && logicaAjedrez.leerCasilla(casilla)!=0 && logicaAjedrez.leerCasilla(casilla)/abs(logicaAjedrez.leerCasilla(casilla))==logicaAjedrez.getTurno())
		{
			origen.x = casilla.x;
			origen.y = casilla.y;
		}
		else if (destino.x == -100 && destino.y == -100 && origen.x != -100 && origen.y != -100 )
		{
			destino.x = casilla.x;
			destino.y = casilla.y;
		}

		if (origen.x != -100 && origen.y != -100 && destino.x != -100 && destino.y != -100)
		{
			jugada jugadaAct;
			jugadaAct.origen = origen;
			jugadaAct.destino = destino;			

			error = logicaAjedrez.jugadaAjedrez (jugadaAct);
			origen.x = -100; origen.y = -100; destino.x = -100; destino.y = -100;
		}
	}

}

void CoordinadorAjedrez::dibujaPiezas()
{
	int pieza;

	for (int i=0; i <8; i++)
		for (int j=0; j<8; j++)
		{
			Casilla casilla;
			casilla.x = i;
			casilla.y = j;
			pieza= logicaAjedrez.leerCasilla(casilla);
			switch (pieza)
			{
				case PEON_SIN_MOVER: 
					piezas.dibujaPeonBlanca(i,j);
					break;
				case PEON_MOVIDO:
					piezas.dibujaPeonBlanca(i,j);
					break;
				case CABALLO: 
					piezas.dibujaCaballoBlanca(i,j);
					break;
				case ALFIL: 
					piezas.dibujaAlfilBlanca(i,j);
					break;
				case TORRE_NO_MOVIDA: 
					piezas.dibujaTorreBlanca(i,j);
					break;
				case TORRE_MOVIDA: 
					piezas.dibujaTorreBlanca(i,j);
					break;
				case DAMA: 
					piezas.dibujaReinaBlanca(i,j);
					break;
				case REY_NO_MOVIDO: 
					piezas.dibujaReyBlanca(i,j);
					break;
				case REY_MOVIDO: 
					piezas.dibujaReyBlanca(i,j);
					break;

				case -PEON_SIN_MOVER: 
					piezas.dibujaPeonNegra(i,j);
					break;
				case -PEON_MOVIDO: 
					piezas.dibujaPeonNegra(i,j);
					break;
				case -CABALLO: 
					piezas.dibujaCaballoNegra(i,j);
					break;
				case -ALFIL: 
					piezas.dibujaAlfilNegra(i,j);
					break;
				case -TORRE_NO_MOVIDA: 
					piezas.dibujaTorreNegra(i,j);
					break;
				case -TORRE_MOVIDA: 
					piezas.dibujaTorreNegra(i,j);
					break;
				case -DAMA: 
					piezas.dibujaReinaNegra(i,j);
					break;
				case -REY_NO_MOVIDO: 
					piezas.dibujaReyNegra(i,j);
					break;
				case -REY_MOVIDO: 
					piezas.dibujaReyNegra(i,j);
					break;

				case C_VACIA: 
					break;
			}
		}
}


void CoordinadorAjedrez::processMenuEvents(unsigned char option) {

	if(estado == INICIO)
	{
		if(option== 'e')
		{
			graficosAjedrez.Inicializa();
			estado=JUEGO;
		}
		if(option== 's')
			exit(0);
	}
	else if(estado == JUEGO)
	{		
		if(option== 's')
			exit(0);
		if (option == 'r')
			logicaAjedrez.reset();
	}
	else if(estado == FIN)
	{
		if(option == 'c')
			estado=INICIO;
	}
}

