#include<iostream>
using namespace std;

int main(){
    int n,A[100];
    int x = 0;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }

    for(int i=0;i<n;i++)
    {
        int minj = i;
        for(int j=i;j<n;j++)
        {
            if(A[j]<A[minj])
            {
                minj = j;
            }
        }

    if(i!=minj)
    {
        int v = A[i];
        A[i] = A[minj];
        A[minj] = v;
        x++;
    }

    }

    for(int i=0;i<n;i++)
    {
        if(i==0) cout << A[i];
        else cout << " " << A[i];
    }

    cout << endl;
    cout << x << endl;
}
