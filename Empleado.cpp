#include "Empleado.h"

Empleado::Empleado()
{
}

Empleado::Empleado(string nombre,int edad,int nivel,int habilidad,int pereza)
{
	this->nombre=nombre;
	this->edad=edad;
	this->nivel=nivel;
	this->habilidad=habilidad;
	this->pereza=pereza;
	this->tarea=NULL;
}

string Empleado::getNombre(){
	return this->nombre;
}

void Empleado::setNombre(string nombre){
	this->nombre=nombre;
}

int Empleado::getEdad(){
	return this->edad;
}

void Empleado::setEdad(int edad){
	this->edad=edad;
}

int Empleado::getNivel(){
	return this->nivel;
}

void Empleado::setNivel(int nivel)
{
	this->nivel=nivel;
}

int Empleado::getHabilidad(){
	return this->habilidad;
}

void Empleado::setHabilidad(int habilidad)
{
	this->habilidad=habilidad;
}

int Empleado::getPereza(){
	return this->pereza;
}

void Empleado::setPereza(){
	this->pereza=pereza;
}

Tarea* Empleado::getTarea(){
	return this->tarea;
}

void Empleado::setTarea(Tarea* tarea){
	this->tarea=tarea;
}

Empleado::~Empleado()
{
}
