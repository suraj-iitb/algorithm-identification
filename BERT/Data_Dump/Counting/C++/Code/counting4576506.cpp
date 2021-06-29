#include <bits/stdc++.h>
using namespace std;

#define MAX 2000001
#define VMAX 10000

int main(){
    unsigned short *A,*B;
    int C[VMAX+1]={0};

    int n,i,j;
    
    scanf("%d",&n);

    A=(short unsigned int*)malloc(sizeof(short)*n+1);
    B=(short unsigned int*)malloc(sizeof(short)*n+1);

    for(i=0;i<n;i++){
        scanf("%hu",&A[i+1]);
        C[A[i+1]]++;
    }

    for(i=1;i<=VMAX;i++){
        C[i]=C[i]+C[i-1];
    }

    for(i=n;i>0;i--){
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }

    for(i=1;i<=n;i++){
        if(i>1)printf(" ");
        printf("%d",B[i]);
    }
    printf("\n");
    
    return 0;
}
