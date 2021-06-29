
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn=105;

int n,ans,s[maxn];

void bubblesort()
{
	int flag=1;
	for(int i=0;flag;i++){
		flag=0;
		for(int j=n-1;j>=i+1;j--){
			if(s[j]<s[j-1]){
				swap(s[j],s[j-1]);
				ans++;
				flag=1;
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	bubblesort();
	for(int i=0;i<n;i++){
		if(i!=0){
			printf(" ");
		}
		printf("%d",s[i]);
	}
	printf("\n");
	printf("%d\n",ans);
	return 0;
}
/*
5
5 3 2 4 1
*/
