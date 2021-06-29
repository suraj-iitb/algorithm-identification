#include<stdio.h>
int main(){
    int N,i,j,v,w;
    scanf("%d",&N);
    int A[N];
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<N;i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(w=0;w<N;w++){
            printf("%d",A[w]);
            if(w<N-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
