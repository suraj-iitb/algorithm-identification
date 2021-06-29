# include <stdio.h>
int a[500000];
int n;
int number;
int l[500000];
int r[500000];
void solve(int left,int right,int middle);
void sort(int left,int right);

int main(){
	number = 0;
	scanf("%d",&n);
	for(int i = 0; i < n ; i++)
			scanf("%d",&a[i]);
	sort(0,n);
	for(int i = 0; i < n-1 ; i++)
		printf("%d ",a[i]);
	printf("%d\n%d\n",a[n-1],number);
}

void sort(int left,int right)
{

	if(left < right - 1)
	{
	
		int	middle = (right + left)/2;
		sort(left,middle);
		sort(middle,right);
		solve(left,right,middle);
	}
}

void solve(int left,int right,int middle)
{
	int n1 = middle - left;
	int n2 = right - middle;
	for(int i = 0; i < n1;++i)	l[i] = a[left+i];
	for(int i = 0; i < n2;++i)	r[i] = a[middle+i];
	l[n1] = r[n2] = 10000000000;
	int j = 0;int k = 0;
	for(int i =left;i<right;i++)
	{
		if(l[j]<r[k])
		{
		
			a[i] = l[j];
			j++;
		}else{
			a[i] = r[k];
			k++;
		}
		number++;
	
	}
}

