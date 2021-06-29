#include <iostream>
using namespace std;

void print_array(int A[],int N){
    for(int i=0;i<N;i++){
        if(i != 0){cout<<" ";}
        cout<<A[i];
    }
    cout<<'\n';
}

void insertion_sort(int A[],int N){
    int i,j,v;
    for(i=1;i<N;i++){
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        print_array(A,N);
    }
}

int main(){
    int N;
    int A[1000];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    print_array(A,N);
    insertion_sort(A,N);
}
