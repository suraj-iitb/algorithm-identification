#include<iostream>

void sort(int A[],int N){
    for(int i=1;i<N;i++){
        int v=A[i];
        int j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(int k=0;k<N;k++){
            std::cout<<A[k];
            if(k!=N-1) std::cout<<" ";
       }
       std::cout<<std::endl;
    }
}

int main(void){
    int N;
    int A[100];
    std::cin>>N;
    for(int i=0;i<N;i++)
        std::cin>>A[i];
    for(int i=0;i<N;i++){
        if(i) std::cout<<" ";
        std::cout<<A[i];
    }
    std::cout<<std::endl;
    sort(A,N);
    
    return 0;
}
