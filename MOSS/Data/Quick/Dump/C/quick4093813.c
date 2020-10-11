#include<stdio.h>
#include<string.h>
#define nMAX 100000
#define INF (1<<30)

typedef struct{char ch; int num;}card;
card in[nMAX],A[nMAX],L[nMAX],R[nMAX];

//{{{ quick
int Partition(int L,int R){
	int x=A[R].num, i=L-1, j;
	card tmp;

	for(j=L;j<R;j++){
		if(A[j].num<=x){
			++i;

			// swap(A[i].A[j])
			tmp=A[i];
			A[i]=A[j];
			A[j]=tmp;
		}
	}
	tmp=A[R];
	A[R]=A[i+1];
	A[i+1]=tmp;

	return i+1;
}

void QuickSort(int L, int R){
	int mid;
	if(L<R){
		mid=Partition(L,R);
		QuickSort(L,mid-1);
		QuickSort(mid+1,R);
	}
}
//}}}
//{{{ merge
void merge(card* A, int l, int mid, int r){
	int n1,n2,i,j,k;
	n1=mid-l;	n2=r-mid;
	for(i=0;i<n1;i++){
		L[i]=A[l+i];
	}
	for(int i=0;i<n2;i++){
		R[i]=A[mid+i];
	}
	L[n1].num=R[n2].num=INF;

	i=j=0;
	for(k=l;k<r;k++){
		if(L[i].num<=R[j].num){
			A[k]=L[i++];
		}else{
			A[k]=R[j++];
		}
	}
}

void MergeSort(card* A, int l, int r){
	int mid;
	if(r-l>1){
		mid=(l+r)/2;
		MergeSort(A,l,mid);
		MergeSort(A,mid,r);
		merge(A,l,mid,r);
	}
}

//}}}

int main(){
	int i,n;	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %c %d",&in[i].ch, &in[i].num);
		//printf("%c %d\n",in[i].ch, in[i].num);
		A[i]=in[i];
	}
	QuickSort(0,n-1);
	MergeSort(in,0,n);

	int flag=1;
	for(i=0;i<n;i++){
		if(!(in[i].ch==A[i].ch && in[i].num==A[i].num)){
			flag=0;	break;
		}
	}

	if(flag==0)printf("Not stable\n");
	else printf("Stable\n");

	for(i=0;i<n;i++){
		//printf("%d: ",i);
		printf("%c %d\n",A[i].ch, A[i].num);
		//printf("in; %c %d\n",in[i].ch, in[i].num);
	}

	return 0;
}

