#include <iostream>
#define N 100
using namespace std;

int main()
{
    int n,a[N],key,i,k;
    cin >> n;
    for( i=0; i<n ; i++)
    {
        cin >> a[i];
    }
    for(i=0; i<n ; i++)
    {
        key = a[i];
        int j = i-1;
        while(a[j]>key && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        for( k=0; k<n-1 ; k++)
            cout << a[k] << " ";
        cout << a[k] << endl;
    }
    return 0;
}

