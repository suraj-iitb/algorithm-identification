#include<iostream>

using namespace std;


void trace(int arr[] , int n){
    int i;
    for(i = 0 ; i < n ; i++){
        if( i > 0){
            cout << " ";
        }
        cout << arr[i];
    }
    cout << endl;
}

void insertionSort(int arr[], int n){
    int key, i, j;
    for(int i = 1 ; i < n ; i++){
        key = arr[i];
        j = i - 1 ;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        trace(arr,n);
    }
}


int main(){
    int n;
    cin >> n;
    int num[n];
    for(int i = 0 ; i < n ; i++){
        cin >> num[i];
    }

    trace(num,n);
    insertionSort(num,n);

    return 0;

}
