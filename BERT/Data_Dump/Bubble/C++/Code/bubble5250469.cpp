# include <iostream>

using std :: cout; using std :: endl; using std :: cin;

int main(void)
{
    long long int n,i,j,k,m,sum;
    long long int a[104];
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    sum=0;
    bool bj=true;
    for(i=1;bj;i++)
    {
        bj=false;
        for(k=n;k>i;k--)
        {
            if( a[k]<a[k-1] )
            {
                j=a[k]; a[k]=a[k-1]; a[k-1]=j;
                bj=true;
                sum++;
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        if(i>1)  cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<sum<<endl;

    return 0;
}

