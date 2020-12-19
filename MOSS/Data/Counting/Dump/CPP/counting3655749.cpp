#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v;
    int A[n];
    for(int i=0; i<n; i++)
        cin>>A[i];
    int m=A[0];
    for(int i=1; i<n; i++){
        if(m<A[i]){
            m=A[i];
        }
    }
    int C[m+1];
    for(int i=0; i<=m; i++){
        C[i]=0;
    }
    for(int i=0; i<n; i++){
        C[A[i]]++;
    }
    for(int i=0; i<=m; i++){
        for(int j=0; j<C[i]; j++){
            v.push_back(i);
        }
    }
    cout<<v[0];
    for(int i=1; i<v.size(); i++)
        cout<<" "<<v[i];
    cout<<endl;
    return 0;
}
