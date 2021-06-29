#include <iostream>
using namespace std;

void output(int n,int *p)
{
    for(int i=0;i<n-1;i++)    cout<<*(p+i)<<" ";
    cout<<*(p+n-1)<<endl;
}

void insertSort(int n,int *p)
{
    int temp,i,j;
    if(n==1)
        output(n,p);
    else
    {
        for( i=0;i<n;i++)
        {
            temp=*(p+i);
            for(j=0;j<i;j++)
            {
                if(*(p+j)>temp)
                {
                    for(int k=i-1;k>=j;k--)   *(p+k+1)=*(p+k);
                    *(p+j)=temp;
                    break; 
                }
            }
            output(n,p);
        } 
    }

}

int main(int argc, char const *argv[])
{
    int N,*p;
    cin>>N;
    p=new int[N];
    for (int i=0;i<N;i++)   cin>>*(p+i);//input array
    insertSort(N,p);
    return 0;
}

