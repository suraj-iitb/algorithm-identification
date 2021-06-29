#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int arr[99], fin[99];
    for(int i=0;i<N;i++) cin>>arr[i];
    int count=0;
    
    for(int i=0;i<N;i++){
        int mini=i;
        for(int j=i;j<N;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        if(i!=mini){
            swap(arr[i],arr[mini]);
            count++;
        }
    }
    
    for(int i=0;i<N;i++) cout<<arr[i]<<" \n"[i==N-1];
    cout<<count<<endl;
    return 0;
}

