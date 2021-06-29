#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100];
    for(int i=0; i<n; i++)
        cin >> a[i];
    int cnt = 0,  swap = 0;
    for(int i=0 ;i < n - 1; i++)
    {
        for(int j = n-1; j -1 >= 0; j--)
        {
            if(a[j-1] > a[j])
            {
                swap = a[j];
                a[j] = a[j-1];
                a[j-1] = swap;
                cnt++;
            }
        }
    }
    for(int i=0; i < n-1; i++)
        cout << a[i] << " ";
    cout << a[n-1] << endl << cnt << endl;
    return 0;
}

