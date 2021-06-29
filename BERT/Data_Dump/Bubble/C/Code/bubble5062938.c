#include<stdio.h>
#include<stdlib.h>

void bubblesort(int N, int A[]){
   int i,a,r=0,f;
   for(f=0; f<N-1; f++){
       for(i=N-1; i>f; i--){
           if(A[i]<A[i-1]){
               a=A[i-1];
               A[i-1]=A[i];
               A[i]=a;
               r++;
            }
       }
   }
   for(i=0; i<N ;i++){
       if(i!=0)printf(" ");
       printf("%d", A[i]);
   }
   printf("\n%d\n", r);
}

int main(){
    int N, i;
    int A[100];
    scanf("%d", &N);
    if(N<1 || N>100)exit(1);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
        if(A[i]<0 || A[i]>100)exit(1);
    }
    bubblesort(N, A);
    return 0;
}
