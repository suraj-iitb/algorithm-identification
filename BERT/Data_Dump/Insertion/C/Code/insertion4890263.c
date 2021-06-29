#include<stdio.h>
int main(){
    int i,j,N,a[100],k;
    scanf("%d",&N);
    for(i = 0; i < N; i++){
        scanf("%d",&a[i]);
    }
    for(i = 0; i < N; i++){
        k = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > k){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
        for(j = 0; j < N; j++){
            printf("%d",a[j]);
            if(j != N - 1) {
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
    return 0;
}
