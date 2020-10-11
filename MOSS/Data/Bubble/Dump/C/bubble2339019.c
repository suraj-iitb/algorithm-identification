#include<stdio.h>
int main(){
    int i,j,k,tmp,N,a[128],b=0;
    scanf("%d",&N);

    for(k = 0;k < N;k++){
        scanf("%d",&a[k]);
    }

    for(i = 0;i < N;i++){
        for(j = 0;j < N-1;j++){
            if(a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                b++;
            }
        }
    }

    for(k = 0;k < N-1;k++){
        printf("%d ",a[k]);
    }
    printf("%d\n",a[N-1]);
    printf("%d\n",b);
    return 0;
}
