#include<stdio.h>
#include<stdlib.h>
/*
int maxi(FILE *F){
    int n;
    int max,i;
    fscanf(F,"%d",&max);
    while(fscanf(F,"%d",&n) != EOF){
        if(n>max)max = n;
    }
    return max;
}
*/
/*
void delete(FILE *F,int max){
    while
}
*/
int main(){
    FILE *F = fopen("F.dat","wb");
    int n,k,i;
    printf("donnz le nombre des integet");
    scanf("%d",&n);
    for(i = 0;i<n;i++){
        printf("donnez le %d eme nombre: ",i+1);
        scanf("%d",&k);
        fprintf(F,"%d ",k);
    }
    fclose(F);
    int T[n];
    F = fopen("F.dat","rb");
    for(i = 0;i<n;i++){
        fscanf(F,"%d",&T[i]);
    }
    rewind(F);
    int j;
    for(i = 0;i<n;i++){
        printf("%d\n",T[i]);
    }
    for(i = 0;i<n-1;i++){
        for(j = i+1;j<n;j++){
        if(T[i]<T[j]){
            k = T[i];
            T[i] = T[j];
            T[j] = k;
        }
    }
    }
       for(i = 0;i<n;i++){
        printf("\n%d\n",T[i]);
    }
    FILE *Ftri = fopen("Ftri.dat","wb");
    for(i = 0 ; i<n ; i++){
        fprintf(Ftri,"%d ",T[i]);
    }
    fclose(Ftri);
    char c;
    Ftri = fopen("Ftri.dat","rb");
    while((c = fgetc(Ftri)) != EOF){
        printf("%c",c);
    }
    fclose(Ftri);
}
