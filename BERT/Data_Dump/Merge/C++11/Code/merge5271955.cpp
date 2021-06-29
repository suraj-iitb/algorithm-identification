# include <iostream>

using std :: endl; using std :: cin; using std :: cout;
#define max 2000000000
int a[500004];
int L[250004],R[250004],sum;

void f2(int n,int left,int mid,int right)
{
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++) L[i]=a[left+i];
    for(int i=0;i<n2;i++) R[i]=a[mid+i];

    L[n1]=R[n2]=max;
    int i=0,j=0;
    for(int k=left;k<right;k++)
    {
        sum++;
        if( L[i]<=R[j] )
            a[k]=L[i++];
        else
            a[k]=R[j++];
    }
}

void f1(int n,int left,int right)
{
    //cout<<left<<" "<<right<<endl;
    if( left+1<right )
    {
        int mid=(left+right)/2;
        f1(n,left,mid);
        f1(n,mid,right);
        f2(n,left,mid,right);
    }
}

int main(void)
{
    int i,j,k,m,n;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    f1(n,0,n);

    for(i=0;i<n;i++)
    {
        if( i )
            cout<<" ";
        cout<<a[i];
    }

    cout<<endl;
    cout<<sum<<endl;

    return 0;
}

