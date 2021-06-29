#include <iostream>

using namespace std;

void insertionSort(int A[], int N) { // N個の要素を含む0-オリジンの配列A
    int i, j, v, l;
    for (i = 1; N > i; i++) {   //for i が 1 から N-1 まで
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j + 1] = v;
        cout << A[0];
        for(l =1; l < N; l++){
            cout << " " << A[l];
        }
        cout << endl;
    }
}

int bubbleSort(int A[], int N) { // N 個の要素を含む 0-オリジンの配列 A
    int j, l, t, c=0;
    int flag = 1; // 逆の隣接要素が存在する
    while (flag) {
        flag = 0;
        for(j = N-1; j > 0; j--) {
            if(A[j] < A[j-1]) {
                t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
                flag = 1;
                c++;
            }
        }
    }
    return c;
}

int main() {
    int A[110];
    int i, l, N, t, f, flg=1, c;
    
    cin >> N;
    for(i =0; i < N; i++){
        cin >> A[i];
    }
/*
    cout << A[0];
    for(i =1; i < N; i++){
        cout << " " << A[i];
    }
    cout << endl;
*/
//    insertionSort(A, N);
    c = bubbleSort(A, N);
    cout << A[0];
    for(i =1; i < N; i++){
        cout << " " << A[i];
    }
    cout << endl;
    cout << c << endl;
    return 0;
}

