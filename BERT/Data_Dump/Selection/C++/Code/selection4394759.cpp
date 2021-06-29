#include <iostream>
using namespace std;

void sort(int* array, int N)
{
    int count = 0;
    for(int i=0;i<N;++i)
    {
        int minj = i;
        for(int j=i;j<N;++j)
        {
            if(array[minj] > array[j])
            {
                minj = j;
            }
        }
        if(i != minj){
            swap(array[i], array[minj]);
            ++count;
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
    int N;
    int array[100];
    cin >> N;
    for(int i=0;i<N;++i)
    {
        cin >> array[i];
    }
    sort(array, N);
}

