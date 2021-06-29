#include <stdio.h>

int main(){
    int n, v, N, num[1000], j;

    scanf("%d",&N);
    n=N;
    for(int i=0;;i++){
        if(n==0){
            break;
        }else{
            scanf("%d",&num[i]);
            n=n-1;
        }
    }

    for(int i=1;i<=N;i++){
        for(int k=0;k<=N;k++){
            printf("%d",num[k]);
            if(k==N-1){
                printf("\n");
                break;
            }
            printf(" ");
        }
        v=num[i];
        j=i-1;
        while(j>=0&&num[j]>v){
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=v;
       
    }

}
