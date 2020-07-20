#include <cstdio>
using namespace std;

int bubblesort(int A[], int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            if(A[j] < A[j-1]){
                int t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    int count = bubblesort(A,n);
    for(int i = 0; i < n; i++){
        printf("%d",A[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf("\n%d\n",count);
}
