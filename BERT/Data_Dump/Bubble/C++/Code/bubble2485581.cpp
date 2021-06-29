#include <iostream>
 
using namespace std;
 
int main()
{
    int n, a[100], i, j, r = 0;
 
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];
 
    for (i = 0; i < n; ++i)
        for (j = n-1; j > i; --j)
            if (a[j] < a[j-1])
                swap(a[j], a[j-1]), ++r;
 
    for (i = 0; i < n; ++i)
    {
        cout << a[i];
        if (i < n-1)
            cout << " ";
    }
    cout << endl << r << endl;
 
    return 0;
}
