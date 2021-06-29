#include<stdio.h>
#include<string.h>
void select(int t[],int q);
/*int erfen(int t[],int key,int q);*/ 
int main() {
	int n,q,i,j,time=0,key;
	scanf("%d",&n);
	int s[n];
	for(i=0; i<n; i++)
	scanf("%d",&s[i]);
	scanf("%d",&q);
	int t[q];
	for(i=0; i<q; i++)
	scanf("%d",&t[i]);//输入
	//select(s,n);
	for(i=0; i<q; i++) {
		key=t[i];
		time=time+erfen(s,key,n);
	}
	printf("%d\n",time);
	return 0;
}
/*void select(int t[],int q) {
	int i,j,min,mid;
	for(i=0; i<q; i++) {
		min=i;
		for(j=i; j<q; j++) {
			if(t[j]<t[min])
				min=j;
		}
		if(min!=i) {
			mid=t[i];
			t[i]=t[min];
			t[min]=mid;
		}
	}
}*/ 
int erfen(int t[],int key,int q) {
	int left=0,right=q;
	while(left<right) {
		int mid=(left+right)/2;
		if(t[mid]==key)
			return 1;
		else if(t[mid]>key) {
			right=mid;
		} else if(t[mid]<key) {
			left=mid+1;
		}
	}
	return 0;
}
