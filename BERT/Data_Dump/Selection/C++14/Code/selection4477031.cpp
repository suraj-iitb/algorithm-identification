#include <iostream>
using namespace std;
int selectionsort(int A[],int N){
    int sw =0;
    int minj;

    for (int i =0;i<N-1;i++){
        minj =i;
        for(int j=i;j<N;j++){
            if(A[j]<A[minj])
                minj = j;
                
            }
             swap(A[i],A[minj]);
            if(i!=minj)
                sw++;
                
            
        }
    
    return sw;
    
}
int main(){
    int A[100],N,i,sw;
    
    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);
    sw = selectionsort(A,N);
    for(int i =0;i<N;i++){
        if(i>0) printf(" ");
        printf("%d",A[i]);
        
    }
    printf("\n");
    printf("%d\n",sw);
    return 0;
    
}
