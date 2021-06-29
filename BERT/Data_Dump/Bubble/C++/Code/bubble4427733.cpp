#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


int bubblesort(int A[], int N) {

    int cnt = 0;
    bool flag = true;
    
    while (flag) {
        
        flag = false;

        for (int i = N - 1; i > 0; i--) {
        
            if (A[i - 1] > A[i]) {

                cnt++;

                swap(A[i - 1], A[i]);
                flag = true;
        
            }
        }
    }

    return cnt;
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int cnt = bubblesort(A, N);

    cout << A[0];
    for (int i = 1; i < N; i++)
        cout << " " << A[i];
    cout << '\n';
    cout << cnt << '\n';

    return 0;
}
