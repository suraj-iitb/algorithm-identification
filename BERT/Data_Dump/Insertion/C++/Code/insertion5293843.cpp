#include <iostream>
using namespace std;

void show_card(int *num, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        cout << num[i] << flush;
        if (i < cnt - 1)
            cout << " " << flush;
        else
            cout << endl;
    }
}

void insertionSort(int *num, int ele)
{

    for (int i = 0; i < ele; i++)
    {
        int v = num[i];
        int j = i - 1;

        while (j >= 0 && num[j] > v)
        {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = v;
        show_card(num, ele);
    }
}

int main()
{
    int element;
    cin >> element;

    int *num = new int[element];

    for (int i = 0; i < element; i++)
        cin >> num[i];

    insertionSort(num, element);

    delete[] num;
}
