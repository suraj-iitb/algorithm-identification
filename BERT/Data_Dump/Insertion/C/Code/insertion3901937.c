#include <stdio.h>
int main (){

    int i, j, k, v, N;
    int A[1000]={0};

    scanf("%d",&N);
    for(i=0;i <= N-1; i++){
        scanf("%d",&A[i]);//"%d "のスペースが問題だった
    }
    
    //printf("test1");
    for(i=1; i<=N; i++){
        for(k=0; k<N-1; k++){
            printf("%d ",A[k]);
        }
        printf("%d\n",A[N-1]);
        
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
            //if(j < 0 && A[j] <= v) break;
        }
        A[j+1] = v;
        
    }

return 0;
}
