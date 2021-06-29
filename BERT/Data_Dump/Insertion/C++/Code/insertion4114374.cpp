#include <iostream>
using namespace std;

int sort(int* &num, int size)
{
    for(int i = 0; i < size; i++)
    {
        int j = i;
        int temp = num[j];
        for(j = i - 1; j >= 0 && temp < num[j]; j--)
        {
            num[j + 1] = num[j];
        }
        num[j + 1] = temp;
        for(int t = 0; t < size; t++)
        {
            if(t != 0)
                cout << " ";
            cout << num[t];
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    int count = 0;
    cin >> count;
    int *num = new int[count];
    for(int i = 0; i < count; i++)
    {
        cin >> num[i];
    }
    sort(num, count);
    return 0;
}
