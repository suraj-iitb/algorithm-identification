#include<iostream>

using namespace std;

void bubbleSort(int * arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
}

int main(){
    const int n = 10;
    int arr[n];
    cout<<"Enter the array:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    bubbleSort(arr,n);
    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<10;i++)
        cout<<arr[i]<<endl;

}