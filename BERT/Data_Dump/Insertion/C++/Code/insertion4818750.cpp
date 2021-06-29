#include <iostream>

using namespace std;

void insert_sort(int a[], int len);

int main()
{
    int len;
    int a[1010];
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> a[i];
    }
    insert_sort(a, len);
    cout << a[0];
    for (int i = 1; i < len; i++)
    {
        cout << ' ' << a[i];
    }
    cout << endl;
    return 0;
}

void insert_sort(int a[], int len)
{
    for (int i = 1; i < len; i++)
    {
        cout << a[0];
        for (int i = 1; i < len; i++)
        {
            cout << ' ' << a[i];
        }
        cout << endl;
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    return;
}
