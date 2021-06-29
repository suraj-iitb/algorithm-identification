#include <iostream>
#include <algorithm>

using namespace std;

void printarr(vector<int> arr,int n){
    for(int i=0;i<arr.size()-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[arr.size()-1]<<endl;
    return;
}


int main() {
    int n;
    vector<int> arr;
    cin>>n;
    for(int i=0,t;i<n;i++){
        cin>>t;
        arr.push_back(t);
    }
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while (j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;

        printarr(arr,n);
    }
    return 0;
}

