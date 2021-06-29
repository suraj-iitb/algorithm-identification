#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> A;

void insertionSort(int n)
{
    for (int i = 0; i < n; ++i) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        for (int k = 0; k < n-1; ++k) {
            cout << A[k] <<" ";
        }
        cout << A[n-1] << endl;
   }

    return;
}

int main ()
{
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    insertionSort(n);

    return 0;
}
