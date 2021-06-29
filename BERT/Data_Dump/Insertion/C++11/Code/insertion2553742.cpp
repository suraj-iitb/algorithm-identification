#include <iostream>
using namespace std;

int arr[100];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        for (int k = 0; k < n - 1; k++)
            cout << arr[k] << ' ';
        cout << arr[n-1] << endl;
    }
    return 0;
}
