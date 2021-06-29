#include<stdio.h>
#include<stdlib.h>

void Countingsort(int*,int);

int B[10000];

#define MAX 2000000

int main(){

    int n,i,A[MAX];

    scanf("%d",&n);

    if(n > MAX)exit(0);

    for(i = 0;i < n;i++){

        scanf("%d",&A[i]);
    }

    Countingsort(A,n);

    

    return 0;
}

void Countingsort(int A[],int k){

    int i,C[MAX],j,B[MAX];

    for(i = 0;i<MAX;i++){

        C[i] = 0;

    }

    for(j = 0;j < k;j++){

        C[A[j]]++;
    }

    

    for(i = 1;i < MAX;i++){

        C[i] = C[i] + C[i - 1];

    }
    /*for(j = 0;j < k;j++){

        printf("%d ",C[j]);

    }

    printf("\n");*/

    

    for(j = k-1;j >= 0;j--){

        B[C[A[j]]] = A[j];

        C[A[j]]--;
    }

    for(j = 1;j <= k;j++){

        if(j == k){

            printf("%d\n",B[j]);

        }

        else{

            printf("%d ",B[j]);

        }

        

    }

   

    

    
}
