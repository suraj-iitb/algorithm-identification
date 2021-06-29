#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100];
    for(int i=0; i<n; i++)
        cin >> a[i];
    int cnt = 0,  swap = 0;
    for(int i=0 ;i < n; i++)
    {
        int min = i;
        for(int j = i; j < n; j++)
        {
            if(a[min] > a[j])
            {
                min = j;

            }
        }
        if(min != i)
        {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
            cnt++;
        }
    }
    for(int i=0; i < n-1; i++)
        cout << a[i] << " ";
    cout << a[n-1] << endl << cnt << endl;
    return 0;
}

