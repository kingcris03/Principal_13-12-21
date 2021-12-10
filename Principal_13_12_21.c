#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int in_relativo();
int in_lecturabase1();
int in_contbase1();
int in_fact_1();
float fl_rr(float a, float b, float c, float d);
int in_manual();
int in_arch_cont_i(char * archivo);
int in_baselectura_cancer();
int in_base_cancer_lectura(char * archivo);
int pregunta(char *texto, char *archivo);
int main(){
	int opc;
	char c_opc;
	
	do{
		printf("\n                                1. Comparacion de factores \n");
		printf("                                2. Calculo acumulativo de riesgo relativo \n");
		printf("                                3. Ver estadisticas de riesgo relativo \n");
		printf("                                4. Manual de usuario \n");
		printf("                                5. Salir \n");
		scanf("%i", &opc);
		switch(opc){
			case 1: 
			in_baselectura_cancer();
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
			in_manual();
			break;	
			case 5: 
			printf("Usted ha salido del programa \n");
			break;
			default:
			printf("No se ha tecleado ninguna opcion valida");
		}
	}while(opc != 5 );
	
	
	
	
	
	return 0;
}
//Esta función mostrará el manual de usuario 
int in_manual(){
	FILE * arch;
	arch = fopen("Manual.txt", "rb"); 
	if(arch==NULL){
		printf("No se ha encontrado ningun archivo en la carpeta");
		return 1;
	}
	
	char caracter;
	while (feof(arch) == 0){
		caracter = fgetc(arch);
		printf("%c", caracter);
	}
	fclose(arch);
	printf("Se ha leido correctamente");
	

}
int in_relativo(){
	FILE * flujo = fopen("base_1.txt", "ab");
	if(flujo == NULL){
		printf("No se ha encontrado el archivo");
		
	}
	else{
		int i;
		char ans;
		printf("Usted padece cancer?  ");
		for(i=0; i<=1; i++){
		//	printf("Usted padece cancer?  ");
			scanf("%c", &ans);
			if(ans == 's' || ans== 'S' ){
				fputs("Si\n", flujo);
			}
			else if(ans == 'n' || ans== 'N' ){
				fputs("No\n", flujo);
			}
		}
		fflush(flujo);
		fclose(flujo);
		printf("EXITO !!!\n");
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
	char archivo_2[]="base_2.txt";
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
	char archivo2[]="base_2.txt";
	char archivo3[]="base_3.txt";
	char archivo4[]="base_4.txt";
	char archivo5[]="base_5.txt";
	char archivo6[]="base_6.txt";
	char archivo7[]="base_7.txt";
	char archivo8[]="base_8.txt";
	char texto_1[]="Fuma? ";
	char texto_2[]="Algun familiar suyo ha padecido de cancer de cualquier tipo?  ";
	char texto_3[]="Ha sido diagnosticado de COVID-19 ultimamente?  ";
	char texto_4[]="Acostumbra estar bajo los rayos UV provenietes del sol durante más de 6 horas seguidas?  ";
	char texto_5[]="Ha sido infectado alguna vez en su vida por la bacteria Helicobacter Pylori?  ";
	char texto_6[]="Sufre de sobrepeso u obesidad?  ";
	char texto_7[]="Tiene más de 30 años cumplidos  ";
    pregunta(texto_1,archivo2);
    pregunta(texto_2,archivo3);
    pregunta(texto_3,archivo4);
    pregunta(texto_4,archivo5);
    pregunta(texto_5,archivo6);
    pregunta(texto_6,archivo7);
    pregunta(texto_7,archivo8);
}

float fl_rr(float a, float b, float c, float d){
	float fl_ex, fl_nex;
	fl_ex = a/(a+b);
	fl_nex = c/(c+d);
	float rr = fl_ex / fl_nex;
	return rr;
	
}

int in_arch_cont_i(char * archivo){
	FILE * arch_cont=fopen("base_1.txt", "rb");
	fseek(arch_cont, 0, SEEK_END);
	int num_elementos = ftell(arch_cont);
	int i, in_sic = 0, in_noc = 0;
	rewind(arch_cont);
	
	char * cadena = (char *) calloc(sizeof(char), num_elementos);
	if(cadena == NULL){
		printf("Error en reservacion de memoria");
		return 2;
	}
	int num_elementos_leidos = fread(cadena, sizeof(char), num_elementos, arch_cont);
	if(num_elementos_leidos != num_elementos){
		printf("Error leyendo el archivo");
		return 3;
	}
	
	for(i=0; i<num_elementos; i+=3){
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
	if(cadena_i[i]== 'N' && cadena[i] == 'S'){
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
	float rr = fl_rr(in_ci, in_sinci, in_nci, in_nonci);
	printf("%i %i %i %i %.3f", in_nci, in_ci, in_sinci, in_nonci, rr);
	free(cadena_i);
	fclose(arch_cont_i);
	free(cadena);
	fclose(arch_cont);
	printf("\nSe han leido los archivos correctamente\n");
	
	
	return 6;
	
}

int in_baselectura_cancer(){
	char archivo_c_1[]="base_mama.txt";
	char archivo_c_2[]="base_pulmon.txt";
	char archivo_c_3[]="base_piel.txt";
	int opc_2;
	char c_opc_2;
	
	do{
		printf("\n                                1. Ver factores de riesgo de cancer de mama \n");
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
int pregunta(char *texto, char *archivo){
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



