#include<bits/stdc++.h>
using namespace std;
int INF=1e9+7;
int n;
struct mem
{
	char a;//储存字母 
	int digit;//储存数字 
};
struct mem stu[100005],ctu[100005];//stu，ctu分别用于归并排序和快速排序
struct mem R[100005],L[100005];
/*归并排序，归并排序是一种稳定的高级排序*/
int Merge(struct mem stu[],int left,int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++) L[i]=stu[left+i];
	for(int i=0;i<n2;i++) R[i]=stu[mid+i];
	L[n1].digit=INF;
	R[n2].digit=INF;
	int i=0,j=0;
	for(int k=left;k<right;k++)
	{
		if(L[i].digit<=R[j].digit)
		{
			stu[k]=L[i];
			i++;
		}
		else 
		{
			stu[k]=R[j];
			j++;
		}
	 } 
	 return 0;
}
int MergeSort(struct mem stu[],int left,int right)
{
	if(left+1<right)
	{
		int mid=(left+right)/2;
		MergeSort(stu,left,mid);
		MergeSort(stu,mid,right);
		Merge(stu,left,mid,right);
	}
	return 0;
}
/*快速排序*/
int Partition(struct mem ctu[],int p,int r)//这里p,r分别是数组的第一个元素与最后一个元素的位置 
{
	struct mem temp=ctu[r];
	struct mem t;
	int i=p-1;
	for(int j=p;j<r;j++)
	{
		if(ctu[j].digit<=temp.digit)
		{
			i=i+1;
			t=ctu[i];
			ctu[i]=ctu[j];
			ctu[j]=t;
		}
	 }
	 t=ctu[i+1];
	 ctu[i+1]=ctu[r];
	 ctu[r]=t;
	  return i+1;
} 
int QuikSort(struct mem ctu[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=Partition(ctu,p,r);
		QuikSort(ctu,p,q-1);
		QuikSort(ctu,q+1,r);
	}
}
int main()
{
	int flag=1;
	scanf("%d",&n);
	char s[10];
	int v;
	for(int i=0;i<n;i++)
	{
		scanf("%s %d",s,&v);
		stu[i].a=ctu[i].a=s[0];
		stu[i].digit=ctu[i].digit=v;
		//ctu[i]=stu[i];
	}
	MergeSort(stu,0,n);
	QuikSort(ctu,0,n-1);
	for(int i=0;i<n;i++)
	{
		if(stu[i].a!=ctu[i].a)
		{
			flag=0;
            break;
		}
	}
	if(flag) printf("Stable\n");
	else printf("Not stable\n");
	for(int i=0;i<n;i++)
	{
		printf("%c %d\n",ctu[i].a,ctu[i].digit);
	}
	return 0;
}

