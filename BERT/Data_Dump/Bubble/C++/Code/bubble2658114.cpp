#include <iostream>
#include <cstdio>
using namespace std;

int bubbleSort(int A[],int N) {
    int sw=0;
    bool f=true;
    for (int i=0; f; i++) {
        f=false;
        for (int j=N-1; j>=i; j--) {
            if (A[j]<A[j-1]) {
                swap(A[j],A[j-1]);
                f=true;
                sw++;
            }
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
    int sw=bubbleSort(A,N);
    for (int i=0; i<N; i++) {
        printf("%s%d",((i==0)?"":" "),A[i]);
    }
    printf("\n");
    printf("%d\n",sw);
    return 0;
}
