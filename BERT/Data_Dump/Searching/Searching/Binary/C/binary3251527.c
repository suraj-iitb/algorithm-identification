# include <stdio.h>
int main()
{
	int a[100001];
	int q;
	int n;
		int number = 0;
	scanf("%d",&n);
	int middle;
	for(int i = 0;i < n; i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	int num = 0;
	for(int i = 0; i < q; i++)
	{
		int ccc;
		scanf("%d", &ccc);
		int low = 0;
		int high = n-1;
	
		while(low<=high)
		 {
		 		 middle = (low +high )/2;
		 		if (a[middle] < ccc)  low = middle+1;
		 		else if (a[middle] > ccc)  high = middle-1; 
		 		else if (a[middle] == ccc)	{
				++num;
				low = high +1;
				}
		 }
	}
	printf("%d\n",num);
 } 
