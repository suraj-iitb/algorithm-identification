#include <stdio.h>
//#include <assert.h>

#define N 110
#define INPUT_MAX 1000

void print_array(int A[], int n);

void insertionSort(int A[], int n);

int main (void){

    int A[N];

    int n;
    //fprintf(stderr, "要素数>>>");
    scanf("%d", &n);
    //assert(1 <= n && n <= 100);

    for(int i = 0; i < n; i++){

        int input;

        //fprintf(stderr, "A[%d] = ", i);
        scanf("%d", &input);
        A[i] = input;
        //assert(0 <= A[i] && A[i] <= INPUT_MAX);

    }

    insertionSort(A, n);


    return 0;

}

void print_array(int A[], int n){

    for(int i = 0; i < n-1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n", A[n-1]);


}

void insertionSort(int A[], int n){

    for(int i = 1; i < n; i++){
        print_array(A, n);
        


        int v = A[i];
        int j = i - 1;

        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
    }

    print_array(A, n);
}
