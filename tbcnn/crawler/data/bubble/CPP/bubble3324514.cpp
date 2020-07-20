#include<iostream>
using namespace std;
int main()
{
	int n; 
	cin>>n;
	int a[n];
			for(int i=0;i<n;i++)
			{
			cin>>a[i];
			
			}
	int kazu=0;
	for(int j=0;j<=n;j++)
	{
			int flag=0;
				for(int i=1;i< n;i++)
				{
					if(a[i]<a[i-1])
					{
						flag=1;
					int x=a[i];
						a[i]=a[i-1];
						a[i-1]=x;
					
					
						kazu++;
					}
				
				}
							if(flag==0)
							{	
							break;
								}

		}
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)
		{
		cout<<a[i]<<" ";
		}
		else
		{
		cout<<a[i]<<endl;
		}
		
	}
	
	cout<<kazu<<endl;
		
		
	
}



