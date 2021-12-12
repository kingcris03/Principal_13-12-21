#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int in_relativo();       //Esta función guardará los datos ingresados por el usuario en una primera instancia y los datos guardados servirán como primer filtro en la organización de la información 
int in_lecturabase1();   
int in_contbase1();      // Es la función principal del programa puesto que hará lectura y escritura en la base(s) de datos, abriendo los archivos correspondientes y hacer un conteo cada vez que se ingresen nuevos valores
int in_fact_1();          //Subfunción de la función principal que hará la lectura y escritura de los datos almacenados por los usuarios realizando a su vez la pregunta correspondiente a este ultimo dependiendo del archivo abierto 
float fl_rr(float a, float b, float c, float d);  //Función que hará el labor de procesar todos los datos ingresados por los usuarios regresando como salida los un valor númerico
int in_manual();  //Función que unicamente hará lectura del manual de usuario el cual dará indicaciones a este ultimo para saber como utlizar y guardar la información ingresada por este mismo
int in_arch_cont_i(char * archivo);  //Realizará la lectura y conteo correspondiente a la base de datos de los factores de riesgo analizados
int in_baselectura_cancer(); //Siendo una función secundaria, solo hará lectura de la base de datos de lectura donde estan almacenados los factores de riesgo de algunos tipos de cáncer
int in_base_cancer_lectura(char * archivo);  //Función que esta empaquetada en la anterior y complento de la misma, la cual abrirá el archivo que el usuario indique para ser pmostrado en pantalla
int pregunta(char *texto, char *archivo);  //Esta función esta empaquetada dentro una función que asu vez esta empaquetada en la funión principal, la cual abrirá el archivo donde se va a hacer la escritura de la base de datos
//ademas de preguntar las preguntas correspondientes a los factores especificados a analizar
int main(){
	int opc;
	char c_opc;
	
	do{
		printf("\n                                1. Comparacion de factores \n");
		printf("                                2. Calculo acumulativo de riesgo relativo \n");                //Dentro de la función main se irán llamando las demas funciones a partir de un menu realizado con do-while y switch-case
		printf("                                3. Ver estadisticas de riesgo relativo \n");
		printf("                                4. Manual de usuario \n");
		printf("                                5. Salir \n");
		scanf("%i", &opc);
		switch(opc){
			case 1: 
			in_baselectura_cancer();  //Se manda a llmar la función in_baselectura_cancer para que haga lectura de la base de datos que contiene los factores de riesgo de algunos tipos de cancer
			break;
			case 2:     
		    in_relativo();
		    in_fact_1();
		    in_contbase1();
		    system("cls");
			break;
			case 3: 
			in_contbase1();
			break;
			case 4: 
			in_manual();  //Manda a llamar el manual para guiar a los usuarios
			break;	
			case 5: 
			printf("Usted ha salido del programa \n");   //Finaliza el programa
			break;
			default:
			printf("No se ha tecleado ninguna opcion valida");   //En el caso de que no se halla tecleado nu¿inguna opcion del switch-case se imprime el texto "No se ha teclado ninguna opción valida"		    
		}
	}while(opc != 5 );  //El ciclo se repite siempre y cuando se ´presiona la tecla con el número 5
	
	
	
	
	
	return 0;
}
//Esta función mostrará el manual de usuario el cual esta contenido en un archivo de texto llamado "Manual.txt"
int in_manual(){
	FILE * arch;
	arch = fopen("Manual.txt", "rb"); //Se abre el archivo
	if(arch==NULL){                                         //Si no se encuentra retornará un texto en el cual se mencione que on se ha encontrado ningun aarchivo y el número 1
		printf("No se ha encontrado ningun archivo en la carpeta");
		return 1;
	}
	
	char caracter;   //De lo contrario se mostrarán en pantalla el contenido del archvo "manual.txt"
	while (feof(arch) == 0){
		caracter = fgetc(arch);
		printf("%c", caracter);
	}
	fclose(arch);       //Se cierra el archivo
	printf("Se ha leido correctamente");   //Si todo ha salido bien se imprime "Se ha leído correctamente"
	

}
int in_relativo(){
	FILE * flujo = fopen("base_1.txt", "ab");  //Se abre el archivo
	if(flujo == NULL){
		printf("No se ha encontrado el archivo");
		
	}
	else{
		int i;
		char ans;
		printf("Usted padece cancer?  ");  //Se pregunta al usuario si tiene cancer o no
		for(i=0; i<=1; i++){                 //Dentro del archivo se irán guardando los datos en una matriz la cual solo tendra una columna
		//	printf("Usted padece cancer?  ");
			scanf("%c", &ans);  //Se guarda la respuesta ingresada por el usuario
			if(ans == 's' || ans== 'S' ){
				fputs("Si\n", flujo);  //Si la respuesta es 's' ó 'S' en el archivo abierto se imprimen "Si"
			}
			else if(ans == 'n' || ans== 'N' ){  //Por el contrario si la respuesta es 'n' ó 'N' en el archivo abierto se imprimen "No"
				fputs("No\n", flujo);
			}
		}
		fflush(flujo);  //Elimina el buffer en el caso de que se hayan quedado datos guardados
		fclose(flujo);  //Se cierra el programa
		printf("EXITO !!!\n");  //Si e proceso se ha realizado correctamente se muestra en pantalla "EXITO"
	}
}

