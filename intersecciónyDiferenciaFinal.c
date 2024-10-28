

#include <stdio.h>
void interseccion(int *conjunto,int *conjunto2,int tam1,int tam2);
void diferencia(int *conjunto,int *conjunto2,int tam1,int tam2);

int main(){

	int tam1,tam2;
	int num,num2,i,j;
	printf("Ingrese el tamanio del 1er conjunto:");
	scanf("%d",&tam1);
	int  conjunto[tam1];
	printf("Ingrese el 1er conjunto:");
	for(i=0;i<tam1;i++){
		scanf("%d",&num);
		conjunto[i]=num;	
	}
	printf("Ingrese el tamanio del 2do conjunto:");
	scanf("%d",&tam2);
	printf("Ingrese el 2do conjunto: ");
	int  conjunto2[tam2];
	for(j=0;j<tam2;j++){
		scanf("%d",&num2);
		conjunto2[j]=num2;	
	}

	printf("El primer conjunto es {");
	for(i=0;i<tam1;i++){
		printf("%d ",conjunto[i]);
		 if(i<tam1-1){
            printf(", ");
        }
	}
	 printf("}\n");
	 printf("El segundo conjunto es {");
	for(j=0;j<tam2;j++){
		printf("%d ",conjunto2[j]);
		 if(j<tam2-1){
            printf(", ");
        }
	}
	 printf("}");
	 printf("\n");
	 interseccion(conjunto,conjunto2,tam1,tam2);
	 printf("\n");
	 diferencia(conjunto,conjunto2,tam1,tam2);
	 
	return 0;
}
void interseccion(int *conjunto,int *conjunto2,int tam1,int tam2){
	int inter[100];      
    int interTam=0;     
	int i,j ;
    for(i=0;i<tam1;i++) {
        int encontrado = 0;
        for (j=0;j<tam2&&!encontrado;j++){
            if (conjunto[i]==conjunto2[j]) {
                encontrado=1;
            }
        }
        // Si se encontró en ambos conjuntos, verificar si ya está en `inter`
        if(encontrado){
            int existe=0;
            int k;
            for(k=0;k< interTam&&!existe;k++){
                if(inter[k]==conjunto[i]) {
                    existe=1;
                }
            }
			if(!existe){
					inter[interTam++]=conjunto[i];
				}
        }
    }
	printf("Interseccion { ");
	for(i=0;i<interTam;i++){
		printf("%d", inter[i]);
		if(i<interTam-1){
			printf(", ");
		}
    }
    printf(" }\n");
}
	
void diferencia(int *conjunto,int *conjunto2,int tam1,int tam2){
	printf("Diferencia { ");
	int i,j;
	for(i=0;i<tam1;i++){
		   int  estaEnConjunto2=0; 
			for (j=0;j<tam2;j++){
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

