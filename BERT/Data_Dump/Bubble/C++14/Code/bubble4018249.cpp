#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

void insetrtionsort(int a[], int n);
void printarray(int n, int a[]);

void insetrtionsort(int a[], int n)
{
    int j, v;
    for (int i = 1; i < n; i++)
    {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

void babblesort(int n, int a[])
{
    int flag = 1;
    int counter = 0;
    int tmp;
    while (flag)
    {
        flag = 0;
        for (int j = n - 1; j > 0; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                counter++;
                flag = 1;
            }
        }
    }
    printarray(n, a);
    cout << counter << endl;
}

void printarray(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
}

int gcd(int a, int b)
{
    if (a < b)
    {
        int t = a;
        a = b;
        b = t;
    }
    cout << a << " " << b << endl;
    if (b == 0)
        return a;
    else
        return gcd(b, b % a);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    babblesort(n, a);
    return 0;
}