int in_lecturabase1(){
	FILE * arch_r=fopen("base_1.txt", "rb");
	if(arch_r == NULL){
		printf("No se ha encontrado el archivo \n");
		return 1;
		
	}
	else{
	char cadena[2];
	while(feof(arch_r) == 0){
		fscanf(arch_r, "%s", &cadena);
		printf("%s\n", cadena);
	}
    }
	fclose(arch_r);
	printf("Se ha leido el archivo exitosamente\n");
}
int in_contbase1(){
	char archivo_2[]="base_2.txt";  //Se define a la variable aarchivo_i[] para almacenar el texto que se guardará en la función in_arch_cont_i(archivo_i)
	char archivo_3[]="base_3.txt";  
	char archivo_4[]="base_4.txt";  
	char archivo_5[]="base_5.txt";  
	char archivo_6[]="base_6.txt";
	char archivo_7[]="base_7.txt";
	char archivo_8[]="base_8.txt";
	in_arch_cont_i(archivo_2);
	in_arch_cont_i(archivo_3);
	in_arch_cont_i(archivo_4);
	in_arch_cont_i(archivo_5);
	in_arch_cont_i(archivo_6);
	in_arch_cont_i(archivo_7);
	in_arch_cont_i(archivo_8);
	
	
	return 6;

}
int in_fact_1(){
	char archivo2[]="base_2.txt";  //Se guarda el texto que se utilizará para abrir el archivo de base de datos 
	char archivo3[]="base_3.txt";
	char archivo4[]="base_4.txt";
	char archivo5[]="base_5.txt";
	char archivo6[]="base_6.txt";
	char archivo7[]="base_7.txt";
	char archivo8[]="base_8.txt";
	char texto_1[]="Fuma? ";
	char texto_2[]="Algun familiar suyo ha padecido de cancer de cualquier tipo?  ";  //Se realizará la pregunta que acompañara de la base de datos abierta
	char texto_3[]="Ha sido diagnosticado de COVID-19 ultimamente?  ";
	char texto_4[]="Acostumbra estar bajo los rayos UV provenietes del sol durante más de 6 horas seguidas?  ";
	char texto_5[]="Ha sido infectado alguna vez en su vida por la bacteria Helicobacter Pylori?  ";
	char texto_6[]="Sufre de sobrepeso u obesidad?  ";
	char texto_7[]="Tiene más de 30 años cumplidos  ";
    pregunta(texto_1,archivo2);                       //Procesará la pregunta con la base de datos en la cual se relacionarán
    pregunta(texto_2,archivo3);
    pregunta(texto_3,archivo4);
    pregunta(texto_4,archivo5);
    pregunta(texto_5,archivo6);
    pregunta(texto_6,archivo7);
    pregunta(texto_7,archivo8);
}

float fl_rr(float a, float b, float c, float d){
	float fl_ex, fl_nex;  //Se definen dos variable de tipo flotante con la finalidad de realizar una operación matematica que analizará los datos ingresados por el usuario
	fl_ex = a/(a+b);
	fl_nex = c/(c+d);
	float rr = fl_ex / fl_nex;
	return rr;
	
}

