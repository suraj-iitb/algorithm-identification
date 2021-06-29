
#include<iostream>
using namespace std;

int main()
{
    int n,m=0;
    cin>>n;
    int arr[n];
   
    
    for(int i=0 ; i<n;i++)
        cin>>arr[i];
    
   
    
    int mini,temp;
    
	for (int i=0; i < n-1; i++)
	{
        
	    mini = i;
		
        
        
		for (int j=i+1; j < n; j++)
           if (arr[j] < arr[mini])
                mini=j;
        
		
        
        if (mini != i)
        {
            temp = arr[i];
            arr[i] = arr[mini];
            arr[mini] = temp;
            m++;
        }
        
        
        
	}

    for(int i=0 ; i<n-1;i++)
        cout<<arr[i]<<" ";
    cout<<arr[n-1]<<endl;
    
    cout<<m<<endl;
    
	return 0;
}
