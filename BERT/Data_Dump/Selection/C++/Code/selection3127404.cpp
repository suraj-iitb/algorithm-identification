#include <iostream>

using namespace std;

int SelectionSort(int *arr,int n)
{
    int min = 0;
    int t = 0;

    for (int i = 0; i < n; i++)
    {
        min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            arr[i]       ^= arr[min];
            arr[min] ^= arr[i];
            arr[i]       ^= arr[min];
            t++;
        }
    }
    return t;
}

int main(int argc, char *argv[])
{
    int Num = 0;
    int Operations = 0;
    cin >> Num;
    int *arr = new int[Num];

    for (int i = 0; i < Num; i++)
    {
        cin >> arr[i];
    }

    Operations = SelectionSort(arr, Num);

    for (int i = 0; i < Num; i++)
    {
        if (i == 0)
        {
            cout << arr[i];
        }
        else
        {
            cout << " " << arr[i];
        }
    }
    cout << "\n" << Operations << endl;

    return 0;
}
