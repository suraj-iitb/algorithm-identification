
#include<iostream>
using namespace std;
int selectionSort(int a[],int N)
{
    int sw=0;
    int temp;

    for(int j=0;j<N-1;j++)//??????????¬???°
    {
        int k=j;
        for(int i=j+1;i<N;i++){
            if(a[i]<a[k]){
                k=i;

            }

        }
        temp=a[j];
        a[j]=a[k];
        a[k]=temp;
        if(j!=k)
            sw++;

    }
    return sw;
}








int main()
{
    int N,sw;
    cin>>N;
    int a[100];
    for(int i=0;i<N;i++)
        cin>>a[i];
    sw=selectionSort(a,N);
    for(int i=0;i<N;i++)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<sw<<endl;
}
