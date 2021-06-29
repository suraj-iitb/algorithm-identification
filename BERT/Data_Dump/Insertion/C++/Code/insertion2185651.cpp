#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void insertSort(int arr[], int n){
    for(int i = 1;i < n;i++){
        int temp = arr[i];
        int j = i-1;
        for(;j>=0;j--){
            if(temp < arr[j]){
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = temp;

        for(int q = 0;q< n;q++){

            cout<<arr[q];
            if(q != n-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}


int main(){
    int n;
    int arr[110];
    cin>>n;
    for (int i = 0; i < n;i++) {
        cin>>arr[i];
    }
    for(int q = 0;q< n;q++){

        cout<<arr[q];
        if(q != n-1){
            cout<<" ";
        }
    }
    cout<<endl;
    insertSort(arr, n);




}
