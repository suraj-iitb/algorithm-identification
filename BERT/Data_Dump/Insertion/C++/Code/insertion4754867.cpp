#include<iostream>
#include<algorithm>

using namespace std;
static const int MAX = 100;

void inputArray(
    int Array[],        //[out]
    int& totalCountNum  //[out]
)
{
    cin >> totalCountNum;
    for (int i = 0; i < totalCountNum; i++)
    {
        cin >> Array[i];
    }
}

void outputArray(
    const int Array[],         //[in]
    const int totalCountNum    //[in]   
)
{
    cout << Array[0];
    for (int i = 1; i < totalCountNum; i++)
    {
        cout << " " << Array[i];
    }
    cout << "\n";
}

int main()
{
    int N = 0;
    int A[MAX] = {};

    inputArray(A, N);
    outputArray(A, N);

    for (int i = 1; i < N; i++)
    {
        int v = A[i];
        int j = i - 1;

        while ((j >= 0) && (A[j] > v))
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        outputArray(A, N);
    }

    return 0;
}


