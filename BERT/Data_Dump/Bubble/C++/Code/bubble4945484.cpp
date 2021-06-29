#include<iostream>
using namespace std;

int bubbleSort(int A[], int N){
    //cはchange 交換回数
    int c = 0;
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j = N-1 ; j > 0 ; j--){
            if(A[j] < A[j-1]){
                int b = A[j];
                A[j] = A[j-1];
                A[j-1] = b;
                flag = 1;
                c += 1;
            }
        }
    }
    return c;
}
int main(){
    int A[100];
    int N,c,k;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }

    c = bubbleSort(A , N);

    for(k = 0 ; k < N ; k++){
        if(k != N-1){
            cout << A[k] << " ";
        }
        else{
            cout << A[k];
        }
    }

    cout << endl;
    cout << c << endl;

    return 0;
}
