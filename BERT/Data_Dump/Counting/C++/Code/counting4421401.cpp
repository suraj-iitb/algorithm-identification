#include <iostream>
using namespace std;

const int MAX_NUM = 2000000;
const int MAX_VALUE = 10000;

void counting_sort(int* array1, int* array2, int n)
{
    int k = -1, count[MAX_VALUE] = {};
    for(int i=0;i<n;++i)
    {
        ++count[array1[i]];
        k = max(k, array1[i]);
    }
    for(int i=0;i<k;++i)
    {
        count[i+1] += count[i];
    }
    for(int i=0;i<n;++i)
    {
        array2[--count[array1[i]]] = array1[i];
    }
}

int main()
{
    int n, array1[MAX_NUM], array2[MAX_NUM];
    cin >> n;
    for(int i=0;i<n;++i) cin >> array1[i];
    counting_sort(array1, array2, n);
    for(int i=0;i<n;++i)
    {
        if(i) cout << " ";
        cout << array2[i];
    }
    cout << endl;
}

