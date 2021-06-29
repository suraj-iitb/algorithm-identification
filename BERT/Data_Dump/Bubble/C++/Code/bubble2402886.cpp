#include <iostream>
using namespace std;

int main()
{
    int n, A[200];
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];
    int flag = 1, i = 0, count = 0;
    while(flag)
    {
        flag = 0;
        for(int j=n-1; j>=i+1; j--)
        {
            if(A[j]<A[j-1])
            {
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                flag = 1;
                count++;
            }
        }
        i++;
    }
    for(int k=0; k<n-1; k++)
       cout << A[k] << " ";
    cout << A[n-1] << endl;
    cout << count << endl;
    return 0;
}
