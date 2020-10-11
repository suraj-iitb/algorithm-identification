#include<stdio.h>
#define M 100000
#define SE 2000000000

struct C{
	char su;
	int va;
};

struct C l[M/2+2],r[M/2+2];

void me(struct C a[],int n,int left,int mid,int right){
	int i,j,k;
	int n1=mid-left;
	int n2=right-mid;
	for(i=0;i<n1;i++)l[i]=a[left+i];
	for(i=0;i<n2;i++)r[i]=a[mid+i];
	l[n1].va=r[n2].va=SE;
	i=j=0;
	for(k=left;k<right;k++){
		if(l[i].va<=r[j].va){
			a[k]=l[i++];
		}else{
			a[k]=r[j++];
		}
	}
}

void meS(struct C a[],int n,int left,int right){
	int mid;
	if(left+1<right){
		mid=(left+right)/2;
		meS(a,n,left,mid);
		meS(a,n,mid,right);
		me(a,n,left,mid,right);
	}
}

int par(struct C a[],int n, int p,int r){
	int i,j;
	struct C t,x;
	x=a[r];
	i=p-1;
	for(j=p;j<r;j++){
		if(a[j].va<=x.va){
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	t=a[i+1];
	a[i+1]=a[r];
	a[r]=t;
	return i+1;
}

void quick(struct C a[],int n, int p, int r){
	int q;
	if(p<r){
		q=par(a,n,p,r);
		quick(a,n,p,q-1);
		quick(a,n,q+1,r);
	}
}

int main(){
	int n,i,v;
	struct C a[M],b[M];
	char s[10];
	int stable=1;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%s %d",s,&v);
		a[i].su=b[i].su=s[0];
		a[i].va=b[i].va=v;
	}
	
	meS(a,n,0,n);
	quick(b,n,0,n-1);
	
	for(i=0;i<n;i++){
		if(a[i].su!=b[i].su)stable=0;
	}
	
	if(stable==1)printf("Stable\n");
	else printf("Not stable\n");
	for(i=0;i<n;i++){
		printf("%c %d\n",b[i].su,b[i].va);
	}
	
	return 0;
}
