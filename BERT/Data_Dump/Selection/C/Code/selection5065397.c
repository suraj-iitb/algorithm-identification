#include<stdio.h>
#include<stdlib.h>

int main(){

    int N,i,A[100],minj,j,state=0,cnt=0,cnt2=0;

    scanf("%d",&N);

    if(N < 1 || N > 100)exit(0);

    for(i = 0;i < N;i++){

        scanf("%d",&A[i]);

    }

    for(i = 0;i < N;i++){

        //cnt2 += cnt;

        //printf("%d\n",cnt2);

        //cnt = 0;

        minj = i;

        for(j = i;j < N;j++){

               

            if(A[j] < A[minj]){

                minj = j;

            }
        }

        if(minj != i){

            state = A[i];

            A[i] = A[minj];

            A[minj] = state;

            cnt++;
        }

               

            
        
    }


    for(i = 0;i < N;i++){

        if(i == N-1){

            printf("%d",A[i]);
        }

        else{

            printf("%d ",A[i]);
        }
    }

    printf("\n");

    printf("%d\n",cnt);

    return 0;

}



    

