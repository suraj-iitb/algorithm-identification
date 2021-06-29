// 12.1 交換ソート
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> data(n);
    for(int i=0; i<n; i++){
        cin>>data[i];
    }
    int count=0;

    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            if(data[j-1]>data[j]){
                swap(data[j-1],data[j]);
                count++;
            }
        }
    }

    for(int i=0; i<n-1; i++){
        cout<<data[i]<<" ";
    }

    cout<<data[n-1]<<endl<<count<<endl;
}
