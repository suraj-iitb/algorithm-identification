#include <iostream>
using namespace std;


void selectionSort(int* A,int N,int& count){
    for(int i=0;i!=N;++i){
        int minj=i;
        for(int j=i;j!=N;++j){
            if(A[j]<A[minj]){
                minj=j;
                
            }
        }
        if(A[i]!=A[minj]){
            ++count;
            int tmp=A[i];
            A[i]=A[minj];
            A[minj]=tmp;
        }
        
        
        
    }
}

void print_l(int* array,int N){
    for(int i=0;i!=N;++i){
        cout<<array[i];
        if(i!=N-1){
            cout<<" ";
        }else{
            cout<<endl;
        }
    }
    
}

int main(){
    int N;
    cin>>N;
    int array[N];
    int count=0;
    for(int i=0;i!=N;++i){
        cin>>array[i];
    }
    
    selectionSort(array, N, count);
    
    print_l(array,N);
    cout<<count<<endl;
}

