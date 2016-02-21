#include "Casilla.h"
#include <math.h>

//constructor
Casilla::Casilla(float xv, float yv)
{
	x=xv;
	y=yv; 
}


Casilla::~Casilla(void)
{
}

/**************************************************************************
 *					  	  Operadores de Casilla							  *
 **************************************************************************/

Casilla Casilla::operator + (Casilla op)
{
	Casilla resultado; 
	resultado.x = x + op.x; 
	resultado.y = y + op.y; 
	return resultado;
}

Casilla Casilla::operator + (float real) 
{ 
	Casilla resultado; 
	resultado.x = x + real; 
	resultado.y = y; 
	return resultado;
}

float Casilla::modulo()
{
	return sqrt((float)(x*x+y*y));
}

float Casilla::argumento()
{
	return atan2((float)y,(float)x);
}

Casilla Casilla::unitario()
{
	Casilla retorno (x,y);

	if (x != 0) 
		retorno.x = x/x;
	else retorno.x = 0;

	if (y != 0)
		retorno.y = y/y;
	else retorno.y = 0;

	return retorno;
	/*
	Casilla retorno(x,y);
	float mod=modulo();
	if(mod>0.00001)
	{
		retorno.x=(int)(retorno.x/mod);
		retorno.y=(int)(retorno.y/mod);
	} 
	return retorno; 
	*/
}

Casilla Casilla::operator - (Casilla op) 
{ 
	Casilla res;
	res.x=x-op.x; 
	res.y=y-op.y; 
	return res; 
} 

Casilla Casilla::operator / (Casilla op)
{
	Casilla res;
	if (op.x != 0)	
		res.x = x/op.x;
	else res.x = 0;
	
	if (op.y != 0)
		res.y = y/op.y;
	else res.y = 0;

	return res;
}

float Casilla::operator *(Casilla v)
{
	return x*v.x+y*v.y;
}

Casilla Casilla::operator *(float op)
{
	Casilla resultado(x*op,y*op);
	return resultado;	
}

Casilla Casilla::operator / (float op)
{
	Casilla resultado (x/op, y/op);
	return resultado;
}

bool Casilla:: operator != (Casilla op)
{
	if ((x=op.x) && (y=op.y))
		return 0;
	else return 1;
}

Casilla Casilla::valAbsoluto()
{
	Casilla absoluto;
	absoluto.x = abs((*this).x);
	absoluto.y = abs((*this).y);
	return absoluto;
}