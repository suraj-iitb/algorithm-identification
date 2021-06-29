//exit()を使うとCEになるのでコメントアウトしました(自環境では動く)
#include <iostream>
#include <stdexcept>

int main(){
    int N;
    try{
        std::cin >> N;
        if(N < 1 || N > 100){
            throw std::runtime_error("input should be 1 <= N <= 100");
        }
    }
    catch(std::runtime_error e){
        std::cout << e.what() << std::endl;
        //std:exit(1);
    }

    //set array size
    int *A;
    A = new int[N];

    //input numbers to array
    int i, j, k, key;
    try{
        for(i = 0; i < N; ++i){
            std::cin >> A[i];
            if(A[i] < 0 || A[i] > 1000){
                throw std::runtime_error("input should be 0 <= A <= 1000");
            }
        }
    }
    catch(std::runtime_error e){
        std::cout << e.what() << std::endl;
        //std::exit(1);
    }

    for(i = 0; i < N; ++i){
        std::cout << A[i];
        if(i != N - 1){
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    //sort
    for(i = 1; i < N; ++i){
        key = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;

        //output process
        for(k = 0; k < N; ++k){
            std::cout << A[k];
            if(k != N - 1){
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }


    return 0;
}
