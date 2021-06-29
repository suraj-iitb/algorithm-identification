# include <iostream>

using std :: cout; using std :: endl; using std :: cin;

int main(void)
{
    long long int n,i,j,k,m;
    long long int a[104];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(i=1;i<=n;i++)
    {
        if(i>1)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;

    for(i=2;i<=n;i++)
    {
        j=a[i];
        k=i-1;
        while( k>0 && a[k]>j )
        {
            a[k+1]=a[k];
            k--;
        }
        a[k+1]=j;

        for(m=1;m<=n;m++)
        {
            if(m>1)
                cout<<" ";
            cout<<a[m];
        }
        cout<<endl;
    }

    return 0;
}

