#include <iostream>

using namespace std;
int N;

int main()
{
    cin>>N;
    
    if(N<1 and N>100){
        cout<<"Invalid Input";
        return 0;
    }
    
    int A[N];
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    int k=0;
    for(int i=0; i<N-1; i++){
        
        for(int j=N-1; j>=i+1; j--){
            if (A[j]<A[j-1]){
                int t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
                k++;
            }
        }
        
    }
    for (int i = 0; i<N; i++){
        if(i!=N-1){
            cout<<A[i]<<" ";
        }
        else{
            cout<<A[i];
        }
    }
    cout<<endl;
    cout<<k<<endl;
    return 0;
}

