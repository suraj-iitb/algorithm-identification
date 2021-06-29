#include<cstdio>
int cnt = 0;
void merge(int * A,int left, int right, int mid);
void mergesort(int *A, int left, int right);
int main()
{
    int n;
    scanf("%d", &n);
    int A[n + 1];//？ 
    for(int i = 0; i < n; i++)
        scanf("%d", A+i);
    mergesort(A, 0, n);
    for(int i = 0; i < n; i++){
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", cnt);
    return 0;
}
void merge(int * A,int left, int right, int mid)
{
    int T1[mid - left + 1], T2[right - mid + 1], i = 0, j = 0;
    for(i = 0; i < mid - left; i++)
        T1[i] = A[left + i];
    T1[i] = 2000000000;
    for(i = 0; i < right - mid; i++)
        T2[i] = A[mid + i];
    T2[i] = 2000000000;
    i = 0;
    for(int k = left; k < right; k++){
	    cnt++; 
	    if(T1[i] <= T2[j]){
	    	A[k] = T1[i];
	        ++i;
	    }
	    else{
	        A[k] = T2[j];
	        ++j;
	    }
	}	
}
void mergesort(int *A, int left, int right)
{
    int mid = (left + right) / 2;
    if(left + 1 < right){
        mergesort(A, left, mid);//前闭后开 
        mergesort(A, mid, right);
        merge(A, left, right, mid);
    }
}
