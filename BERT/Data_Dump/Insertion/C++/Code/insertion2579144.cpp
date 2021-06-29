#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        A.push_back(a);
    }
    for(int j=0;j<n;j++){
        cout<<(j==0?"":" ")<<A[j];
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        int key=A[i];
        int j;
        for(j=i-1;j>=0&&A[j]>key;j--)A[j+1]=A[j];
        A[j+1]=key;
        for(int k=0;k<n;k++){
            cout<<(k==0?"":" ")<<A[k];
        }
        cout<<endl;
    }
}
