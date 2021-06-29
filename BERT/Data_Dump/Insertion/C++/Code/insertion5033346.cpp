#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int a[100];
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int k = 0; k < N; k++) {
        cout << a[k];
        if (k < N - 1) cout << " ";
        else if (k == N - 1) cout << endl;
    }

    int key;
    for (int i = 1; i < N; i++) {
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--; 
        }
        a[j + 1] = key;

        for (int k = 0; k < N; k++) {
            cout << a[k];
            if (k < N - 1) cout << " ";
            else if (k == N - 1) cout << endl;
        }
    }
}
