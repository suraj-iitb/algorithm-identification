#include<stdio.h>

long long int count=0;
void merge(long long int a[], int left, int mid, int right) 
{ 
    int p,o,k; 
    int n1 = mid - left+1; 
    int n2 =  right-mid; 
    int L[n1], R[n2]; 
  
    for (p = 0; p < n1; p++) //左半分の数列を登録
        L[p] = a[left + p]; 
       
    for (o = 0; o < n2; o++) //右半分の数列を登録
        R[o] = a[mid + 1+ o];
        
    p = 0; 
    o = 0;  
    k = left; 
    while (p < n1 && o < n2) //一つの数列に合併していく
    { 
        if (L[p] <= R[o]) 
        { 
            a[k] = L[p];  count++;
            p++; 
        }
        else
        { 
            a[k] = R[o]; 
            o++;
			count++; 
        } 
        k++; 
     } 
  
    while (p < n1) 
    { 
        a[k] = L[p];  count++;
        p++; 
        k++; 
    } 
  
    while (o < n2) 
    { 
        a[k] = R[o];  count++;
        o++; 
        k++; 
    } 
    
} 
  
void mergesort(long long int a[], int l, int r) 
{ 
    if (l < r) 
    {    
        int m = l+(r-l)/2; 
        mergesort(a, l, m); //左半分に分解したものをさらに二等分に分解させる関数mergesortに入れる
        mergesort(a, m+1, r); //右半分に分解したものをさらに二等分に分解させる関数mergesortに入れる
		merge(a, l, m, r); //ソートした左半分と右半分を一つの配列にする
    } 
} 

long long int num[100000005];
int main()
{
	int a;
	
	scanf("%d",&a); 
	for(int i=0;i<a;i++)
	{
		scanf("%lld",&num[i]);
	}
	
	mergesort(num,0,a-1);
	
	for(int i=0;i<a;i++)
	{
		if (i==0)
		{
			printf("%lld",num[i]);
		}else
		{
			printf("% lld",num[i]);
		}
			
	}	
	printf("\n");
	printf("%lld\n",count);
	
	return 0;
}

