#include<stdio.h>

int main(void){
    int N,b;
    scanf("%d",&N);
    int a[N];
    
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        printf("%d",a[i]);
        if(i<N-1){
            printf(" ");
        }
    }
    printf("\n");
    for(int i=1;i<N;i++){
        for(int t=i;0<t;t--){
            if(a[t-1]>a[t]){
                b=a[t-1];
                a[t-1]=a[t];
                a[t]=b;
            }
        }
        for(int t=0;t<N;t++){
            printf("%d",a[t]);
            if(t<N-1){
                printf(" ");
            }
        }
        printf("\n");
    }    
    return 0;
}
