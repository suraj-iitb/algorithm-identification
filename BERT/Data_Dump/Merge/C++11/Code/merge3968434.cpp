# include <iostream>
using namespace std;
int n,*a,cnt = 0;
void Merge(int left,int mid,int right)
{
	int n1 = mid-left,n2 = right-mid;
	int *L,*R;
	L = new int [n1+1]; R = new int [n2+1];
	for(int i = 0;i < n1;i++) L[i] = a[left+i];
	for(int i = 0;i < n2;i++) R[i] = a[mid+i];
	L[n1] = R[n2] = 1e9+1;
	int i = 0,j = 0;
	for(int k = left;k < right;k++)
	{
		cnt++;
		if(L[i] <= R[j]) a[k] = L[i++];
		else a[k] = R[j++];
	}
}
void Merge_Sort(int left,int right)
{
	if(right-left <= 1) return ;
	int mid = (left+right)/2;
	Merge_Sort(left,mid);
	Merge_Sort(mid,right);
	Merge(left,mid,right); 
}
int main(void)
{

	scanf("%d",&n); a = new int [n];
	for(int i = 0;i < n;i++) scanf("%d",&a[i]);
	Merge_Sort(0,n);
	for(int i = 0;i < n;i++) printf("%d%c",a[i],(i == n-1)?'\n':' ');
	printf("%d\n",cnt);
	return 0;
}
