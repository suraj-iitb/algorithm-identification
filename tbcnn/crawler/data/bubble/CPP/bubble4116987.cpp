#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sort(int* &num, int size)
{
    int flag = 1;
    int step = 0;
    while(flag)
    {
        flag = 0;
        for(int j = size - 1; j > 0; j--)
        {
            if(num[j] < num[j - 1])
            {
                swap(&num[j], &num[j - 1]);
                step++;
                flag = 1;
            }
        }
    }
    return step;
}

int main()
{
    int size = 0;
    cin >> size;
    int *num = new int[size];
    for(int i = 0; i < size; i++)
    {
        cin >> num[i];
    }
    int step = sort(num, size);
    for(int t = 0; t < size; t++)
    {
        if(t)
            cout << " ";
        cout << num[t];
    }
    cout << endl;
    cout << step << endl;
    return 0;
}
