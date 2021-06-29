#include<iostream>
#include<algorithm>
#define index 100
int main(int argc, char const *argv[]) {
    
    int data[index];
    int N=0;
    std::cin>>N;
    for (int i=0; i<N; ++i) {
        std::cin>>data[i];
    }
    
    for (int i = 0; i<N; ++i) {
        int v = data[i];
        int j = i-1;
        while (0<=j && v<data[j]) {
            data[j+1]=data[j];
            j--;
        }
        data[j+1] = v;
        
        for (int i = 0; i<N; ++i) {
            std::cout<<data[i];
            if (!(i==N-1)) {
                std::cout<<" ";
            }else{
                std::cout<<std::endl;;
            }
        }
    }
    return 0;
}
