#include <iostream>
#include <stdio.h>
using namespace std;

void selectionSort(int array[],int N,int& change_count) {
    int i, j;
    int swapCount = 0;
    int mini=0;
    for (i = 0; i < N - 1; i++) {
        mini = i;
        for (j = i+1; j < N; j++) {
            if (array[j] < array[mini]) {
                mini = j;
               
            }
        }
        if (i != mini) {
            swap(array[i], array[mini]);
            change_count++;
        }

    }
}

int main() {
    int N;
    int* a;
    int change_count = 0;
    cin >> N;
    a = new int[N];

    for (int i = 0; i < N; i++) cin >> a[i];

    selectionSort(a,N,change_count);
    for (int i = 0; i < N; i++) {
        if (i != N - 1) {
            printf("%d ", a[i]);
        }
        else {
            printf("%d\n", a[i]);
        }
    }
    printf("%d\n", change_count);
    delete[] a;

}
