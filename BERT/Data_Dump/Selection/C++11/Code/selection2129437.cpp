#include <iostream>
#include <algorithm>

using namespace std;

void SelectSort(int x[], int N);
void BubbleSort(int x[], int N);
void InsertSort(int x[], int N, int num);
void ShellSort(int x[], int N);
void Trace(int x[], int N);

int gCount = 0;

int main() {
    int N;

    cin >> N;

    int x[N];

    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    SelectSort(x, N);
    Trace(x, N);
    cout << gCount << endl;

    return 0;
}


void SelectSort(int x[], int N) {
    int min;

    for (int i = 0; i < N - 1; i++) {
        min = i;
        for (int j = i; j < N; j++) {
            if (x[min] > x[j]) {
                min = j;
            }
        }
        if (i != min) {
            gCount++;
            swap(x[min], x[i]);
        }
    }
}

void Trace (int x[], int N) {
    int i;
    for (i = 0; i < N - 1; i++) {
        cout << x[i] << " ";
    }
    cout << x[i] << endl;
}
