/**
 * Program name:Selection Sort
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

//Selection Sort
void SelectionSort(int data[], int length, bool ascent, void (*traceHandler)(int data[], int length, void *x), void *x, bool firstLoopOrSecond)
{
    int position;

    for (int i = 0; i < length - 1; i++)
    {
        position = i;

        for (int j = i + 1; j < length; j++)
        {
            if (ascent && (data[j] < data[position]))
            {
                position = j;
            }
            else if (!ascent && (data[j] > data[position]))
            {
                position = j;
            }

            if (traceHandler && firstLoopOrSecond)
            {
                traceHandler(data, length, x);
            }
        }
        if (position == i)
        {
            continue;
        }
        int tmp = data[i];
        data[i] = data[position];
        data[position] = tmp;

        if (traceHandler && !firstLoopOrSecond)
        {
            traceHandler(data, length, x);
        }
    }
}

/**
 * @brief Handler for count
 * @param data Data to display
 * @param length Length of the data
 * @param count Count Variable.
*/
void countHandler(int data[], int length, void *count)
{
    int *pp = (int *)count;
    (*pp)++;
}

int main()
{
    int n;
    int R[MAX];
    int count = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> R[i];
    }

    SelectionSort(R, n, true, countHandler, &count, false);
    trace(R, n);
    cout << count << endl;

    return 0;
}
