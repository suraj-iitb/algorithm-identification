#include<iostream>
using namespace std;

int bubbleSort(int N, int *series){
    int swapNum=0;
    for(int i=0; i<N; i++){
        for(int j=N-1; j>=i+1; j--){
            if(series[j-1]>series[j]){
                swap(series[j], series[j-1]);
                swapNum++;
            }
        }
    }
    return swapNum;
}

int main(){

    int N, swapNum;
    int series[100];
    cin >> N;

    for(int i=0; i!=N; i++){cin >> series[i];}
    
    swapNum=bubbleSort(N, series);

    for(int i=0; i!=N; i++){
        cout << series[i];
        if(i!=N-1)cout << " ";
    }
    cout << endl;
    
    cout << swapNum << endl;

    return 0;
}
