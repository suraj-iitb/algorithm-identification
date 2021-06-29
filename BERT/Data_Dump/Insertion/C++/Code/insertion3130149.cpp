#include<iostream>

using namespace std;

void InsertionSort(int a[],int n){
    for(int i=0;i<n;i++){
        int temp = a[i];
        int j = i-1;
        while(j>=0 && a[j] > temp){
            a[j+1] =a[j];
            j--;
            a[j+1] = temp;
        }
        for(int b=0;b<n-1;b++){
            cout << a[b] << " ";
        }
        cout << a[n-1] << endl;
    }
}


int main(){
    int n;
    int array[1000];

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> array[i];
    }

    InsertionSort(array,n);
    return 0;
}
