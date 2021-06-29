#include <stdio.h>

int kota(int A[],int h,int haku){
    int j=0;
    A[h]=haku;
    while(A[j]!=haku)j++;
    return j!=h;
}

int main(){
    int j,h,A[100000+1],q,haku,man=0;
    
    scanf("%d",&h);
    for(j=0;j<h;j++){
        scanf("%d",&A[j]);
    }
    scanf("%d",&q);
    for(j=0;j<q;j++){
        scanf("%d",&haku);
        if(kota(A,h,haku))man++;
    }
    printf("%d\n",man);
    return 0;
}
