#include<iostream>

using namespace std;

void trace(int *array,int n){
    for (int i = 0; i < n; i++){
        if(i!=0) cout << " ";
        cout << *(array + i);
    }
    cout << endl;
}


void bubbleSort(int *array,int n){
    bool flag = true;
    int i = 0;
    int time = 0;
    while (flag){
        flag = false;
        for(int j = n-1;j >= i+1;j--){

            if(array[j] < array[j-1]){
                int value = array[j-1];
                array[j-1] = array[j];
                array[j] = value;
                flag = true;
                time++;
            }
        }
        i++;
    }
    trace(array,n);
    cout << time << endl;
};

int main(){
    int n;
    cin >> n ;
    int  array[n];
    for (int i = 0; i < n; i++){cin >> array[i];}

    bubbleSort(array,n);
}
