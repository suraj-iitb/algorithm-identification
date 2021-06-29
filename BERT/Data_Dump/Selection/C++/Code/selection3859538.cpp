#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        if(i==n-1){
            cout<<arr[i];
        }
        else{
            cout<<arr[i]<<" ";
        }
    }
}

void selectionSort(int arr[], int n){
    
    int sCount = 0;
    
    for(int i=0; i<n-1; i++){
        int mini = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        if(i!=mini){
        swap(&arr[i],&arr[mini]);
        sCount++;
        }
    }
    
    printArray(arr,n);
    cout<<endl;
    cout<<sCount<<endl;
}

int main(){
    
    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    selectionSort(arr,n);
    return 0;
}
