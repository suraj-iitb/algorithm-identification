#include<iostream>

using namespace std;

void selectionSort(int A[100], int n){

    int i, j, minj, counter = 0, tmp;

    for(i=0;i<n;i++){
        minj = i;
        for(j=i;j<n;j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i != minj){
            A[i] = A[i] + A[minj];
            A[minj] = A[i] - A[minj];
            A[i] = A[i] - A[minj];
            counter++;
        }
    }

    for(j=0;j<n;j++){
        if(j == 0){
            cout << A[j];
        }else{
            cout << " " << A[j];
        }
    }

    cout << endl << counter << endl;

}

int main(){

    int i, n;
    int A[100] = {0};

    cin >> n;

    for(i=0;i<n;i++){
        cin >> A[i];
    }

    selectionSort(A, n);

    return 0;
}
