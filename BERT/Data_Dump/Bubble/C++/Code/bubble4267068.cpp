#include <iostream>
using namespace std;

void bubbleSort(int *a, int n)
{
}
int main()
{
    int n = 0, a[105];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int sp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                sp++;
            }
        }
    }

    for (int i = 0; i < n; i++)
     {  
         if (i) cout<<" ";
          cout << a[i];
     }
    cout << endl;
    cout << sp << endl;
    return 0;
}
