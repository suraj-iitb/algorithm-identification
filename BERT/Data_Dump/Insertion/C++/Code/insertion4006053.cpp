#include <iostream>
#include<vector>
using namespace std;
int main(void){
    // Your code here!
    int N;  
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        cout<<A[i];
            if(i!=N-1){
                cout<<' ';
            }
            else{
                cout<<endl;
            }
        }
    for(int i=1;i<N;i++){
        int temp=A[i];
        int j=i-1;
        while(j>=0&&temp<A[j]){
            A[j+1]=A[j];
            A[j]=temp;
            j--;
        }
        for(int i=0;i<N;i++){
        cout<<A[i];
            if(i!=N-1){
                cout<<' ';
            }
            else{
                cout<<endl;
            }
        }
    }    
}

