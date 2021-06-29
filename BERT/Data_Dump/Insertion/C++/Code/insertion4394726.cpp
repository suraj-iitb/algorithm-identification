#include <iostream>

using namespace std;

void print(int* array, int N)
{
    for(int i=0;i<N;++i)
    {
        if(i) cout << " ";
        cout << array[i];
    }
    cout << endl;
}

void sort(int* array, int N)
{
    for(int i=0;i<N;++i){
        int v = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > v)
        {
            array[j+1] = array[j];
            --j;
        }
        array[j + 1] = v;
        print(array, N);
    }
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

