#include <iostream>
#include <algorithm>
using namespace std;

void showMe(int *a, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << (i == 0 ? "" : " ") << a[i];
    }
    cout << endl;
}

int doSelectionSort(int *a, size_t size)
{
    int num_of_swap = 0;
    size_t minj;
    for (size_t i = 0; i < size; ++i)
    {
        minj = i;
        for (size_t j = i; j < size; ++j)
        {
            if (a[j] < a[minj])
                minj = j;
        }
        if (i != minj)
        {
            swap(a[i], a[minj]);
            ++num_of_swap;
        }
    }
    return num_of_swap;
}

int main()
{
    int a[100] = {};
    size_t size;
    cin >> size;
    for (size_t i = 0; i < size; ++i)
    {
        cin >> a[i];
    }

    int numOfSwap = doSelectionSort(a, size);
    showMe(a, size);
    cout << numOfSwap << endl;

    return 0;
}
