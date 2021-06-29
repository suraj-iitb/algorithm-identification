#include <iostream>


using namespace std;

int main()
{
    int n,i,j,v,k;
    cin >> n;
    int array[n];
    for (i=0;i<n;i++){
        cin>>array[i];
    }
    for (k=0;k<n;k++){
        cout << array[k] << ((k==n-1)?'\n':' ');
    }
    for (i=1;i<n;i++){
        j=i-1;
        v=array[i];
        while(j>=0 and v<array[j]){
            array[j+1]=array[j];
            j--;
        }

        array[j+1]=v;
        for (k=0;k<n;k++){
            cout << array[k] << ((k==n-1)?'\n':' ');
        }
    }

}

