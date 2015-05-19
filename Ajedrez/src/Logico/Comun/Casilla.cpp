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
	return (float) sqrt(x*x+y*y);
}

float Casilla::argumento()
{
	return (float)atan2(y,x);
}

Casilla Casilla::unitario()
{
	Casilla retorno(x,y);
	float mod=modulo();
	if(mod>0.00001)
	{
		retorno.x/=mod;
		retorno.y/=mod; 
	} 
	return retorno; 
}

Casilla Casilla::operator - (Casilla op) 
{ 
	Casilla res;
	res.x=x-op.x; 
	res.y=y-op.y; 
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