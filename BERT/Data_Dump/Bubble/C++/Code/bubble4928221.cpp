#include<iostream>

using namespace std;

void bubbleSort(int A[100], int n){

    int flag = 1, counter = 0, j;

    while(flag){
        flag--;
        for(j=n-1;j>0;j--){
            if(A[j] < A[j-1]){
                A[j] += A[j-1];
                A[j-1] = A[j] - A[j-1];
                A[j] = A[j] - A[j-1];
                counter++;
                flag++;
            }
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

    bubbleSort(A, n);

    return 0;
}
