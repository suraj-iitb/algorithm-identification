#include <iostream>

void insertSort(int n, int *a) {
    int v, j;
    
    for(int i=1; i <= n-1; i++) {
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        
        for(int i=0; i != n; i++) {
            if(i < n-1) std::cout << a[i] << " ";
            else std::cout << a[i] << "\n";
        }
    }
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    std::cin >> N;
    int A[N];
    for(int i=0; i != N; i++) {
        std::cin >> A[i];
    }
    for(int i=0; i != N; i++) {
        if(i < N-1) std::cout << A[i] << " ";
        else std::cout << A[i] << "\n";
    }
    insertSort(N, A);
    
    return 0;
}
