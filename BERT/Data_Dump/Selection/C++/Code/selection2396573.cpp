#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int selectionSort(vector<int> &A, int N)
{
    int counter = 0;
    for (int i = 0; i < N-1; ++i) {
        int minj = i;
        for (int j = i; j < N; ++j) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }

        if (i != minj) {
            swap(A[i], A[minj]);
            counter++;
        }
    }
    return counter;
}

int main()
{
    vector<int> A;
    int N;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    int counter = selectionSort(A, N);

    for (int i = 0; i < N-1; ++i) {
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
    cout << counter << endl;

    return 0;
}
