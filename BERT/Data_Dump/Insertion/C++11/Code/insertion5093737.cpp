#include<bits/stdc++.h>
using namespace std;
#define PRINT(arr, n) for (int i=0; i<n-1; ++i) cout<<arr[i]<<" "; cout<<arr[n-1]<<endl;
const int N = 100;
int v[N];

void insertionSort(int* arr, int n)
{
    for (int i=1; i<n; ++i){
        int j=i-1;
        int key = arr[i];
        while (j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        PRINT(arr, n);
    }
}
int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>v[i];
    PRINT(v, n);
    insertionSort(v, n);
    return 0;
}


