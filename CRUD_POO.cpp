#include <iostream>
#include <stdio.h>  
#include <string.h> 
using namespace std;
const char *registro_estudiantes = "registro_estudiantes.dat";

struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	char direccion;
	int telefono;
};
 void abrir_registro();
 void insertar_estudiante();
 void actualizar_estudiante();
 void buscar_estudiante();
 void eliminar_estudiante();
int main (){
	char cont;
	do{
	int eleccion=0;
	cout<<"---------Bienvenido al sistema gestor de Estudiantes---------"<<endl;
	cout<<"Seleccione la operaci�n que desea realizar: "<<endl;
	cout<<"1. Crear arch"<<endl;
	cout<<"2. Ingresar estudiante"<<endl;
	cout<<"3. Ver lista de estudiantes"<<endl;
	cout<<"4. Actualizar informaci�n de estudiantes"<<endl;
	cout<<"5. Borrar informaci�n de un estudiante"<<endl<<endl;
	cin>>eleccion;
	switch(eleccion){
		case 1:
			abrir_registro();
		break;
		case 2:
			registro_estudiante();
		break;
		case 3:
			buscar_estudiante();
		break;
		case 4:
			actualizar_estudiante();
		break;
		case 5:
			eliminar_estudiante();
		break;
		default:
			cout<<"La opci�n seleccionada no est� disponible, por favor vuelva a intentarlo"<<endl;
		break;
	}
	cout<<"Desea continuar y realizar otra operaci�n? s/n";
	cin>>cont;
	}while((cont == 's')|| (cont =='S'));
	return 0;
}

void buscar_estudiante(){
		FILE* arch = fopen(registro_estudiantes,"rb");	
	int posicion=0,indic=0,cod=0;
	cout<<"Inserte el c�digo del estudiante que desea visualizar: ";
	cin>>cod;
	
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,arch);	
	do{
	   if(estudiante.codigo == cod)	{
	   	cout<<"Codigo: "<<estudiante.codigo<<endl;
	   	cout<<"Nombres: "<<estudiante.nombre<<endl;
	   	cout<<"Apellidos: "<<estudiante.apellido<<endl;
	   	cout<<"Direccion: "<<estudiante.direccion<<endl;
	   	cout<<"Telefono: "<<estudiante.telefono<<endl;
	   }
	   fread(&estudiante,sizeof(Estudiante),1,arch);	
	} while(feof(arch)==0);
	fclose(arch);
}

void abrir_registro(){

	system("cls");
	FILE* arch = fopen(registro_estudiantes, "rb");
	if(!arch) {
		arch = fopen(registro_estudiantes, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, arch );
	cout << "Id" <<"││"<< "Codigo" <<"││"<< "Nombres"<<" "<<"Apellidos"<<" "<<"Direccion"<<" "<<"N. Teléfono"<<" "<<endl;	
		do{
		cout<<"******************************************************************************** \n";
		cout << registro <<" - "<< estudiante.codigo <<" - "<< estudiante.nombre<<" - "<<estudiante.apellido<<" - "<<estudiante.direccion<<" - "<<estudiante.telefono<<endl;
        
		fread ( &estudiante, sizeof(Estudiante), 1, arch );
		registro += 1;	
		} while (feof( arch ) == 0);
		
    cout<<endl;
    
		fclose(arch);
	}
void registro_estudiante(){
	char continuar;
	FILE* arch = fopen(registro_estudiantes, "ab"); // ab
		Estudiante estudiante;
		 string nombre,apellido;
		do{
			fflush(stdin);
			
		cout<<"Inserte el codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
		cout<<"Inserte el nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
		cout<<"Inserte el apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		cout<<"Inserte la direccion:";
		getline(cin,apellido);
		cout<<"Inserte el telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite( &estudiante, sizeof(Estudiante), 1, arch );
		cout<<"Desea insertar otro nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
	fclose(arch);
	abrir_registro();
}
void actualizar_estudiante(){
	
	FILE* arch = fopen(registro_estudiantes, "r+b");
		int id;
		string nombre,apellido,direccion;	
    	Estudiante estudiante;
		cout << "Inserte el ID del estudiante que desea Modificar: ";
    		cin >> id;
    		fseek ( arch, id * sizeof(Estudiante), SEEK_SET ); 
		cout<<"Inserte el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Inserte el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Inserte el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		cout<<"Inserte la Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str()); 
		cout<<"Inserte el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, arch );
		
	fclose(arch);
	abrir_registro();
		system("PAUSE");
}
void eliminar_estudiante(){
	const char *nombre_arch_temp = "arch_temp.dat";
	Estudiante estudiante;
	FILE* arch = fopen(registro_estudiantes, "rb");
	FILE* arch_temp=fopen(nombre_arch_temp,"w+b");
	int id=0,i=0;
		cout<<"Inserte el id a eliminar:"; 
	cin>>id; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,arch)){
			
			if (i != id){
				fwrite(&estudiante,sizeof(Estudiante),1,arch_temp);
			} 
			
			i++; 
		}
	                
		fclose(arch_temp); 
		fclose(arch); 
	                
		arch_temp=fopen(nombre_arch_temp,"rb"); 
		arch=fopen(registro_estudiantes,"wb"); 
		while(fread(&estudiante,sizeof(Estudiante),1, arch_temp)){ 
			fwrite(&estudiante,sizeof(Estudiante),1, arch); 
		}
	                
	fclose(arch_temp); 
	fclose(arch); 
	abrir_registro();
		system("PAUSE");
}


