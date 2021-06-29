#include <iostream>
using namespace std;

void printarray(int n, int a[])
{
    for (int i = 0;i < n;i++)
    {
        cout << a[i];
        if (i != n-1) cout << " ";
    }
    cout << endl;
    return;
}

void insertionsort(int n, int a[])
{
    int key;
    for (int i = 1;i < n;i++)
    {
        key = a[i];;
        int j = i-1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        printarray(n, a);
    }
    
    return;
}

int main ()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++) cin >> a[i];
    
    printarray(n, a);
    insertionsort(n, a);
    
    
}
