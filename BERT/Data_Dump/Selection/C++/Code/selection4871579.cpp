 #include<iostream>
 #include<cstdio>
 #include<algorithm>
 using namespace std;
 int main()
{
	int n,a[110];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int count=0;
	for(int i=0;i<n-1;i++){
		int mi=i;
		for(int j=i+1;j<n;j++){
			if(a[mi]>a[j]){
				mi=j;
					
			}
		}
		if(mi!=i){
			swap(a[mi],a[i]);
			count++;
		}
		
		
	}
	
	cout<<a[0];
	for(int i=1;i<n;i++){
		cout<<" "<<a[i]; 
	} 
	cout<<endl;
	cout<<count<<endl;
	return 0;
}
