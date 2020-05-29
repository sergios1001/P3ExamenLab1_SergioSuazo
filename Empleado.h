#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>

using namespace std;
class Empleado
{
	public:
		//constructores
		Empleado();
		Empleado(string,int,int,int,int);
		
		//gets y sets
		string getNombre();
		void setNombre(string);
		int getEdad();
		void setEdad(int);
		int getNivel();
		void setNivel(int);
		int getHabilidad();
		void setHabilidad(int);
		int getPereza();
		void setPereza();
		
		
		//destructor
		~Empleado();
	protected:
		string nombre;
		int edad,nivel,habilidad,pereza;
};

#endif
