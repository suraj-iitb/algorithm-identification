#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,s,i,j;
    int *retu;
    
    scanf("%d",&a);
    retu=(int *)malloc(a * sizeof(int));
    for(i=0;i<a;i++){
        scanf("%d",&retu[i]);
    }
    for(i=0;i<a;i++){
        s=retu[i];
        j=i-1;
        while(retu[j]>s && j>=0){
            retu[j+1]=retu[j];
            j--;
        }
	retu[j+1]=s;
	for(j=0;j<a;j++){
        printf("%d",retu[j]);
	if(j!=a-1)printf(" ");}
	printf("\n");
    }
}

