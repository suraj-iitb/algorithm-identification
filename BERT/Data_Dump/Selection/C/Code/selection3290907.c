#include<stdio.h>
void selectionSort(int*, int);
int main(){
    int S[100];
    int s, t, i, j;
    scanf("%d", &s);
    
    for(i=0 ; i<s ; i++){
        scanf("%d", &S[i]);
    }
    
    selectionSort(S, s);
    
    return 0;
}

void selectionSort(int* A,int b){
    int min;
    int cont = 0;
    int change;
    int i, j, flag;
    
    for(i=0 ; i<=b-1 ; i++){
        min = i;
        flag = 0;
        
        for(j=i ; j<=b-1 ; j++){
            if(A[j]<A[min]){
                min = j;
                flag = 1;
            }
        }
        
        if(flag==1){
            cont++;
        }
        
        change = A[i];
        A[i] = A[min];
        A[min] = change;
    }
    
    for(i=0 ; i<b ; i++){
        if(i==b-1){
            printf("%d\n", A[i]);
        }
        else{
            printf("%d ", A[i]);
        }
    }
    
    printf("%d\n", cont);
}
