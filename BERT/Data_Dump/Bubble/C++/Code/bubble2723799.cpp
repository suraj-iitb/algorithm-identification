#include <iostream>

void Show(int *array, int n){
    for(int i=0; i<n; ++i){
        if(i != n-1){
            std::cout << array[i] << " ";
        }else{
            std::cout << array[i];
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    int A[110];
    int c = 0;

    std::cin >> n;
    for(int i=0; i<n; ++i){
        std::cin >> A[i];
    }

    bool flag = true;
    
    for(int i=0; flag; ++i){
        flag = false;
        for(int j = n-1; j>=i+1; j--){
            if(A[j] < A[j-1]){
                std::swap(A[j], A[j-1]);
                flag = true;
                c++;
            }
        }
    }
    
    Show(A, n);
    std::cout << c << std::endl;
}
