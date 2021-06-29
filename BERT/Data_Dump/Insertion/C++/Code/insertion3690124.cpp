#include<iostream>
using namespace std;
int main()
{
    int N,key;
    int R[100];
    int k;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> R[i];
    for(int i=0; i<N-1; i++)
        cout<<R[i]<<" ";
    cout<<R[N-1]<<endl;
    for(int i=1; i<N; i++)
    {
        key = R[i];
        k = i - 1;
        while(k >=0 && R[k] > key)
        {
            R[k+1] = R[k];
            k--;
        }
        R[k+1] = key;
        for(int i=0; i<N-1; i++)
            cout<<R[i]<<" ";
        cout<<R[N-1]<<endl;
    }

}

