#include <iostream>

using namespace std;

int main()
{
    int n,i,j,temp;
    int count=0;
    cin >> n;
    int array[n];
    for (i=0;i<n;i++){
        cin>>array[i];
    }
    for (i=0;i<n;i++){
        for (j=n-1;j>i;j--){
            if(array[j]<array[j-1]) {
                temp=array[j];
                array[j]=array[j-1];
                array[j-1]=temp;
                count++;
            }

        }
    }
    for (i=0;i<n;i++){
        cout<<array[i]<<((i==n-1)?"\n":" ");
    }
    cout<<count<<endl;

}

