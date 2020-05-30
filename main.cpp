#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
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
	while( option != 7 ) {
		
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
				int despide;
				for(int i=0;i<empleados.size();i++){
					cout<<i<<"- "<<empleados[i]->getNombre()<<endl;
				}
				cout<<"Elija el empleado al que quiere despedir: ";
				cin>>despide;
				
				empleados.erase(empleados.begin() + despide);
				break;	
			} 
			    
			case 3:{
				cout<<"Lista de Empleados: "<<endl;
				for(int i=0;i<empleados.size();i++){
					cout<<i<<"- "<<empleados[i]->getNombre()<<endl;
				}
				break;

			}
			case 4:{
				string descripcion;
				int nivel,carga;
				cout<<"Ingrese la descripcion de la Tarea: ";
				cin>>descripcion;
				cout<<"Nivel de la tarea: ";
				cin>>nivel;
				cout<<"Carga de la tarea: ";
				cin>>carga;
				
				backlog.push_back(new Tarea(descripcion,nivel,carga));
				break;
			}
			case 5:{
				cout<<"Lista de Tareas: "<<endl;
				for(int i=0;i<backlog.size();i++){
					cout<<i<<"- "<<backlog[i]->getDescripcion()<<endl;
				}
				break;
			}
			case 6:{
				int sel=0;
				int cargaTotal=0;
				int proyeccion;
				
				int perezosos=0,fallido=0,exitoso=0,progreso=0;
				for(int i=0;i<backlog.size();i++){
					cargaTotal+=backlog[i]->getCarga();
				}
				proyeccion=cargaTotal+cargaTotal*.2;
				//cout<<cargaTotal<<endl;
				while(sel!=3 && cargaTotal!=0){
					
					cout<<"Dias para terminar el proyecto: "<< proyeccion <<endl;
					
					switch( sel = menu2()){
						
						case 1:{
							perezosos=0;
							fallido=0;
							exitoso=0;
							
							for(int i=0;i<empleados.size();i++){
								if(empleados[i]->getTarea()==NULL){
									for(int j=0;j<backlog.size();j++){
										if(empleados[i]->getNivel()>=backlog[j]->getNivel())
										{
											empleados[i]->setTarea(backlog[j]);
											backlog.erase(backlog.begin() + j);
											progreso++;
											break;
										}
									}	
								}
							}
							
							for(int i=0;i<empleados.size();i++){
								if(empleados[i]->getTarea()!=NULL){
									int pereza = rand() % 101;
									if(empleados[i]->getPereza() < pereza){
										int habilidad = rand() % 101;
										if(empleados[i]->getHabilidad()>=habilidad){
											
											empleados[i]->getTarea()->setCarga(empleados[i]->getTarea()->getCarga() - 1 );
											if(empleados[i]->getTarea()->getCarga()==0)
											{
												empleados[i]->setTarea(NULL);
												progreso--;
											}
											cargaTotal--;
											exitoso++;
										}
										else
										{
											fallido++;
										}
									}
									else
									{
										perezosos++;
									}
								}
							}
							
							proyeccion--;
							
							break;
						}
						case 2:{
							
							cout<<"Tareas en backlog: "<<backlog.size()<<endl;
							cout<<"Tareas en progreso: "<<progreso<<endl;
							cout<<"Empleados perezosos: "<<perezosos<<endl;
							cout<<"Empleados que fallaron: "<<backlog.size()<<endl;
							cout<<"Empleados que lograron el dia: "<<backlog.size()<<endl;
							break;
						}
						case 3:{
							//salir
							cout<<"Saliendo de la simulacion..."<<endl;
							break;
						}
					}
				}
				
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
