#include <iostream>

#define NMAX 100

int selectionSort(int A[], int N) {
    int minj;
    int temp;
    int j;
    int cnt = 0;
    bool flag;
    
    for (int i=0; i<N; i++) {
        minj = i;
        flag = 0;
        for (j=i; j<N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
                flag = 1;
            }
        }
        temp = A[minj];
        A[minj] = A[i];
        A[i] = temp;
        if (flag==1)
            cnt++;
    }
    return cnt;
}

int main() {
    int N;
    int A[NMAX];

    std::cin >> N;
    for (int i=0; i<N; i++)
        std::cin >> A[i];
    
    int cnt = selectionSort(A, N);
    
    for (int i=0; i<N; i++) {
        if (i!=0)
            std::cout << " ";
        std::cout << A[i];
    }
    std::cout << std::endl;
    std::cout << cnt << std::endl;
}
