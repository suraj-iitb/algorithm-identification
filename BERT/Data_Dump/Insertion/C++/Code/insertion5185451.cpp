#include <iostream>

using namespace std;
int main()
{
    int A[100];
    int i,j,k,size;

    cin>>size;
    for(i = 0; i<size; i++)
        cin>>A[i];
    
    for(k =0; k<size-1; k++)
    {
        cout<<A[k]<<' ';
    }
    cout<<A[k]<<endl;
    for(i = 1; i<size; i++)
    {
        int key = A[i];
        j = i-1;
        while(j >= 0 && A[j]>key)
        {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = key;
        for(k =0; k<size-1; k++)
        {
            cout<<A[k]<<' ';

        }
        cout<<A[k]<<endl;
    }




}


