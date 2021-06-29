#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define maxn 100000
int nums[maxn];
int n;
void print()
{
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
            cout<<nums[i]<<" ";
        else
            cout<<nums[i]<<endl;
    }
}
void insertionSort()
{
    print();
    for(int i=1;i<n;i++)
    {
        int key=nums[i];
        int j=i-1;
        while(nums[j]>key&&j>=0)
        {
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
        print();
    }
}
int main()
{
    while(cin>>n)
    {
        int num;
        for(int i=0;i<n;i++)
            scanf("%d",&nums[i]);
        insertionSort();
    }
    return 0;
}
