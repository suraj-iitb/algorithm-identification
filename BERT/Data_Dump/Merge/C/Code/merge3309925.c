#include <stdio.h>
int temp[500000],cnt;   
void MergeSort(int x[ ], int left, int right)
{
    int mid, i, j, k;
	if (left >= right)              
        return;                     
    mid = (left + right) / 2;       
    MergeSort(x, left, mid);        
    MergeSort(x, mid + 1, right);   
    for (i = left; i <= mid; i++)
        temp[i] = x[i];
    for (i = mid + 1, j = right; i <= right; i++, j--)
        temp[i] = x[j];
        i = left;         
        j = right;
      
    for (k = left; k <= right; k++) {
        if (temp[i] <= temp[j]) 
            x[k] = temp[i++];
        else 
    x[k] = temp[j--];
    cnt++;
    }
}

int main()
{
    int i,j,n;
    int x[500001];
    scanf("%d",&n);
   for (i = 0; i < n; i++){
        scanf("%d",&x[i]);
   }
    MergeSort(x, 0, n-1);
    printf("%d",x[0]);
    for (i = 1; i < n; i++){
        printf(" %d", x[i]);
    }
    printf("\n%d\n",cnt);
    return 0;
}

