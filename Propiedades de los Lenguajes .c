#include <stdio.h>

int existe(char elemento, char lenguaje[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        if (lenguaje[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

void unionLenguajes(char lenguajeA[], int tamanioA, char lenguajeU[], int tamanioU) {
    printf("Unión de A y U: {");
    for (int i = 0; i < tamanioA; i++) {
        printf("%c", lenguajeA[i]);
        if (i < tamanioA - 1) {
            printf(", ");
        }
    }
    for (int i = 0; i < tamanioU; i++) {
        if (!existe(lenguajeU[i], lenguajeA, tamanioA)) {
            printf(", %c", lenguajeU[i]);
        }
    }
    printf("}\n");
}

void complemento(char lenguajeA[], int tamanioA, char lenguajeU[], int tamanioU) {
    printf("Complemento de A en U: {");
    int primero = 1;
    for (int i = 0; i < tamanioU; i++) {
        if (!existe(lenguajeU[i], lenguajeA, tamanioA)) {
            if (!primero) {
                printf(", ");
            }
            printf("%c", lenguajeU[i]);
            primero = 0;
        }
    }
    printf("}\n");
}

void interseccion(char *lenguajeA,int tamanioA, char *lenguajeU,int tamanioU){
	int inter[100];      
    int interTam=0;     
	int i,j ;
    for(i=0;i<tamanioA;i++) {
        int encontrado = 0;
        for (j=0;j<tamanioU&&!encontrado;j++){
            if (lenguajeA[i]==lenguajeU[j]) {
                encontrado=1;
            }
        }
        // Si se encontró en ambos conjuntos, verificar si ya está en `inter`
        if(encontrado){
            int existe=0;
            int k;
            for(k=0;k< interTam&&!existe;k++){
                if(inter[k]==lenguajeA[i]) {
                    existe=1;
                }
            }
			if(!existe){
					inter[interTam++]=lenguajeA[i];
				}
        }
    }
	printf("Interseccion de A y U: { ");
	for(i=0;i<interTam;i++){
		printf("%c", inter[i]);
		if(i<interTam-1){
			printf(", ");
		}
    }
    printf(" }\n");
}
	
void diferencia(char *lenguajeA, int tamanioA, char *lenguajeU,int tamanioU){
	printf("Diferencia de A en U: { ");
	int i,j;
	for(i=0;i<tamanioA;i++){
		   int  estaEnLenguajeU=0; 
			for (j=0;j<tamanioU;j++){
				if (lenguajeA[i]==lenguajeU[j]) {
					estaEnLenguajeU=1; 			
				}
				
			}
			if(estaEnLenguajeU==0){
				printf("%c, ",lenguajeU[i]);
			}	
	}	
	printf("}\n");
}	



int main(){
	int opcion, i, j;
    int tamanioA, tamanioU;
	
    printf("--------------------------------\n");
    printf("| Propiedades de los lenguajes |\n");
    printf("--------------------------------\n\n");
    
    do{
		
		printf("Ingrese el tamaño del lenguaje A: ");
		scanf("%d", &tamanioA);
		char lenguajeA[tamanioA]; 

		printf("Ingrese los elementos del lenguaje A (separados por espacios):\n");
		for (int i = 0; i < tamanioA; i++) {
			scanf(" %c", &lenguajeA[i]); 
		}

		printf("Ingrese el tamaño del lenguaje U: ");
		scanf("%d", &tamanioU);
		char lenguajeU[tamanioU];

		printf("Ingrese los elementos del lenguaje U (separados por espacios):\n");
		for (int i = 0; i < tamanioU; i++) {
			scanf(" %c", &lenguajeU[i]);
		}
		
		printf("\nLos lenguajes introducidos son:\n");
		printf("A={");
		for(i=0;i<tamanioA;i++){
			printf("%c ",lenguajeA[i]);
			 if(i<tamanioA-1){
				printf(", ");
			}
		}
		printf("}\n");

		printf("U={");
		for(j=0;j<tamanioU;j++){
			printf("%c ",lenguajeU[j]);
			 if(j<tamanioU-1){
				printf(", ");
			}
		}
		printf("}\n");
		
		do{	
			printf("\nSelecciona la propiedad que deseas usar:\n\n");
			printf("-------------------------\n");
			printf("| Unión ---> 1          |\n");
			printf("| Intersección ---> 2   |\n");
			printf("| Complemento ---> 3     |\n");
			printf("| Diferencia ---> 4      |\n");	
			printf("-------------------------\n\n");
			
			printf("Ingrese su elección | 1 | 2 | 3 | 4 |: ");
			scanf("%d", &opcion);
		
			switch(opcion){
				case 1:
				unionLenguajes(lenguajeA, tamanioA, lenguajeU, tamanioU);
						break;
				case 2:
			    interseccion(lenguajeA, tamanioA, lenguajeU, tamanioU);	
					break;
				case 3:
				complemento(lenguajeA, tamanioA, lenguajeU, tamanioU);
					break;
				case 4:
				diferencia(lenguajeA, tamanioA, lenguajeU, tamanioU);
					break;
				default: printf("Error, esta opción no se encuentra en el menú de propiedades\n");
				}
				printf("\n¿Te gustaría probar otra propiedad? Si->1 No->2\n");
				scanf("%d", &opcion);
			
			}while(opcion!=2);
			printf("\n¿Desearías ingresar nuevos lenguajes? Si->1 No->2\n");
			scanf("%d", &opcion);

    }while(opcion!=2);

    return 0;
}
