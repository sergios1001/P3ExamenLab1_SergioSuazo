#include <iostream>
#include <string>
#include <vector>
#include "Empleado.h"
#include "Tarea.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu(){
	int retValue=0;
	
	while(retValue < 1 || retValue > 7){
		
		cout<<"----------------------"<<endl
			<<"1.- Contratar Empleado"<<endl
			<<"2.- Despedir Empleado"<<endl
			<<"3.- Listar Empleados"<<endl
			<<"4.- Crear Tarea"<<endl
			<<"5.- Listar Tareas"<<endl
			<<"6.- Iniciar Proyecto"<<endl
			<<"7.- Salir"<<endl
			
			<<"Ingrese una opcion entre 1 y 7: ";
			
			cin>>retValue;

			
			if(retValue >= 1 && retValue <= 7){
				break;
			}
				
			else{
						
				cout<<endl<<"Opcion incorrecta, elija nuevamente "<<endl;
			}
					
	}//end while
	
	
	return retValue;
}

int menu2(){
	int retValue=0;
	
	while(retValue < 1 || retValue > 3){
		
		cout<<"-------------------"<<endl
			<<"1.- Siguiente dia"<<endl
			<<"2.- Generar reporte"<<endl
			<<"3.- Salir"<<endl
			<<"Ingrese una opcion entre 1 y 3: ";
			
			cin>>retValue;

			
			if(retValue >= 1 && retValue <= 3){
				break;
			}
				
			else{
						
				cout<<endl<<"Opcion incorrecta, elija nuevamente "<<endl;
			}
					
	}//end while
	
	
	return retValue;
}

vector <Empleado*> empleados; 
vector <Tarea*> backlog;

int main(int argc, char** argv) {
	int option=0;
	while( option != 3 ) {
		
		switch( option = menu() ){ 
		
			case 1:{
				string nombre;
				int edad,nivel,habilidad,pereza;
				cout<<"Nombre del Empleado: ";
				cin>>nombre;
				cout<<"Edad: ";
				cin>>edad;
				cout<<"Nivel: ";
				cin>>nivel;
				cout<<"Porcentaje de Habilidad: ";
				cin>>habilidad;
				cout<<"Porcentaje de Pereza: ";
				cin>>pereza;
				
				empleados.push_back(new Empleado(nombre,edad,nivel,habilidad,pereza));
				
				cout<<"Se contrato al empleado exitosamente"<<endl;
				
				break;
			}
			case 2:{
				for(int i=0;i<empleados.size();i++){
					
				}
				
				break;	
			} 
			    
			case 3:{

				break;

			}
			case 4:{
				break;
			}
			case 5:{
				break;
			}
			case 6:{
				break;
			}
			case 7:{
				//salir
				cout<<"Saliendo del programa..."<<endl;
				break;
			}
			
						
		}//switch
	
	}//while
	return 0;
}
