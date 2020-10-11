#include<stdio.h>
#include<stdlib.h>

#define INFINITY 2000000000
#define MAX 100000

int cnt=0;

struct card{
    char alp;
    int num;
};

struct card L[MAX/2+2],R[MAX/2+2];

void merge(struct card a[],int n,int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++){
		L[i]=a[left+i];
	}
	for(int i=0;i<n2;i++){
		R[i]=a[mid+i];
	}
	L[n1].num=INFINITY;
	R[n2].num=INFINITY;
	int i=0;
	int j=0;
	for(int k=left;k<right;k++){
		cnt++;
		if(L[i].num<=R[j].num){
			a[k]=L[i];
			i++;
		}else{
			a[k]=R[j];
			j++;
		}
	}
}

void msort(struct card a[],int n,int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		msort(a,n,left,mid);
		msort(a,n,mid,right);
		merge(a,n,left,mid,right);
	}
}

int partition(struct card a[],int n,int p,int r){
    int i,j;
    struct card t,x;
    x=a[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(a[j].num<=x.num){
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

void quicksort(struct card a[],int n,int p,int r){
    int q;
    if(p<r){
        q=partition(a,n,p,r);
        quicksort(a,n,p,q-1);
        quicksort(a,n,q+1,r);
    }
}

int main(void){

	int n,v;
    struct card a[MAX],b[MAX];
    char s[10];
    int stable=1;
    
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%s %d",s,&v);
        a[i].alp=b[i].alp=s[0];
        a[i].num=b[i].num=v;
	}
	
	msort(a,n,0,n);
	quicksort(b,n,0,n-1);
	
	for(int i=0;i<n;i++){
        if(a[i].alp!=b[i].alp)stable=0;
    }

    if(stable==1)printf("Stable\n");
    else printf("Not stable\n");
    for (int i = 0; i < n; i++){
        printf("%c %d\n",b[i].alp,b[i].num);
    }
    
	return 0;
}
