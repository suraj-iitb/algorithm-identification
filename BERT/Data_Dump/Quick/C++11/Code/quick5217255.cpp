#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<char,int> p;
bool cmp(p a,p b)
{
    return a.second<b.second;
}

void merge(p a[],int l,int r,int mid)
{
  p aux[r-l+1];
  int i,j,k;

  for(k=l;k<=r;k++)
  aux[k-l]=a[k];

  i=l;
  j=mid+1;
  for(k=l;k<=r;k++)
  {
  	if(i>mid)
  	{
  		a[k]=aux[j-l];
  		j++;
	  }
	else if(j>r)
	{
		a[k]=aux[i-l];
		i++;
	  }
	else if(aux[i-l].second>aux[j-l].second)
	{
		a[k]=aux[j-l];
		j++;
		}
	else
	{
		a[k]=aux[i-l];
		i++;
			}


	  }

}

void merge_sort(p a[],int l,int r)
{
    if(l>=r)
	return ;

	int mid=(l+r)/2;

	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	merge(a,l,r,mid);

}


void mergesort(p a[],int l,int r)
{
	merge_sort(a,l,r-1);
}

int Partition(p A[],int q,int r)
{
    int x=A[r].second;
    int i=q-1;
    for(int j=q;j<r;j++)
    {
        if(A[j].second<=x)
        {
            i++;
            p temp=A[j];
            A[j]=A[i];
            A[i]=temp;
        }
    }
    p temp=A[r];
    A[r]=A[i+1];
    A[i+1]=temp;
    return i+1;
}
void qsort(p A[],int q,int r)
{
    if(q<r)
    {
        int z=Partition(A,q,r);
        qsort(A,q,z-1);
        qsort(A,z+1,r);
    }
}
int main()
{
    p card[100010],temp[100010];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>card[i].first>>card[i].second;
        temp[i]=card[i];
    }
    qsort(card,0,n-1);
    mergesort(temp,0,n);
    for(int i=0;i<n;i++)
    {
        if(card[i].first!=temp[i].first)
        {
            cout<<"Not stable"<<endl;
            break;
        }
        if(i==n-1)
            cout<<"Stable"<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<card[i].first<<' '<<card[i].second<<endl;
    }
}
