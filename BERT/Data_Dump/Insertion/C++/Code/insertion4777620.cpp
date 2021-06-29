#include <iostream>
using namespace std;

int main() 
{
    int N, q[100],k=q[0];
    cin >> N;
    for (int i = 0; i < N; i++)  cin >> q[i];
    for (int i = 0; i < N; i++) 
    {
        for (int ii = 0; ii < N-1; ii++) cout << q[ii] << " "; cout << q[N - 1] << endl;
        for (int j = 0; j < i+1; j++) 
        {
            if (q[i - j] > q[i + 1 - j])  swap(q[i - j], q[i + 1 - j]);
            else break;
        }
    }
}
