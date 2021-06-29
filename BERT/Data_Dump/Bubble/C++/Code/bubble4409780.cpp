#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &a, int N) {
    for (int i = 0; i < N; i++) {
        int v = a.at(i);
        int j = i - 1;

        while (j >= 0 && a.at(j) > v) {
            a.at(j+1) = a.at(j);
            j--;
        }

        a.at(j+1) = v;

        for(int i = 0; i < N; i++) {
            if (i == N-1) {
                cout << a.at(i) << '\n';
                break;
            }
            cout << a.at(i) << " ";
        }
    }
}

void bubbleSort(vector<int> &a, int N) {
    bool flag = 1;
    int i = 0;
    int count = 0;
    while (flag) {
       flag = 0;
       for (int j = N - 1; j > i; j--) {
           if (a.at(j) < a.at(j-1)) {
               swap(a.at(j), a.at(j-1));
               flag = 1;
               count++;
           }
       }
       i++;
    }

    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            cout << a.at(i) << endl;
            break;
        }
        cout << a.at(i) << " ";
    }
    cout << count << endl;
}

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    bubbleSort(a, N);
    return 0;

}
