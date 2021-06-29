#include <iostream>
using namespace std;
const int MAX = 100;
int V[MAX];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    for (int i = 0; i < N; ++i) {
        int temp = V[i];
        int j = i - 1;
        while (j >= 0 && V[j] > temp) {
            V[j+1] = V[j];
            j--;
        }
        V[j+1] = temp;

        for (int k = 0; k < N; ++k) {
            if (k == N-1) {
                cout << V[k];
            }else {
                cout << V[k] << " ";
            }
        }
        cout << endl;
    }


    return 0;
}
