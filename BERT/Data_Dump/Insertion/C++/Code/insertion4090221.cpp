/**
 * Program name:Insert Sort
 * author:Xin Peng
 * date:2020/1/5
 * Pragram problem source: AOJ
*/
#include <iostream>
using namespace std;

#define MAX 100

/**
 * @brief Trace display
 * @param data Data to display
 * @param length Length of the data
*/
void trace(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << data[i];
        if (i != length - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

// Insert Sort
void InsertSort(int data[], int length, bool ascent, void (*traceHandler)(int data[], int length))
{
    int tmpValue;

    for (int i = 1; i < length; i++)
    {
        tmpValue = data[i];
        int j = i - 1;

        if (ascent)
        {
            while (j >= 0 && data[j] > tmpValue)
            {
                data[j + 1] = data[j];
                j--;
            }
        }
        else
        {
            while (j >= 0 && data[j] < tmpValue)
            {
                data[j + 1] = data[j];
                j--;
            }
        }
        data[j + 1] = tmpValue;

        if (traceHandler)
        {
            traceHandler(data, length);
        }
    }
}

int main()
{
    int n;
    int R[MAX];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> R[i];
    }

    trace(R,n);
    InsertSort(R, n, true, trace);

    return 0;
}
