#include <iostream>

using namespace std;

static const int MAX = 100;

void trace(int A[], int N){
    for (int i = 0; i < N; i++){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int bubbleSort(int A[], int N){
    bool flag = true;
    int sw = 0;
    while (flag){
        flag = false;
        for (int j = N - 1; j > 0; j--){
            if (A[j] < A[j - 1]){
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = true;
                sw++;
            }
        }
    }
    return sw;
}

int main(){
    int num;
    int A[MAX];

    cin >> num;
    for (int i = 0; i < num; i++) cin >> A[i];

    int count = bubbleSort(A, num);

    trace(A, num);
    cout << count << endl;

    return 0;
}
