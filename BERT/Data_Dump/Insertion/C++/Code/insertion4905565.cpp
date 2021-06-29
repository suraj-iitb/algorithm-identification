#include <iostream>
using namespace std;

void print(int *a, int n)
{
    for(int i=0; i<n-1; i++)
        cout << a[i] << " ";
    cout << a[n-1] << endl;
}

int main() {
    int n;
    cin >> n;
    int a[100];
    for(int i=0; i<n; i++)
        cin >> a[i];
    print(a, n);
    for(int i=1 ;i < n; i++)
    {
        int temp = a[i], j=i-1;
        for(; j >= 0; j--)
        {
            if(temp < a[j])
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = temp;
        print(a, n);
    }
    return 0;
}

