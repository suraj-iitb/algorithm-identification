#include <iostream>
#include <string>
#include <vector>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A&lang=jp
// 挿入ソート
void printArray(vector<int> vector, bool isLast) {
    int size = vector.size();
    for (int i = 0; i < size; ++i) {
        if (i == size - 1) {
            cout << vector[i] << endl;
        } else {
            cout << vector[i] << " ";
        }
    }

//    cout << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    printArray(A, false);

    for (int i = 1; i < N; ++i) {
        int v = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        bool islast = (i == N - 1);
        printArray(A, islast);
    }

//    cout << "5 2 4 6 1 3" << endl;
//    cout << "2 5 4 6 1 3" << endl;
//    cout << "2 4 5 6 1 3" << endl;
//    cout << "2 4 5 6 1 3" << endl;
//    cout << "1 2 4 5 6 3" << endl;
//    cout << "1 2 3 4 5 6" << endl;



    return 0;
}


