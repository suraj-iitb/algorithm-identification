//ALDS1_1_A


#include<iostream>
using namespace std;

int trace(int A[], int N){
        int i;
        for (i=0; i < N; i++){
            if( i > 0 ) printf(" "); //隣接する要素の間に一つの空白を入力
            printf( "%d", A[i]);
        }
        printf("\n");
    }
    
/* Insertion Sort 
1 insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 1 から N-1 まで
3     v = A[i]4     j = i - 1
5     while j >= 0 かつ A[j] > v
6       A[j+1] = A[j]
7       j--
8     A[j+1] = v
*/
int IS(int A[], int N){
    int j, i, v;
    for(i = 1; i < N; i++){
        v = A[i];
        j = i - 1;
        while (j >= 0 and A[j] > v){
            A[j + 1] = A[j];
            j --;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}
    
int main(void){
    int N, i, j;
    int A[100];
    
    scanf("%d", &N);
    for(i = 0; i < N; i++ ) scanf("%d", &A[i]);
    
    trace(A, N);
    IS(A, N);
    
    return 0;
}

