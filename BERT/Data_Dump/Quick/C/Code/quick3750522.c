#include <stdio.h>

int par(long*a,int l,int r){
	int pib=a[r-1]/500000;
	int crr=l;
	for(int i=l;i<r;i++){
		if(a[i]/500000<=pib){
			long t=a[crr];
			a[crr]=a[i];
			a[i]=t;
			crr++;
		}
	}
	return crr-1;
}

void qs(long*a,int l,int r){
	if(r-l>1){
		int m=par(a,l,r);
		qs(a,l,m);
		qs(a,m,r);
	}
}

long a[100010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		long t;
		char c;
		scanf(" %c%ld",&c,&t);
		int m=c=='D'?3:c=='H'?2:c=='S';
		a[i]=t*500000+m*100000+i;
	}
	
	qs(a,0,n);
	
	int flag=1;
	for(int i=0;i<n-1;i++)flag&=a[i]/500000<a[i+1]/500000||a[i]%100000<a[i+1]%100000;
	puts(flag?"Stable":"Not stable");
	for(int i=0;i<n;i++){
		int m=a[i]/100000%5;
		printf("%c %d\n",m==3?'D':m==2?'H':m==1?'S':'C',a[i]/500000);
	}
}
