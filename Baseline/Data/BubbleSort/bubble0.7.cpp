#include<iostream>

using namespace std;

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    const int n = 10;
    int arr[n];
    cout<<"Enter the array:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }

    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<10;i++)
        cout<<arr[i]<<endl;

}