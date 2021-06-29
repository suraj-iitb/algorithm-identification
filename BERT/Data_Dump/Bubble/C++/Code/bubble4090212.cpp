/**
 * Program name:Bubble Sort
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

int BubbleSort(int data[], int length, bool ascent)
{
    bool continueOrNot = true;
    int count=0;

    for (int i = 0; (i < length - 1) && continueOrNot; i++)
    {
        continueOrNot = false;

        for (int j = length - 1; j > i; j--)
        {
            int tmp = 0;

            if (ascent && (data[j] < data[j - 1]))
            {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
                continueOrNot = true;
                count++;
            }
            else if (!ascent && (data[j] > data[j - 1]))
            {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
                continueOrNot = true;
                count++;
            }
        }
    }
    return count;
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

    count=BubbleSort(R, n, true);
    trace(R, n);
    cout << count << endl;

    return 0;
}
