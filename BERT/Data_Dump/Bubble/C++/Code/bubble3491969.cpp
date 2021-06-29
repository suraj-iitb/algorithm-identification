#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, A[100];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int flag = 1;
    int count = 0;
    while (flag)
    {
       flag = 0;
       for (int j = N - 1; j > 0; --j) {
         if (A[j] < A[j - 1]) {
            swap(A[j], A[j - 1]);
            flag = 1;
            ++count;
         }
       }
    }
    for (int i = 0; i < N; ++i)
    {
        cout << A[i];
        if (i < N - 1)
            cout << ' ';
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
