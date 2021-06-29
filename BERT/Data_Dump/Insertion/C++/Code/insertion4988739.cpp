#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        if(i != n-1) cout << a[i] << ' ';
        else cout << a[i] << endl;
    }
  
    int v,j;
    for(int i = 1; i < n; i++)
    {
        v = a[i];
        j = i-1;
        while(j >= 0 && a[j] > v)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        
        for(int i = 0; i < n; i++)
        {
            if(i != n-1) cout << a[i] << ' ';
            else cout << a[i] << endl;
        }
    }
}

