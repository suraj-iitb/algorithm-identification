//By Vlgd
#include<bits/stdc++.h>
using namespace std;
struct card{
	char suit;
	int x;
}a[100000],b[100000];

void merge(card T[],int x,int y){
	if (y-x>1){
		int m=(x+y)/2;
		int p=x,q=m,i=x;
		merge(T,x,m);
		merge(T,m,y);
		while(p<m||q<y){
			if (q>=y||(p<m&&b[p].x<=b[q].x)) T[i++]=b[p++];
			else T[i++]=b[q++];
		}
		for (int i=x;i<y;i++) b[i]=T[i];
	}
}
void msort(int x,int y){
	card c[y-x];
	merge(c,x,y);
}
int part(int p,int r){
	card x=a[r];
	int i=p-1;
	for (int j=p;j<r;j++)
		if(a[j].x<=x.x) swap(a[++i],a[j]);
	swap(a[i+1],a[r]);
	return i+1;
}
void qsort(int x,int y){
	if (y>x){
		int q=part(x,y);
		qsort(x,q-1);
		qsort(q+1,y);
	}
}
main(){
	int n,xx;char ch[2];
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s%d",ch,&xx);
		a[i].suit=b[i].suit=ch[0];
		a[i].x=b[i].x=xx;
	}
	msort(0,n);
	qsort(0,n-1);
	bool iss=true;
	for (int i=0;i<n;i++){
		if (a[i].suit!=b[i].suit){
			iss=false;
			break;
		}
	}
	if (iss) printf("Stable\n");
	else printf("Not stable\n");
	for (int i=0;i<n;i++) printf("%c %d\n",a[i].suit,a[i].x);
}
