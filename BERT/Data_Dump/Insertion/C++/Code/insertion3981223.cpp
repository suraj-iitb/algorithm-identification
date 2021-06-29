#include <iostream>
#include <vector> 
//#include <climits>
using namespace std;


int main() {

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }


    for (int i = 1; i <= N; ++i)
    {

        for (int i = 0; i < N; ++i)
        {
            cout << A[i];
            if(i != N-1) {
                cout << " ";
            }
        }
        cout << endl;

        int v = A[i];
        int j = i - 1;

        while(j>=0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }

    return 0;
}