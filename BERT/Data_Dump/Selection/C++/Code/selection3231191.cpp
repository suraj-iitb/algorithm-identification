#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
    if(b<a)
    {
        int i;
        i=a;
        a=b;
        b=i;
    }
}

int SelectSort(int n,int *p)
{
    int num=0,mini;
    for(int i=0;i<n-1;i++)
    {
        mini=i;
        for(int j=i+1;j<n;j++)
        {
            if(*(p+j)<*(p+mini))
            {
               mini=j;
            }
            
        }
        if(mini!=i)
        {
            swap(*(p+i),*(p+mini));
            num++;
        }
    }
    return num;
}

int main(int argc, char const *argv[])
{
    int N,*p,num;
    cin>>N;
    p=new int[N];
    for(int i=0;i<N;i++)    cin>>*(p+i);
    num=SelectSort(N,p);

    for(int i=0;i<N-1;i++)  cout<<*(p+i)<<" ";
    cout<<*(p+N-1)<<endl<<num<<endl;

    delete []p;
    //system("pause");
    return 0;
}

