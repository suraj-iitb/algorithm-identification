#include<iostream>
#include<utility>

const int MAX_N=110;

int s_sort(const int N,int A[]){
    int cnt_swap=0;
    for(int i=0;i<N;i++){
        int minj=i;
        for(int j=i;j<N;j++){
            if(A[minj]>A[j]) minj=j;         
        }
        if(minj!=i){
            std::swap(A[i],A[minj]);
            cnt_swap++;
        }
    }
    return cnt_swap;
}

int main(void){
    int N;
    int A[MAX_N];
    std::cin>>N;
    for(int i=0;i<N;i++)
        std::cin>>A[i];
    int cnt_swap=s_sort(N,A);
    for(int i=0;i<N;i++){
        if(i) std::cout<<" ";
        std::cout<<A[i];
    }
    std::cout<<std::endl<<cnt_swap<<std::endl;
    return 0;
}
