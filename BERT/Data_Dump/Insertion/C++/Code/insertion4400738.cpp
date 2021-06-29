#include <iostream>

using namespace std;
void print_array(int*,int);

void insertionSort(int* A,int N){
    print_array(A,N);
    for(int i=1;i!=N;++i){
        int v=A[i];
        int j=i-1;
      
        
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
            A[j+1]=v;
        }
          print_array(A,N);
    }
    
}

void print_array(int *A,int N){
    for(int i=0;i!=N;++i){
        std::cout<<A[i];
        if(i!=N-1){
            std::cout<<" ";
        }else{
            std::cout<<std::endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin>>N;
    
    int A[N];
    
    for(int i=0;i!=N;++i){
        cin>>A[i];
    }
    
    insertionSort(A, N);
    
    
    
    return 0;
}