int in_arch_cont_i(char * archivo){
	FILE * arch_cont=fopen("base_1.txt", "rb");  //Hace lectura en binario de la primer base de datos con la finalidad de utilizar esos datos más adelante
	fseek(arch_cont, 0, SEEK_END);                
	int num_elementos = ftell(arch_cont);
	int i, in_sic = 0, in_noc = 0;  
	rewind(arch_cont);
	
	char * cadena = (char *) calloc(sizeof(char), num_elementos);  //Se reserva espacio en la memoria para almacenar los datos de la base de datos
	if(cadena == NULL){
		printf("Error en reservacion de memoria");
		return 2;
	}
	int num_elementos_leidos = fread(cadena, sizeof(char), num_elementos, arch_cont);  //Se realiapa este proceso para leer el archivo adecuadamente
	if(num_elementos_leidos != num_elementos){
		printf("Error leyendo el archivo");
		return 3;
	}
	
	for(i=0; i<num_elementos; i+=3){  //El números de elementos es el triple de los elementos guardados, puesto que cada 'No' y cada 'Si' 
	//guarda dos posiciones en el array, es decir si es un 'Si ' [0], [1] y [2], es S, i, /0, respectivamente, por lo tanto se buscaran las 'S' y las 'N' para hacer el analisis de información e ir guardando en las variables de tipo 
	//entero las camtidades procesadas
	if(cadena[i]== 'S'){
		in_sic++;
	}
	else if(cadena[i] == 'N'){
		in_noc++;
	}
}
	FILE * arch_cont_i=fopen(archivo, "rb");//Lectura de la base i
	fseek(arch_cont_i, 0, SEEK_END);
	int num_elementos_i = ftell(arch_cont_i);
	int  in_ci = 0, in_nci = 0, in_nonci=0, in_sinci=0;
	rewind(arch_cont_i);
	
	char * cadena_i = (char *) calloc(sizeof(char), num_elementos_i);
	if(cadena_i == NULL){
		printf("Error en reservacion de memoria");
		return 4;
	}
	int num_elementos_leidos_i = fread(cadena_i, sizeof(char), num_elementos_i, arch_cont_i);
	if(num_elementos_leidos_i != num_elementos_i){
		printf("Error leyendo el archivo");
		return 5;
	}
	for(i=0; i<num_elementos_i; i+=3){
	if(cadena_i[i]== 'N' && cadena[i] == 'S'){   //Todo lo anterior es el mismo procedimineto que al inicio de la función con la diferencia de que la clasificación de la información es más estricta en cuestion de los requesitos a analizar
		in_nci++;
	}
	else if(cadena_i[i] == 'S' && cadena[i] == 'S'){
		in_ci++;
	}
	else if(cadena_i[i] == 'S' && cadena[i] == 'N'){
		in_sinci++;
	}	
	else if(cadena_i[i] == 'N' && cadena[i] == 'N'){
		in_nonci++;
	}
	}
	float rr = fl_rr(in_ci, in_sinci, in_nci, in_nonci);  //Se ingresan los valores a analizar en la función qye calcula el riesgo relativo de padecer cancer de cada factor 
	printf("%i %i %i %i %.3f", in_nci, in_ci, in_sinci, in_nonci, rr);   //Se imprimen en pantalla todos los valores arrojados y el calculo del Riesgo Relativo
	free(cadena_i);                                          //Se libera la memoria que ocupa el archivo abierto
	fclose(arch_cont_i);
	free(cadena);
	fclose(arch_cont);
	printf("\nSe han leido los archivos correctamente\n");                //Si todo salio como debia, se mostrará en pantalla "Se han leído los archivos Correctamente"
	
	
	return 6;
	
}

int in_baselectura_cancer(){                                   //En esta función se escogerá la base de lectura a abrir asi como su lectura en el programa
	char archivo_c_1[]="base_mama.txt";
	char archivo_c_2[]="base_pulmon.txt";
	char archivo_c_3[]="base_piel.txt";
	int opc_2;
	char c_opc_2;
	
	do{
		printf("\n                                1. Ver factores de riesgo de cancer de mama \n");           //El funcionamiento del submenú es el mismo que el del menú pricipal
		printf("                                2. Ver factores de riesgo de cancer de pulmon \n");
		printf("                                3. Ver factores de riesgo de cancer de piel \n");
		printf("                                4. Salir \n");
		scanf("%i", &opc_2);
		switch(opc_2){
			case 1: 
			in_base_cancer_lectura(archivo_c_1);
			break;
			case 2:     
			in_base_cancer_lectura(archivo_c_2);
			break;
			case 3: 
			in_base_cancer_lectura(archivo_c_3);
			break;
			case 4: 
			printf("Usted ha salido del programa \n");
			break;
			default:
			printf("No se ha tecleado ninguna opcion valida");
		}
	}while(opc_2 != 4 );
}

int in_base_cancer_lectura(char * archivo){
	
	FILE * cancer = fopen (archivo, "r");
	if(cancer == NULL){
		printf("No se ha encontrado el archivo");
		
	}
	
	char buffer[100];
	do{
		if(fgets(buffer, 100, cancer)){
			printf("%s ", buffer);
		}
	}while (!feof(cancer));
	fclose(cancer);
	
}
int pregunta(char *texto, char *archivo){            //Esta función tiene como parametros el texto a imprimir en pantalla, asi como el archivo correspodiente a la pregunta, esta función esta empaquetada en la función principal del código
    FILE * flujo_1 = fopen(archivo, "ab");
	if(flujo_1 == NULL){
		printf("No se ha encontrado el archivo");
	}
	else{
	int i;
    char ans_2;
	printf("%s",texto);
		for(i=0; i<=1; i++){
		//	printf("Usted padece cancer?  ");
			scanf("%c", &ans_2);
			if(ans_2 == 's' || ans_2== 'S' ){
				fputs("Si\n", flujo_1);
			}
			else if(ans_2 == 'n' || ans_2== 'N' ){
				fputs("No\n", flujo_1);
			}
		}
		fflush(flujo_1);
		fclose(flujo_1);
		printf("EXITO !!!\n");
    }
}



