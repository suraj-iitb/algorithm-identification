#include<iostream>
using namespace std;

int selectionSort(int N, int *series){
    int swapNum=0;
    for(int i=0; i<N; i++){
        int minj=i;
        for(int j=i; j<N; j++){
            if(series[minj]>series[j])minj=j;
        }
        swap(series[i], series[minj]);
        if(i!=minj)swapNum++;
    
    }
    return swapNum;
}

int main(){

    int N, swapNum;
    int series[100];
    cin >> N;

    for(int i=0; i!=N; i++){cin >> series[i];}
    
    swapNum=selectionSort(N, series);

    for(int i=0; i!=N; i++){
        cout << series[i];
        if(i!=N-1)cout << " ";
    }
    cout << endl;
    
    cout << swapNum << endl;

    return 0;
}
