#include<iostream>
#include<algorithm>
using namespace std;
#define max 100000
struct card{char icon;int num;};
int partition(card a[],int p,int r){
int x=a[r].num;
	card no;
	int j,i=p-1;
		for(j=p;j<r;j++){
			if(a[j].num<=x){
				i++;
				no=a[i];
				a[i]=a[j];
				a[j]=no;
			}
		}
	no=a[i+1];
	a[i+1]=a[r];
	a[r]=no;
	return i+1;
}	
void quicks(card a[],int p,int r){
int q;
	if(p<r){
		q=partition(a,p,r);
		quicks(a,p,q-1);
		quicks(a,q+1,r);
	}
}
bool ex(card a[],card b[],int n){
	for(int i=0;i<n;i++){
		if(a[i].icon!=b[i].icon)
		return false;
	}
	return true;
}
void merge(card a[],int left,int mid,int right){
int n1=mid-left,n2=right-mid;
	card L[n1+1],R[n2+1];
	int i,j,k;
	for(i=0;i<n1;i++)L[i]=a[left+i];
	for(i=0;i<n2;i++)R[i]=a[mid+i];
	L[n1].num=R[n2].num=1000000001;
	i=j=0;
	for(k=left;k<right;k++){
		if(L[i].num<=R[j].num){
		a[k]=L[i];
			i++;
		}
		else{
		a[k]=R[j];
			j++;
		}
		
	}
	
}

void merges(card a[],int left,int right){
	int mid;
	if(left+1<right){
		
		mid=(left+right)/2;
		merges(a,left,mid);
		merges(a,mid,right);
		merge(a,left,mid,right);
	}
}
main(){
	card a[max],c[max];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %c %d",&a[i].icon,&a[i].num);
		c[i]=a[i];
	}
	quicks(a,0,n-1);
	merges(c,0,n);
	if(ex(a,c,n))
	printf("Stable\n");
	else printf("Not stable\n");
	for(i=0;i<n;i++)
	printf("%c %d\n",a[i].icon,a[i].num);
	return 0;
}

