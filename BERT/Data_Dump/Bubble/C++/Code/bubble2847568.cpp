#include<iostream>
#include<utility>

const int MAX_N=100;

int b_sort(int A[],int N){
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=N-1;j>i;j--){
            if(A[j-1]>A[j]){
                std::swap(A[j-1],A[j]);
                cnt++;
            }
        }
    }
    return cnt;
}


int main(void){
    int N;
    int A[MAX_N];
    std::cin>>N;
    for(int i=0;i<N;i++)
        std::cin>>A[i];
    int cnt_swap=b_sort(A,N);
    for(int i=0;i<N;i++){
        if(i) std::cout<<" ";
        std::cout<<A[i];
    }
    std::cout<<std::endl;
    std::cout<<cnt_swap<<std::endl;
    return 0;
}
