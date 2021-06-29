#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int cnt = 0;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++)
        cin >> A[i];
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for(int i = N - 1; i >= 1; i--)
        {
            if(A[i] < A[i - 1])
            {
                swap(A[i], A[i - 1]);
                cnt++;
                flag = 1;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        if(i > 0)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

