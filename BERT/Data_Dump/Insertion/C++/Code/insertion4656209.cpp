#include<iostream>
using namespace std;
void output(int*, int);

int main()
{
    int num;
    cin >> num;
    int* T = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> T[i];
    }
    output(T, num);
    for (int i = 1; i < num; i++)
    {
        int pivot = T[i];
        int j = i - 1;
        while (T[j] > pivot && j >= 0)
        {
            T[j + 1] = T[j];
            T[j] = pivot;
            j--;
        }
        output(T, num);
    }
}

void output(int* T, int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << T[i] << (i == num - 1 ? '\n' : ' ');
    }
}
