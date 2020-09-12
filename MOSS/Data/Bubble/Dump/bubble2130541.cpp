#include<iostream>
using namespace std;

void printSort(int A[], int N){
    cout << A[0];
    for(int i=1; i<N; i++){
        cout << " " << A[i];
    }
    cout << "" << endl;
}

void bubbleSort(int A[], int N){
    int flag, i, j, tmp, cnt;
    flag = 1;
    cnt = 0;
    while(flag){
        flag = 0;
        for(j=N-1; j+0; j--){
            if(A[j]<A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                cnt++;
            }
        }
    }
    printSort(A, N);
    cout << cnt << endl;
}

int main(void){
    int N, A[100];
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    bubbleSort(A, N);
    return 0;
}
