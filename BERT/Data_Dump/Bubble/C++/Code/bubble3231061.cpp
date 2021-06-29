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

int ButtleSort(int n,int *p)
{
    int num=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(*(p+j)<*(p+j-1))
            {
                swap(*(p+j-1),*(p+j));
                num++;
            }
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
    num=ButtleSort(N,p);
  // swap(*(p+1),*(p+2));
    for(int i=0;i<N-1;i++)  cout<<*(p+i)<<" ";
    cout<<*(p+N-1)<<endl<<num<<endl;

    delete []p;
    //system("pause");
    return 0;
}

