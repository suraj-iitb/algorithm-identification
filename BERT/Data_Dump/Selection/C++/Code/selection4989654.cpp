#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int v=0; v<n; v++){
        cin >> a[v];
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
        {
            int ne = a[i];
            a[i] = a[min];
            a[min] = ne;
            c++;
        }
    }
    cout << a[0];
    for(int i=1; i<n; i++){
        cout << " " << a[i];
    }
    cout << endl;
    cout << c << endl;
}

  


