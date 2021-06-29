#include <iostream>
using namespace std;

int selection_sort(int n, int A[]){
    int sw = 0;
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(A[minj] > A[j]){
                minj = j;
            }
        }
        int temp = A[minj];
        A[minj] = A[i];
        A[i] = temp;
        if(minj != i) sw++;
    }
    return sw;
}


int main(){
    int N, counter; cin >> N;
    int array[N];
    for(int i = 0; i < N; i++) cin >> array[i];
    counter = selection_sort(N, array);

    for(int i = 0; i < N; i++){
        if(i == N-1) cout << array[i] << endl;
        else cout << array[i] << " ";
    }
    cout << counter << endl;

    return 0;
}
