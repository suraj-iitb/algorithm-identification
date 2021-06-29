#include <iostream>

int cnt = 0;

void selectionSort(int A[], int N){
    int min;
    int tmp;
    for(int i=0;i<N;i++){
        min = i;
        for(int j=i;j<N;j++){
            if(A[min]>A[j]){
                min = j;
            }
        }
        if(i!=min){
            tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
            cnt++;
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
    selectionSort(A,N);

    for(int i=0;i<N;i++){
        std::cout << A[i];
        if(i==N-1){
            std::cout << std::endl;
        }else{
            std::cout << " ";
        }
    }
    std::cout << cnt << std::endl;
}
