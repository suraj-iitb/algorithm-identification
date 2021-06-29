#include <iostream>

int cnt = 0;

void bubbleSort(int A[],int N){
    bool flag = true;
    int tmp;
    while(flag){
        flag = false;
        for(int i=N-1;i>0;i--){
            if(A[i]<A[i-1]){
                tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;
                flag = true;
                cnt++;
            }
        }
    }
}

int main(){
    int N;
    std::cin >> N;
    int A[N];
    for(int i=0;i<N;i++){
        std::cin >> A[i];
    }
    bubbleSort(A,N);
    for(int i=0;i<N;i++){
        std::cout << A[i];
        if(i==N-1){
            std::cout << std::endl;
        }else{
            std::cout << " ";
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
