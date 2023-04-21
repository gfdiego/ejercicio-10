#include <iostream>
using namespace std;

const char *nombre_archivo = "notas.dat";
    struct Estudiante
    {
        int codigo;
        char nombres[50];
        char apellidos[50];
        int nota1;
        int nota2;
        int nota3;
        int nota4;
        int promedio;
        char resultado1[50]="aprobrado";
        char resultado2[50]="reprovbado";

    };
    void Crear();
    void Leer();
    void Actualizar();
    void Borrar();

int main(int argc, char const *argv[])
{
    int op;
   do
   {
    system("cls");
    cout<<"INGRESE UNA OPCION"<<endl;
    cout<<" "<<endl;
    cout<<"1.INGRESAR "<<endl;
    cout<<"2.MOSTRAR "<<endl;
    cout<<"3.MODIFICAR "<<endl;
    cout<<"4.BORRAR "<<endl;
     
    cout<<"ingresa una opcion: ";
    cin>>op;
    switch (op)
    {
    case 1:
        Crear();
         system("pause");
        break;
        case 2:
        Leer();
        system("pause");
        break;
        case 3:
        Actualizar();
        system("pause");
        break;
        case 4:
        Borrar();
        system("pause");
        break;
       

    default:
        break;
    }
    
   } while (op<=4 || op>=4);
return 0;

}
void Crear(){
    system("cls");
    FILE* archivo = fopen(nombre_archivo, "a+b");
    char res;
    Estudiante estudiante;
    do
    {
        fflush(stdin);
        cout<<"ingrese id";
        cin>>estudiante.codigo;
        cin.ignore();
        cout<<"ingrese nombre";
        cin.getline(estudiante.nombres,50);
         cout<<"ingrese Apellido";
        cin.getline(estudiante.apellidos,50);
         cout<<"ingrese nota 1";
         cin>>estudiante.nota1;
           cout<<"ingrese nota 2";
         cin>>estudiante.nota2;
           cout<<"ingrese nota 3";
         cin>>estudiante.nota3;
           cout<<"ingrese nota 4";
         cin>>estudiante.nota4;
          cout<<"Promedio: ";
          estudiante.promedio=(estudiante.nota1+estudiante.nota2+estudiante.nota3+estudiante.nota4)/4;
          cout<<estudiante.promedio<<endl;
          

            fwrite(&estudiante,sizeof(Estudiante),1,archivo);
            cout<<"Desea ingresar  otro estudiante";
            cin>>res;

    } while (res=='S' ||res=='s' );
    
    fclose(archivo);
  
}
void Leer(){
    system("cls");
    FILE* archivo = fopen(nombre_archivo,"rb");
    if (!archivo)
    {
        archivo=fopen(nombre_archivo, "w+b");
       }
        Estudiante estudiante;
        int id=0;
        fread(&estudiante,sizeof(Estudiante),1, archivo);
        cout<<"_______________"<<endl;
  
        do
        {
           
        cout<<"ID: "<<id<<endl;
        cout<<"codigo: "<<estudiante.codigo<<endl;
        cout<<"nombre"<<estudiante.nombres<<endl;
        cout<<"apellidos"<<estudiante.apellidos<<endl;
        cout<<"notas: "<<estudiante.nota1<<","<<estudiante.nota2<<","<<estudiante.nota3<<","<<estudiante.nota4<<endl;
        cout<<"promedio : "<<estudiante.promedio<<" resultado : ";
        if (estudiante.promedio>=60)
        {
            cout<<estudiante.resultado1<<endl;
        }else{
             cout<<estudiante.resultado2<<endl;
        }
        
          cout<<"_______________"<<endl;
            fread(&estudiante,sizeof(Estudiante),1, archivo);
            id+=1;
        } while (feof(archivo)==0);
        fclose(archivo);
        

    
       }
       void Actualizar(){
        system("cls");
	
	FILE* archivo = fopen(nombre_archivo,"r+b"); 
	Estudiante estudiante;
	int id=0;
	cout<<"Ingrese el ID que desea Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
		cout<<"ingrese id";
        cin>>estudiante.codigo;
        cin.ignore();
        cout<<"ingrese nombre";
        cin.getline(estudiante.nombres,50);
         cout<<"ingrese Apellido";
        cin.getline(estudiante.apellidos,50);
         cout<<"ingrese nota 1";
         cin>>estudiante.nota1;
           cout<<"ingrese nota 2";
         cin>>estudiante.nota2;
           cout<<"ingrese nota 3";
         cin>>estudiante.nota3;
           cout<<"ingrese nota 4";
         cin>>estudiante.nota4;
          cout<<"Promedio: ";
          estudiante.promedio=(estudiante.nota1+estudiante.nota2+estudiante.nota3+estudiante.nota4)/4;
          cout<<estudiante.promedio<<endl;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	
	
	fclose(archivo);
	Leer();
}
void Borrar(){
    system("cls");
	const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb");
	Estudiante estudiante;
	int id=0,id_n=0;
	cout<<"Ingrese el ID a eliminar:";
	cin>>id;
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
		if (id_n !=id ){
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
		}
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);
	
	archivo_temp = fopen(nombre_archivo_temp,"rb");
	archivo = fopen(nombre_archivo,"wb");
	while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
	}
		fclose(archivo);
	fclose(archivo_temp);
	Leer();
}
