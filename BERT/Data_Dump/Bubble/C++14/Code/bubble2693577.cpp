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

int do_bubble_sort(int *a, size_t size)
{
    int num_of_exchange = 0;
    bool flag = true;
    for (int i = 0; flag; ++i)
    {
        flag = false;
        for (int j = size - 1; j > i; --j)
        {
            if (a[j] < a[j - 1])
            {
                flag = true;
                swap(a[j], a[j - 1]);
                num_of_exchange++;
            }
        }
        // show_me(a, size);
    }
    return num_of_exchange;
}

int main()
{
    int A[100] = {};
    size_t n;
    cin >> n;
    for (size_t t = 0; t < n; ++t)
    {
        cin >> A[t];
    }
    int num;
    num = do_bubble_sort(A, n);
    show_me(A, n);
    cout << num << endl;
}
