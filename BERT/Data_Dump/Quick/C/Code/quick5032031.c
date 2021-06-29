#include<stdio.h>

char S[100000];
int A[100000];
int I[100000];

int partition(int p, int r){
    int x = A[I[r-1]];
    int i = p;
    for(int j = p; j < r - 1; j++){
        if(A[I[j]] <= x){
            int temp = I[i];
            I[i] = I[j];
            I[j] = temp;
            i++;
        }
    }
    int temp = I[i];
    I[i] = I[r-1];
    I[r-1] = temp;
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
        scanf("%c %d", &S[i], &A[i]);
        I[i] = i;
    }
    quicksort(0, n);
    int m = A[I[0]];
    int stable = 1;
    for(int i=1; i<n; i++){
        if(A[I[i-1]] == A[I[i]] && I[i-1] > I[i])
            stable = 0;
    }
    puts(stable ? "Stable" : "Not stable");
    for(int i=0; i<n; i++)
        printf("%c %d\n", S[I[i]], A[I[i]]);
}


