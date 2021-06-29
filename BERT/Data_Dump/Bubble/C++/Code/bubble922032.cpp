
#include<iostream>
using namespace std;

int main()
{
 int n,m=0;
    cin>>n;
    int arr[n];
	
    for( int i=0; i<n ;i++ )
       cin>>arr[i];
    

    
    for( int i=1;i<n ;i++ )
        for( int j=0; j<n-1; j++)
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                m++;
                
            }
            
    for( int i=0; i<n-1 ;i++ )
        cout<<arr[i]<<" ";
    cout<<arr[n-1]<<endl;
    
    cout<<m<<endl;


	return 0;
}
