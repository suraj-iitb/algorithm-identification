#include <iostream>
using namespace std;
const int Max = 200;

int a[Max];
void InsertSort(int a[], int N)
{
    for(int i=0; i<N; i++)
    {
        int v = a[i];
        int j= i-1;
        while(j>=0 && a[j]>v)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for(int k=0; k<N-1; k++)
            cout << a[k] << " ";
        cout << a[N-1] << endl;
    }
}
int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }
    InsertSort(a, N);
    return 0;
}

