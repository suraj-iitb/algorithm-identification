#include <cstdio>

void print(int A[],int n){
    for(int i = 0; i < n; i++){
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void insert_sort(int A[],int max){
    for(int i = max; i >= 1; i--){
        if(A[i]<A[i-1]){
            int t = A[i];
            A[i] = A[i-1];
            A[i-1] = t;
        } else {
            break;
        }
    }
}

int main(){
    int A[100], n;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    
    for(int i = 0; i < n; i++){
        insert_sort(A, i);
        print(A, n);
    }
    
    return 0;
}

