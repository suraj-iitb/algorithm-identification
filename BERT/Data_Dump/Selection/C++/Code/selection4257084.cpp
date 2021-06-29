#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int Min,pos;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int cnt=0;
    for(int i=0; i<n; i++){
        Min=i;
        for(int j=i; j<n; j++){
            if(arr[Min]>arr[j]) Min=j;
        }
        if(Min!=i){
            swap(arr[i],arr[Min]);
            cnt++;
        }
    }

    cout<<arr[0];
    for(int i=1; i<n; i++){
        cout<<" "<<arr[i];
    }
    cout<<endl<<cnt<<endl;

    return 0;
}

