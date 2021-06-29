#include <iostream>

using namespace std;

int swap_count = 0;

void swap(int &a, int &b);
void selection_sort(int a[], int len);
void trace(int a[], int len);

int main()
{
    int len;
    int a[1010];
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> a[i];
    }
    selection_sort(a, len);
    cout << swap_count << endl;
    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    swap_count++;
    return;
}

void selection_sort(int a[], int len)
{
    int min_index;
    for (int i = 0; i < len - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(a[i], a[min_index]);
        }
    }
    trace(a, len);
    return;
}

void trace(int a[], int len)
{
    cout << a[0];
    for (int i = 1; i < len; i++)
    {
        cout << ' ' << a[i];
    }
    cout << endl;
}
