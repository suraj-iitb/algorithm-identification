#include <iostream>
using namespace std;

void print(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i > 0)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
}

void insert_sort(int *a, int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = a[i];

        j = i - 1;
        while(j >= 0 && a[j]>key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        print(a, n);
    }
}

int main()
{
    int a[100];
    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    print(a, n);
    insert_sort(a,n);
    return 0;
}
