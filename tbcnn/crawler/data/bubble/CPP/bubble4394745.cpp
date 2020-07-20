#include <iostream>

using namespace std;

void sort(int* array, int N)
{
    bool flag = true;
    int count = 0;
    while(flag)
    {
        flag = false;
        for(int i=N-1;i>0;--i)
        {
            if(array[i] < array[i-1])
            {
                swap(array[i], array[i-1]);
                ++count;
                flag = true;
            }
        }
    }

    for(int i=0;i<N;++i)
    {
        if(i) cout << " ";
        cout << array[i];
    }
    cout << endl << count << endl;
}

int main()
{
    int array[100];
    int N;
    cin >> N;
    for(int i=0;i<N;++i)
    {
        cin >> array[i];
    }
    sort(array, N);
}

