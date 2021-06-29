#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int selectionSort(int a[],int n){
	int ans = 0;
	for(int i = 0; i < n;i++){
		int mini = i;
		for(int j = i; j < n;j++){
			if(a[j] < a[mini])
			mini = j;
		}
		if(i != mini)
		swap(a[i],a[mini]),
		ans++; 
		
	}
	return ans;
}
int main(){
   int n,a[110];
   scanf("%d",&n);
   for(int i = 0; i < n;i++)
   scanf("%d",&a[i]);
   int ans = selectionSort(a,n);
   for(int i = 0;i < n;i++)
   printf("%d%c",a[i],i == n-1?'\n':' ');
   printf("%d\n",ans);
	return 0;
}
