
#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n,s[maxn],ans;

void selectionsort()
{
	int minn;
	for(int i=0;i<n-1;i++){
		minn=i;
		for(int j=i+1;j<n;j++){
			if(s[j]<s[minn]){
				minn=j;
			}
		}
		swap(s[minn],s[i]);
		if(i!=minn){
			ans++;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	selectionsort();
	for(int i=0;i<n;i++){
		if(i!=0){
			printf(" ");
		}
		printf("%d",s[i]);
	}
	printf("\n%d\n",ans);
	return 0;
}
/*
6
5 6 4 2 1 3
*/
