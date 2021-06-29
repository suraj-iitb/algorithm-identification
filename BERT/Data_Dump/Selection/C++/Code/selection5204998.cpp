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
    for(int i=0; i<N; i++){
        int mini=i;
        
        for(int j=1+i; j<N; j++){
            if (A[j]<A[mini]){
                mini=j;

            }
        }
        if (A[i]!=A[mini]){
            int t = A[i];
            A[i] = A[mini];
            A[mini] = t;
            k++;
            
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

