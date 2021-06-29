#include<iostream>
void selection_sort(int A[], int N){
    int cnt = 0;
    for(int i=0; i<N; ++i){
        int minj = i;
        for(int j=i; j<N; ++j)
            if(A[j] < A[minj]) minj = j;
        if(i != minj){
            std::swap(A[i], A[minj]);
            ++cnt;
        }
    }
    for(int i=0; i<N; ++i)
        std::cout << A[i] << (i == N-1 ? '\n' : ' ');
    std::cout << cnt << std::endl;
}
int main(){
    int A[101], N;
    std::cin >> N;
    for(int i=0; i<N; ++i) std::cin >> A[i];
    selection_sort(A, N);
    return 0;
}
