#include<iostream>
using namespace std;
int A[100];
void print(int A[], int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		cout<<A[i]<<" ";
	}
	cout<<A[n-1]<<endl;
}

int main(int argc, char const *argv[])
 {
 	int n;
 	cin>>n;
 	for (int i = 0; i < n; ++i)
 	{
 		cin>>A[i];
 	}

 	int flag = 1;
 	int cnt = 0;
 	while(flag)
 	{
 		flag = 0;
 		for (int i = n-1; i >= 1; --i)
 		{
 			if(A[i] < A[i-1])
 			{
 				int tmp = A[i];
 				A[i] = A[i-1];
 				A[i-1] = tmp;
 				cnt++;
 				flag = 1;
 			}
 		}
 	}
 	print(A,n);
 	cout<<cnt<<endl;
 	return 0;
 }
