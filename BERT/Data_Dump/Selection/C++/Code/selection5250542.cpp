# include <iostream>

using std :: cout; using std :: endl; using std :: cin;

int main(void)
{
    long long int n,i,j,k,m,sum=0,min;
    long long int a[104];
    cin>>n;

    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
    {
        min=i;
        for(j=i;j<=n;j++)
        {
            if( a[j]<a[min] )
            {
                min=j;
            }
        }

        k=a[i];  a[i]=a[min]; a[min]=k;
        if(min!=i)
            sum++;
    }

    for(i=1;i<=n;i++)
    {
        if( i>1 )
            cout<<' ';

        cout<<a[i];
    }
    cout<<endl<<sum<<endl;

    return 0;
}

