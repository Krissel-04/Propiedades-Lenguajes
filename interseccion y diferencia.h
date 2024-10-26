#include <stdio.h>

void interseccion(int *conjunto,int *conjunto2){
	printf("Interseccion de A y U: { ");
	int i,j;
		for(i=0;i<4;i++){
			for(j=0;j<8;j++){
				if (conjunto[i]==conjunto2[j]){
					printf("%d, ",conjunto[i]);			
				}
			}
		}	
	printf("}\n");
		
}	 
void diferencia(int *conjunto,int *conjunto2){
	printf("Diferencia de A y U: { ");
	int i,j;
	for(i=0;i<4;i++){
		   int  estaEnConjunto2=0; 
			for (j=0;j<8;j++){
				if (conjunto[i]==conjunto2[j]) {
					estaEnConjunto2=1; 			
				}
				
			}
			if(estaEnConjunto2==0){
				printf("%d, ",conjunto[i]);
			}	
	}	
	printf("}\n");
}		
