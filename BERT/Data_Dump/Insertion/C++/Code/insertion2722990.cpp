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

int main(){
    int n;
    int A[110];

    std::cin >> n;
    for(int i=0; i<n; ++i){
        std::cin >> A[i];
    }

    Show(A, n);

    for(int i=1; i<n; ++i){
        int v = A[i];
        int j = i-1;
        while(j>=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        Show(A, n);
    }
}
