#include<iostream>
void bubble_sort(int A[], int N){
    bool f;
    int cnt = 0;
    do{
        f = false;
        for(int j=N-1; j>0; --j){
            if(A[j] < A[j-1]){
                std::swap(A[j], A[j-1]);
                f = true;
                ++cnt;
            }
        }
    }while(f);
    for(int i=0; i<N; ++i)
        std::cout << A[i] << (i == N-1 ? '\n' :  ' ');
    std::cout << cnt << std::endl;
}
int main(){
    int A[101], N;
    std::cin >> N;
    for(int i=0; i<N; ++i) std::cin >> A[i];
    bubble_sort(A, N);
    return 0;
}
