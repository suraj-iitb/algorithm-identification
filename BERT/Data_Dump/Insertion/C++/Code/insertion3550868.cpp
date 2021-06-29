#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i);
    }
    for(int i=0;i<N;i++){
        int v =A.at(i);
        for(int j=i-1;j>=0;j--){
            if(v<A.at(j)){
                A.at(j+1)=A.at(j);
            }
            else {A.at(j+1)=v;
                break;
            }
            if(j==0) A.at(0)=v;
                
            }
        
        for(int j=0;j<N;j++){
            cout<<A.at(j);
            if(j<N-1) cout<<" ";
            if(j==N-1) cout<<endl;
        }
    
    }
            
    }

