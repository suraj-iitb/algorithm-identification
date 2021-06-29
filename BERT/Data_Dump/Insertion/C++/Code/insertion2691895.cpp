#include <iostream>
#include <string>
using namespace std;

void show_me(int *a, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << (i == 0 ? "" : " ") << a[i];
    }
    cout << endl;
}

void insertion_sort(int *a, size_t size)
{
    int v;
    for (int i = 1; i < size; ++i)
    {
        v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = v;
        show_me(a, size);
    }
}

int main()
{
    int a[100] = {};
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    show_me(a, n);
    insertion_sort(a, n);
}

