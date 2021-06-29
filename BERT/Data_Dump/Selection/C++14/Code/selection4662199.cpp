// 選択ソート O(N^2)

#include <iostream>
using namespace std;

int selectionSort(int A[], int N) {
    int ex{ 0 }, min{0};
    for (int i = 0; i < N-1; i++) {
        min = i;

        for (int j = i; j < N; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        swap(A[i], A[min]);
        if( i != min ) ex++;
    }
    return ex;
}

int main()
{
    int N;
    cin >> N;

    int A[100];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ex = selectionSort(A,N);

    for (int i = 0; i < N; i++) {
        if (i != 0) cout << ' ';
        cout << A[i];
    }
    cout << endl;
    cout << ex << endl;

}
