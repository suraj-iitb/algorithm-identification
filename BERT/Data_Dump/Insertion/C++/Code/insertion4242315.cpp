#include <iostream>

static const int MAX = 1000;

int main(){
    int itr;
    std::cin >> itr;
    int A[MAX];
    for(int i = 0; i < itr; i++){
        std::cin >> A[i];
    }
    for(int i = 0; i < itr; i++){
        if(i > 0) std::cout << " ";
        std::cout << A[i];
    }
    std::cout << std::endl;
    for(int i = 1; i < itr; i++){
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = v;
        for(int k = 0; k < itr - 1; k++){
            std::cout << A[k] << " ";
        }
        std::cout << A[itr - 1] << std::endl;
    }
    return 0;
}
