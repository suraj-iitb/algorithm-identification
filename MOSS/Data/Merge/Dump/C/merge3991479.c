#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define scani(x) scanf("%d",&x)
#define scanc(x) scanf("%s",x)
#define printi(x) printf("%d",x)
#define printin(x) printf("%d\n",x)
#define printc(x) printf("%s",x)
#define repd(i,n,m) for(int i = n; i > m; i--)
#define repu(i,n,m) for(int i = n; i < m; i++)
#define allprintu(i,n,m,a) for(int i = n; i < m; i++){if(i != m-1){printf("%d ",a[i]);}else{printf("%d\n",a[i]);}}
#define allprintd(i,n,m,a) for(int i = n; i > m; i--){if(i != 0){printf("%d ",a[i]);}else{printf("%d\n",a[i]);}}
	
#define MAX 500000
int n;
int s[MAX];
int count;
void initialize(){
	count = 0;
}
void merge(int A[], int left, int mid, int right){
	int n1 = mid - left, n2 = right - mid;
	int *L = (int*)malloc(sizeof(int)*(n1+1));
	int *R = (int*)malloc(sizeof(int)*(n2+1));
	repu(i,0,n1){
		L[i] = A[left + i];
	}
	repu(i,0,n2){
		R[i] = A[mid + i];
	}
	L[n1] = (int)(pow(10,9)+1);
	R[n2] = (int)(pow(10,9)+1);
	int i = 0;
	int j = 0;
	repu(k,left,right){
		count++;
		if(L[i] <= R[j]){
			A[k] = L[i];
			i = i + 1;
		}else{
			A[k] = R[j];
			j = j + 1;
		}
	}
	free(L);
	free(R);
}

void mergeSort(int A[], int left, int right){
	if( left + 1 < right){
		int mid = (left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left, mid, right);
	}
}
int main(void){
	initialize();
	scani(n);
	repu(i,0,n){
		scani(s[i]);
	}
	mergeSort(s,0,n);
	allprintu(i,0,n,s);
	printin(count);
	return 0;
}
