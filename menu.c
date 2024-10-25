#include <stdio.h>
#include "union y complemento.h"
#include "interseccion y diferencia.h"

int main(){
	int opcion;		
	int conjuntoA[] = {1, 3, 5, 7};
	int conjuntoU[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int tamanioA = sizeof(conjuntoA) / sizeof(conjuntoA[0]);
    int tamanioU = sizeof(conjuntoU) / sizeof(conjuntoU[0]);
    int conjunto[]={1,3,5,7};
	int conjunto2[]={1,2,3,4,5,6,7,8};
	
	printf("Propiedades de los lenguajes\n\n");
	printf("Dado A={1,3,5,7} y U={1,2,3,4,5,6,7,8}\n\n");
	printf("Selecciona la propiedad que deseas usar:\n\n");
	printf("-------------------------\n");
	printf("| Union ---> 1          |\n");
	printf("| Interseccion ---> 2   |\n");
	printf("| Complemento ---> 3    |\n");
	printf("| Diferencia ---> 4     |\n");	
	printf("|                       |\n");
	printf("| Salir ---> 5          |\n");
	printf("-------------------------\n");
	
	do{
	scanf("%d", &opcion);
	switch(opcion){
		case 1:
		unionConjuntos(conjuntoA, tamanioA, conjuntoU, tamanioU);
				break;
		case 2:
		interseccion(conjunto, conjunto2);
			break;
		case 3:
		complemento(conjuntoA, tamanioA, conjuntoU, tamanioU);	
			break;
		case 4:
		diferencia(conjunto, conjunto2);
			break;
		case 5:
			return 0;
		default: printf("Error, esta opcion no se encuentra en el menu de propiedades\n");
		}
		
	}while(opcion>=1);
	
    return 0;
}
