#include<stdio.h>

int main(){
    int a,n[100],i,j,haku=0,tmp,kota=0;
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",&n[i]);
    }
    haku=1;
    while(haku){
        haku=0;
        for(j=1;j<=a-1;j++){
            if(n[j]<n[j-1]){
                tmp=n[j];
                n[j]=n[j-1];
                n[j-1]=tmp;
                kota++;
                haku=1;
            }
        }
    }
    for(i=0;i<a;i++){
        if(i){
            printf(" ");
        }
        printf("%d",n[i]);
    }
    printf("\n%d\n",kota);
    return 0;
}
