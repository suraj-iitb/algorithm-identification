#include<iostream>

using namespace std;
void trace(int *array,int n){
    for(int i=0;i<n;i++){
        if(i!=0) cout << " ";
        cout << array[i];
    }
    cout << endl;
}

void selectionSort(int *array,int n){
    int time=0;
    for (int i = 0; i < n; i++){
        int minj = i;
        for (int j = i; j < n; j++){
            if(array[j] < array[minj]){
                minj = j;
            }
        }
        if(array[i]!=array[minj]) time++;
        swap(array[i],array[minj]);
    }
    trace(array,n);
    cout << time << endl;
}

int main(){
    int n;
    cin >> n;
    int array[n];

    for(int i=0;i<n;i++){cin >> array[i];}

    selectionSort(array,n);
}
