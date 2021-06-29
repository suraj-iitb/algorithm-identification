#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int swap = 0;
    bool flag = true;
    int count = 0;
    while (flag)
    {
        flag = false;
        for (int i = 1; i < n; i++)
        {
            if (A[i] < A[i-1])
            {
            int s = A[i-1];
                A[i-1] = A[i];
                A[i] = s;
                count += 1;
                flag = true;
            }
        }
    }
    for (int i = 0; i < n-1; i++)
    {
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl;
    cout << count << endl;
}
