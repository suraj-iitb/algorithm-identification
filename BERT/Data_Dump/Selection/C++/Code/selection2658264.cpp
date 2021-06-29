#include <iostream>
#include <cstdio>
using namespace std;

int selectionSort(int A[],int N) {
    int sw=0;
    for (int i=0; i<N-1; i++) {
        int minj=i;
        for (int j=i; j<N; j++) {
            if (A[j]<A[minj]) {
                minj=j;
            }
        }
        int t=A[i];
        A[i]=A[minj];
        A[minj]=t;
        if (i!=minj) {
            sw++;
        }
    }
    return sw;
}
int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    int sw=selectionSort(A,N);
    for (int i=0; i<N; i++) {
        printf("%s%d",((i==0)?"":" "),A[i]);
    }
    printf("\n");
    printf("%d\n",sw);
    return 0;
}
