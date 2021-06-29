#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> A;

int bubbleSort(int n)
{
    bool flag = 1;
    int counter = 0;

    while (flag) {
        flag = 0;

        for (int i = n-1; i > 0; --i) {
            if (A[i-1] > A[i]) {
                swap(A[i-1], A[i]);
                flag = 1;
                counter++;
            }
        }
    }
    return counter;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    int counter = bubbleSort(n);

    for (int i = 0; i < n-1; ++i) {
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl;
    cout << counter << endl;
    return 0;
}
