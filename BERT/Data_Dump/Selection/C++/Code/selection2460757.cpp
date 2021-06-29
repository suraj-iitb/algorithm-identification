#include <stdio.h>
#include<algorithm>

using namespace std;

static const int N = 100;

void print(int A[], int n) {
    for(int i = 0; i < n; i++) {
        if(i) printf(" ");
        printf("%d", A[i]);
    }
}

int selectionSort(int A[], int n) {
    int i, j, num = 0;

    for(i = 0; i < n; i++) {
        int mini = i;
        for(j = i; j < n; j++) {
           if(A[j] < A[mini]) mini = j;
        }
        if(i != mini) {
            swap(A[i], A[mini]);
            num++;
        }
    }
    return num;
}

int main()
{
    int n, A[N+1];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int num = selectionSort(A, n);
    print(A, n);
    printf("\n%d\n", num);
    return 0;
}
