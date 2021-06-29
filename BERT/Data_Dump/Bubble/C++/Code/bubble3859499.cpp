#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

void swap(int *xp,int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int n){
    for(int i=0; i < n; i++){
        if(i==n-1){
            cout<<arr[i];
        }
        else{
        cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

void bubbleSort(int arr[], int n){
    
    int sCount = 0;
    for(int i=0; i < n; i++){
        for(int j=n-1; j>=i+1; j--){
            if(arr[j] < arr[j-1]){
                swap(&arr[j],&arr[j-1]);
                sCount++;
            }
        }
    }
    printArray(arr,n);
    cout<<sCount<<endl;
}



int main(){
    
    int n;
    cin >> n;
     
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    bubbleSort(arr,n);
    return 0;
}
