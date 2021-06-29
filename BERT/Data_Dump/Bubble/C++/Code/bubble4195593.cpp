#include<iostream>
using namespace std;
int bubble(int a[],int n)
{
	int count=0;
	bool flag=1;
	for(int i=0;flag;i++)
	{
		flag=0;
		for(int j=n-1;j>=i+1;j--){
			if ( a[j] < a[j - 1] ) { 
			// 交换相邻元素 
			swap(a[j],a[j - 1] ); 
			flag = 1;
             count++;	
		}
	}	
  }
  return count;
}

int main(){
	int a[100],n,count;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	count=bubble(a,n);
    for(int i=0;i<n;i++)
    {
    	if(i) cout<<" ";
    	cout<<a[i];
	}
	cout<<endl;
	cout<<count<<endl;
	return 0;
}
