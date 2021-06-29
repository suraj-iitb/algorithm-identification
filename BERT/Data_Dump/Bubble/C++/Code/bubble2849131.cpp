#include <iostream>

using namespace std;

int bubble_sort(int A[], int N) {
    int  count = 0;
    bool flag = 1;
    for (int i = 0; flag; i++) { 
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--) { 
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j-1]);
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int A[100], N, sw;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sw = bubble_sort(A, N);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}


