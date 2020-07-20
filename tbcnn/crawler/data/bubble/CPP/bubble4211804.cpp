#include <iostream>
#include <vector>

using namespace std;
int bubbleSort(vector<int> &A)
{
    int count = 0;
    int N = A.size();
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int j = N - 1; j >= 1; j--)
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]);
                flag = true;
                count++;
            }
        }
    }
    return count;
}
void print(const std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int count = bubbleSort(A);
    print(A);
    cout << count << endl;
    return 0;
}
