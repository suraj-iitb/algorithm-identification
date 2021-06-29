#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],temp;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<arr[0];
    for(int i=1; i<n; i++){
        cout<<" "<<arr[i];
        }
        cout<<endl;

    for(int i=1; i<n; i++){
        temp=arr[i];
        int j=i-1;
        while((temp<arr[j]) && (j>=0)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;

        cout<<arr[0];
        for(int i=1; i<n; i++){
        cout<<" "<<arr[i];
        }
        cout<<endl;
    }

    return 0;
}

