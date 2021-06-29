#include<bits/stdc++.h>
using namespace std;
int n, a[500010], b[500010], cnt = 0;
void merge(int l, int mid, int r){
	int n1 = mid - l, n2 = r - mid;
	int T = r - l, i = 0, j = 0, now = 0;
	while(T--){
		cnt++;
		if(i == n1){
			b[now++] = a[mid + j];
			j++;
		}
		else if(j == n2){
			b[now++] = a[l + i];
			i++;
		}
		else if(a[l + i] < a[mid + j]){
			b[now++] = a[l + i];
			i++;
		}
		else{
			b[now++] = a[mid + j];
			j++;
		}
		
	}
	for(int i = 0; i < now; i++) a[l + i] = b[i];
	//for(int i = 0; i < now; i++) printf("%d ", b[i]);
	//printf("\n");
}
void MergeSort(int l, int r){
	if(l + 1 >= r) return;
	int mid = (l + r) / 2;
	MergeSort(l, mid);
	MergeSort(mid, r);
	merge(l, mid, r);
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	MergeSort(0, n);
	for(int i = 0; i < n - 1; i++) printf("%d ", a[i]);
	
	printf("%d\n%d\n", a[n-1], cnt);
	return 0; 
}
