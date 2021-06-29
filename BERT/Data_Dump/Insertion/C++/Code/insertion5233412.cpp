#include <iostream>
using namespace std;
const int MAXSIZE = 100;

void trace(int arr[], int N)
{
    int i;
    for(i=0;i<N;++i)
    {
        if(i>0) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

void INsertSort(int arr[], int N)
{
    int j, i, v;
    for(i=1; i<N; ++i)
    {
        v = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > v)
        {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = v;
        trace(arr, N);
    }
}


int main()
{
    int A[MAXSIZE];
    int n,i;
    cin >> n;
    for(i=0;i<n;++i) cin >> A[i];
    trace(A,n);
    INsertSort(A,n);
    return 0;
}
