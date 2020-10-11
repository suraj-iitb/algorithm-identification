#include<stdio.h>
#define MAX 100

int N,A[MAX];

void print(){
    int i;
    for(i=0;i<N;i++){
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

void sort(){
    int j,i,val;
    for(i=1;i<N;i++){
        val=A[i];
        j=i-1;
        while((j>=0)&&(A[j]>val)){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=val;
        print();
        }
    }
    
int main(void){
    int i,j;
    
    scanf("%d",&N);
    for(i=0;i<N;i++){
     scanf("%d",&A[i]);
    }
    print();
    sort();
    
    return 0;
}    
