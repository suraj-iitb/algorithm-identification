#include <iostream>

using namespace std;

const int MAX = 110;

int bubble_sort(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = n-1; j >= i+1; --j) {
            if (a[j] < a[j-1]) {
                int t = a[j]; a[j] = a[j-1]; a[j-1] = t;
                ++count;
            }
        }
    }
    return count;
}

int main()
{
    int N;
    cin >> N;
    int a[MAX];
    for (int i = 0; i < N; ++i) cin >> a[i];
    int count = bubble_sort(a, N);
    for (int i = 0; i < N; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl << count << endl;

    return 0;
}
