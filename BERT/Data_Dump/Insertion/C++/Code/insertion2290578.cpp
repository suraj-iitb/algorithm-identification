#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int a[105];
    for(int i=0;i<N;i++)
        cin>>a[i];
        int first=1;
        for(int j=0;j<N;j++)
        {
            if(first)
                first=0;
            else
                cout<<" ";
            cout<<a[j];

        }
         cout<<endl;
    for(int i=1;i<N;i++)
    {
        int f=1;

        int v=a[i];
        int j;
        j=i-1;
        while(j>=0&&a[j]>v)
        {
            a[j+1]=a[j];
            j--;
            a[j+1]=v;
        }
        for(int i=0;i<N;i++)
        {
            if(f)
                f=0;
            else
                cout<<" ";
            cout<<a[i];

        }
        cout<<endl;


    }

        return 0;

}
