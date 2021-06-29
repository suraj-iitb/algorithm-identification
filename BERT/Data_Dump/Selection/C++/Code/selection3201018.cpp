#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1000000;
int selectionSort(int A[], int N){ //N個の要素を含む0-オリジンの配列0
    int minj, sw = 0;
    for(int i = 0; i < N - 1; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
            }
            swap(A[i], A[minj]);
            if(i != minj) sw++;
    }
    return sw;
}

int main(){
    int A[100], N, sw;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    sw = selectionSort(A, N);

    for(int i = 0; i < N; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

	return 0;
}
