#include<stdio.h>
#include<stdlib.h>
	typedef struct{
			float nbr;
		}Nombres;
int main()
{
	FILE *f;
	f = fopen("nombre.bin","wb");
	float som = 0;
	float moy;
	int i;
	
	Nombres n[5];
	for(i = 0; i < 5; i++){
		printf("Donnez les nombres: ");
		scanf("%f",&n[i].nbr);
		//som = som + n[i].nbr;
	}
	fwrite(n,sizeof(Nombres),5,f);
	fclose(f);
	
	fopen("nombre.bin","rb");
	/*Nombres n1[5];
	fread(n1,sizeof(Nombres),5,f);
	for(i = 0;i < 5; i++){
		printf("les nombres %f\n",n1[i].nbr);
		som += n1[i].nbr;
	}*/
	Nombres n1;
	
	while(fread(&n1, sizeof(Nombres), 1, f))
	{
		printf("%f\n", n1.nbr);
		som += n1.nbr;	
	}
	
	fclose(f);
	
	moy = som / 5;
	printf("la sommet : %f\n",som);
	printf("la moyenne : %f",moy);
	return 0;
}
