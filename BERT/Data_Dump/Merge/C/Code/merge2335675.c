#include <stdio.h>

#define N 10000000
#define M 2000000000
 
int n, S[N];

int count = 0;
 
void merge(int,int);
void Merge(int,int,int);

 
int main() {
 
  int i,left, right;
 
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
      {
	scanf("%d", &S[i]);
      }
    
    left = 0;
    
    right = n;
 
    merge(left, right);
 
    for(i = 0; i < n-1; i++)
      {
	printf("%d ", S[i]);
      }
    
    printf("%d\n", S[n-1]);

    printf("%d\n", count);
 
    return 0;
 
}

void Merge(int left, int mid, int right){
 
    int n1 = mid - left;
    int n2 = right - mid;
 
    int L[n1+1], R[n2+1];
 
    int i, j, k;
 
    for(i = 0; i < n1; i++)
      {
	L[i] = S[left + i];
      }
    
    for(i = 0; i < n2; i++)
      {
	R[i] = S[mid + i];
      }
    
    L[n1] = R[n2] = M;
 
    i = j = 0;
    
    
    for (k = left; k < right; k++)
      {
        count ++;
	
        if(L[i] <= R[j]) S[k] = L[i++];
	
        else S[k] = R[j++];
    }
 
}
 
void merge(int left, int right)
{

  int mid;
 
    if(right - left <= 1) return;
 
    mid = (left + right) / 2;

    merge(left, mid);

    merge(mid, right);
 
    Merge(left, mid, right);
}
