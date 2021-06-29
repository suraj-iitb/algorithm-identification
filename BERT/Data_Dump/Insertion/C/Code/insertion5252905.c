#include<stdio.h>

int main(void){
    int i,j,k,n,v;
    int A[100];
    scanf("%d", &n); 
    if((1 <= n) && (n <= 100)){
        for(i = 1; i <= n; i++){
            scanf("%d", &A[i]);
            }

        for(j = 1; j <= n; j++){
            v = A[j];
            i = j - 1;
            while((i > 0) && (A[i] > v)){
                A[i + 1] = A[i];
                i--;
            }
            A[i + 1] = v;
            for(k = 1; k <= n; k++){
                if(k == n){
                    printf("%d\n", A[k]);
                }else{
                    printf("%d ", A[k]);
                }
            }
        }
    }else{
        printf("エラー:1～100の値を入力してください");
    }
    
    return 0;
}

