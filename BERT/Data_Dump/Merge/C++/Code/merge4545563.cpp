#include<iostream>
#include<climits>
#define req(i,n) for(int i=0; i<(n); i++)
using namespace std;

int count=0;


void merge(int A[], int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1+1], R[n2+1];


	//cout << n1 << ' ' << n2 << endl;
	req(i,n1)
		L[i] = A[left + i];
	req(i,n2)
		R[i] = A[mid + i];
		
	L[n1] = R[n2] = INT_MAX;
	
	int i,j;
	i = j = 0;
	for(int k=left; k<right; k++){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
			count++;
		}	
		else{
			A[k] = R[j];
			j++;
			count++;
		}
	}
}

void mergesort(int A[],int left, int right)
//分割する役割(mergeにより結合)
{
	if(left + 1 < right){
		int mid = (left + right)/2;
		mergesort(A,left,mid);
		mergesort(A,mid,right);
		merge(A, left, mid, right);
	}			
}

int main()
{
	int n;
	cin >> n;
	int S[n];
	req(i,n)
		cin >> S[i];
	/*req(i,n)
		cout << S[i];
	cout << endl;
	*/
	mergesort(S,0,n);

	req(i,n){
		if(i==n-1)
			cout << S[i];
		else
			cout << S[i] << ' ';
	}
	cout << endl;
	cout << count << endl;
}
