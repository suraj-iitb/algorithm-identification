# include <iostream>

using std :: endl; using std :: cin; using std :: cout;
long long int b[2000004],c[2000000];

int main(void)
{
    long long int i,j,k,m,n;
    long long int a[10009]={0};

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>b[i];
        a[b[i]]++;
    }

    for(i=1;i<=10004;i++)
    {
        a[i]=a[i]+a[i-1];
    }

    for(i=1;i<=n;i++)
    {
        c[ a[ b[i] ] ]=b[i];
        a[b[i]]--;
    }

    for(i=1;i<=n;i++)
    {
        if(i!=1)
            cout<<" ";
        cout<<c[i];
    }

    cout<<endl;

    return 0;
}

