#include <bits/stdc++.h>

using namespace std;

int main(){
    int i,j,n,temp;
    cin>>n;
    int *arr = new int[n];  // heap allocation
    for(i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
    // cout << endl;

}