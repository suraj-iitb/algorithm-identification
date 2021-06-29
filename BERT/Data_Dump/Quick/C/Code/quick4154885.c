

#include<stdio.h>

char N[100000];
int A[100000];
int B[100000];

int partition(int p, int r){
    int x = A[B[r-1]];
    int i = p;
    for(int j = p; j < r - 1; j++){
        if(A[B[j]] <= x){
            int temp = B[i];
            B[i] = B[j];
            B[j] = temp;
            i++;
        }
    }
    int temp = B[i];
    B[i] = B[r-1];
    B[r-1] = temp;
    return i;
}

void quicksort(int p, int r){
    if(r - p >= 2){
        int q = partition(p, r);
        quicksort(p, q);
        quicksort(q+1, r);
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        getchar();
        scanf("%c", &N[i]);
        scanf("%d", &A[i]);
        B[i] = i;
    }
    quicksort(0, n);
    int m = A[B[0]];
    int stable = 1;
    for(int i=1; i<n; i++){
        if(A[B[i-1]] == A[B[i]] && B[i-1] > B[i])
            stable = 0;
    }
    puts(stable ? "Stable" : "Not stable");
    for(int i=0; i<n; i++)
        printf("%c %d\n", N[B[i]], A[B[i]]);
}

