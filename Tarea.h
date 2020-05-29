#ifndef TAREA_H
#define TAREA_H
#include <string>

using namespace std;
class Tarea
{
	public:
		//constructores
		Tarea();
		Tarea(string,int,int);
		
		//gets y sets
		string getDescripcion();
		void setDescripcion(string);
		int getNivel();
		void setNivel(int);
		int getCarga();
		void setCarga(int);
		
		//destructor
		~Tarea();
	protected:
		string descripcion;
		int nivel,carga;
};

#endif
