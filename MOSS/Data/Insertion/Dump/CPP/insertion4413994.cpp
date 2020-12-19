#include <bits/stdc++.h>


#define MAX 100

int arr[MAX];
int N;

void print() {
    for (int i = 0; i < N; i++) {
        if (i) std::printf(" ");
        std::printf("%d", arr[i]);
    }
    std::printf("\n");
}


void insertionSort() {
    int i, j, v;
    for (int i = 1; i < N; i++) {
        v = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > v) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
        print();
    }
}


int main()
{

    std::scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        std::scanf("%d", &arr[i]);
    }
    print();
    insertionSort();

    return 0;
}

