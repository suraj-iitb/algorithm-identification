#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 100;

void trace(int A[], int N)
{
    cout << A[0];
    for(int i = 1; i < N; i++)
    {
        cout <<" "<< A[i];
    }
    cout << endl;
}

int main()
{
    int n, R[MAX];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> R[i];
    trace(R, n);

    int v, j;
    for(int i = 1; i < n; i++)
    {
        v = R[i];
        j = i - 1;
        while(j>=0 & R[j]>v)
        {
            R[j+1] = R[j];
            j --;
        }
        R[j+1] = v;
        trace(R, n);
    }
    return 0;
}
