#include<iostream>
using namespace std;

void printArr(int N, int *arr){
    for(int i=0;i!=N;i++){
        if(i>0)cout<<" "; //隣接する要素の間に1つの空白を出力
        cout<<arr[i];
    }
    cout<<endl;
}

void insertionSort(int N, int *arr){
    int i, j, temp;
    for(int i=1;i!=N;i++){
        temp=arr[i];
        j=i-1;
        while(arr[j]>temp && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        printArr(N, arr);
    }
}

int main(){

    int N;
    int arr[100];
    
    cin>>N;
    for(int i=0;i!=N;i++){
        cin>>arr[i];
    }

    printArr(N, arr);
    insertionSort(N, arr);

    return 0;
}

