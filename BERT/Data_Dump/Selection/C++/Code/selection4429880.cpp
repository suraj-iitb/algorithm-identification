#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


int selectionsort(int A[], int N) {

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        bool flag = false;
        int min = i;

        for (int j = i; j < N; j++) 
        {
            if (A[min] > A[j]) 
            {
                min = j;
                flag = true;
            }
        }

        swap(A[i], A[min]);
        if (flag)
            cnt++;
            
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

    int cnt = selectionsort(A, N);
    for (int i = 0; i < N; i++) {
        if (i)
            cout << " ";
        cout << A[i];
    }
    cout << '\n';
    cout << cnt << '\n';
    return 0;
}
