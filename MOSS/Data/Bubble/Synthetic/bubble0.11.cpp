#include<iostream>

using namespace std;

int main(){
    const int n = 10;
    int arr[n];
    cout<<"Enter the array:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int i=0;
    while(i<n-1){
        int j=i+1;
        while(j<n){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }
    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<10;i++)
        cout<<arr[i]<<endl;

}