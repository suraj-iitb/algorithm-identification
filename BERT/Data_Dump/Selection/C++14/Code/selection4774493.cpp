#include<bits/stdc++.h>
using namespace std;
#define INF 999999999

int main(){
    int n;
    cin>>n;
    vector<int> data(n);
    for(int i=0; i<n; i++){
        cin>>data[i];
    }
    int count=0;

    for(int i=0; i<=n-2; i++){ 
        int minj=i;
        for(int j=i+1; j<=n-1; j++){
            if(data[j]<data[minj]){
                minj=j;
            }
        }
        if(i!=minj){
            swap(data[i],data[minj]);
            count++;
        }
    }

    for(int i=0; i<n-1; i++){
        cout<<data[i]<<" ";
    }

    cout<<data[n-1]<<endl<<count<<endl;
}
