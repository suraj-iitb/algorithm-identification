#include <iostream>
#include <algorithm>

using namespace std;

static const int MAX = 100;

void trace(int A[], int N){
    int i;
    for (int i = 0; i < N; i++){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int main(){
    int num;
    int A[MAX];

    cin >> num;
    for (int i = 0; i < num; i++) cin >> A[i];

    trace(A, num);
    for (int i = 1; i < num; i++){
        int tmp = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > tmp){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp;
        trace(A, num);
    }

    return 0;
}
