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
    int step = 0;
    int min = 0;
    for(int i = 0; i < size; i++)
    {
        min = i;
        for(int j = i + 1; j < size; j++)
        {
            if(num[j] < num[min])
                min = j;
        }
        if(min != i)
        {
            swap(&num[i], &num[min]);
            step++;
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
