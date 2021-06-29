#include <iostream>

using namespace std;

int main()
{
    int m, a[1000], j,i;

    cin>>m;
    for(int i = 0; i<m; i++)
    {
        cin>>a[i];
    }
     for (int k = 0; k < m; k++)
    {
        if (k == 0)
        {
            cout << a[k] << flush;
        }
        else
        {
            cout << " " << a[k] << flush;
        }
    }
    cout<<endl;
    for(j = 1; j<m; j++)
    {
        int key = a[j];
        //cout<<"key:"<<key;
        for( i = j-1; i>=0 && a[i] >key; i--)
        {
            a[i+1] = a[i];
            //cout<<"key:"<<a[i+1]<<endl;
        }
        //cout<<"key:"<<key;
        a[i+1]=key;
        //cout<<"key:"<<a[i+1]<<endl;
        for(int n=0; n<m; n++)
        {
            if(n>0)
                cout<<" ";
            cout<<a[n];
        }
        cout<<endl;
    }


    return 0;
}
