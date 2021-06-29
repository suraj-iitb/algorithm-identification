#include <iostream>
using namespace std;

int main() {
    int N, v, j;
    cin >> N;
    int array[N];
    for(int i = 0; i < N; i++)
    {
        cin >> array[i];
        if(i > 0)
            cout << " ";
        cout << array[i];
    }
    cout << endl;
    for(int i = 1; i <= N - 1; i++)
    {
        v = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > v)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = v;
        for(int k = 0; k < N; k++)
        {
            if(k > 0)
                cout << " ";
            cout << array[k];
        }
        cout << endl;
    }
    return 0;
}
