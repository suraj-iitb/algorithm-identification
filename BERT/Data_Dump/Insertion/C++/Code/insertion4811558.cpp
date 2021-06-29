#include<iostream>
using namespace std;

void print_list(int A[],int N){
    for(int i=0;i<N;i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout<<endl;
}

int main(){
    int A[1000],N,v,i,j;
    
    cin >> N;
    for(int i = 0; i<N; i++) cin >> A[i];
    print_list(A,N);
    
    
    for(i=1; i<N; i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        print_list(A,N);
        }
    
    return 0;
    
}
