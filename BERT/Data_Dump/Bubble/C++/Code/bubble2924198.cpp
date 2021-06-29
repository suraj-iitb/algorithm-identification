#include <iostream>

#define NMAX 100

void bubbleSort(int A[], int N) {
    bool flag = 1;
    int temp;
    int cnt = 0;
    while(flag) {
        flag = 0;
        for (int j=N-1; j>0; j--) {
            if (A[j] < A[j-1]) {
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                flag = 1;
                cnt++;
            }
        }
    }
    for (int i=0; i<N-1; i++)
        std::cout << A[i] << " ";
    std::cout << A[N-1] << std::endl;
    std::cout << cnt << std::endl;

}

int main() {
    int A[NMAX] = {};
    int N;
    
    std::cin >> N;
    
    for (int i=0; i<N; i++)
        std::cin >> A[i];
    
    bubbleSort(A, N);
    
    return 0;   
}
