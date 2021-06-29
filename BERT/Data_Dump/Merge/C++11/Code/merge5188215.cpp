#include<cstdio>
#include<vector>
using namespace std;
void Mergesort(vector<int> &A,int left,int right);
void merge(vector<int> &A,int left,int mid,int right);
int count = 0;
int main()
{
	int n;
	vector<int> a;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		int t;
		scanf("%d",&t);
		a.push_back(t);
	}
//	merge(a,1,2,3);
	Mergesort(a,0,a.size());
	for(int i = 0;i < n - 1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("%d\n",a.back());
	printf("%d\n",count);
	return 0;
}
void Mergesort(vector<int> &A,int left,int right)
{
	if(left + 1 >= right)
		return;
	int mid = (left + right) / 2;
//	printf("left=%d mid=%d right=%d\n",left,mid,right);
//	printf("left->\n");
	Mergesort(A,left,mid);
//	printf("right->\n");
	Mergesort(A,mid,right);
//	printf("merge->\n");
//	for(int i = left;i < right;i++)
//		printf("%d ",A[i]);
//	printf("\n");
	merge(A,left,mid,right);

//	for(int i = left;i < right;i++)
//		printf("%d ",A[i]);
//	printf("\n");
}
void merge(vector<int> &A,int left,int mid,int right)
{
	int i = left,j = mid;
	int n = right - left;
	vector<int> B;
	B.assign(A.begin() + left,A.begin() + right);
//	for(int x = 0;x < B.size();x++)
//		printf("%d ",B[x]);
	
	for(int k = 0;k < n;k++)
	{
		if(i >= mid)
		{
			for(;j < right;j++,k++)
			{
				A[k + left] = B[j - left];
				count++;
			}
			break;
		}
		else if(j >= right)
		{
			for(;i < mid;i++,k++)
			{
				A[k + left] = B[i - left];
				count++;
			}
			break;
		}
		if(B[i - left] <= B[j - left])
		{
			count++;
			A[k + left] = B[i - left];
			i++;
		}
		else
		{
			count++;
			A[k + left] = B[j - left];
			j++;
		}
	}
}
