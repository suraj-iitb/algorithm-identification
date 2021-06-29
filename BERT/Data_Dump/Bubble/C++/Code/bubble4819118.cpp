#include <iostream>

using namespace std;

int swap_count = 0;

void bubble_sort(int a[], int len);
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
    bubble_sort(a, len);
    trace(a, len);
    cout << swap_count << endl;
    return 0;
}

void bubble_sort(int a[], int len)
{
    bool flag = 1;
    for (int i = 0; flag; i++)
    {
        flag = 0;
        for (int j = len - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                swap_count++;
                flag = 1;
            }
        }
    }
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
