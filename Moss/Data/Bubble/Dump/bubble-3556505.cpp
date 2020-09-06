#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i);
    }
    int count=0;
    bool check=true;
    while(check){
        check=false;
        for(int i=N-1;i>0;i--){
            if(A.at(i-1)>A.at(i)){
                swap(A.at(i-1),A.at(i));
                     count++;
                check=true;
                     }
                     
            }
        }
    for(int i=0;i<N-1;i++){
        cout<<A.at(i)<<" ";
    }
    cout<<A.at(N-1)<<endl;
    cout<<count<<endl;
    
    }

