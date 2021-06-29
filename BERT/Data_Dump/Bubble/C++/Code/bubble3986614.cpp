#define _LIBCPP_DEBUG 0

#include <iostream>
#include <vector>

using namespace std;

int BubbleSort(vector<int> A, int N)
{
    int j;
    int flag = 1;
    int count = 0;

    while (flag == 1)
    {
        flag = 0;
        for (j = N-1; j > 0; j--)
        {
            if (A.at(j) < A.at(j-1))
            {
                swap(A.at(j), A.at(j-1));
                flag = 1;
                count++;
            }
        }
        
    }

    for (j = 0; j < N; j++)
    {
        if (j > 0)
        {
            cout << " ";
        }
        cout << A.at(j);
    }
    cout << "\n";
    cout << count << "\n";
    
}

int main() {
    int N, i;
    cin >> N;

    vector<int> vec(N);

    for (i = 0; i < N; i++)
    {
        cin >> vec.at(i);
    }

    BubbleSort(vec, N);
}

