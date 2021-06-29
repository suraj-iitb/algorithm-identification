#include <iostream>
using namespace std;

int main()
{
    int n, A[200];
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];
    int count = 0;
    for(int i=0; i<n; i++)//??????????°??????´??\?????´????´??????¢
    {
        int minj = i;
        for(int j=i+1; j<n; j++)
        {
            if(A[j]<A[minj])
            {
                minj = j;
            }
        }
        int temp = A[i];
        A[i] = A[minj];
        A[minj] = temp;
        if(i!=minj)
          count++;
    }
    for(int i=0; i<n-1; i++)
       cout << A[i] << " ";
    cout << A[n-1] << endl;
    cout << count << endl;
    return 0;
}
