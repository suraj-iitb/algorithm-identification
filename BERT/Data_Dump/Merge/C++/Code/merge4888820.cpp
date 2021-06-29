#include <iostream>
using namespace std;

#define LOOP(i,v,n) for(int i=v;i<n;i++)

int cnt=0;

void Merge(int a[],int left,int mid,int right){
	//~ compare leftside and rightside
	int n1 = mid - left;
	int n2 = right - mid;
		//~ cout << "left:" << left+1 <<  " n1:" << n1 << " right:"<< mid+1 << " n2:"<< n2 << "\n"; 
		int l[n1+1]={},r[n2+1]={};
		//~ seperated two arrays
		//~ l0,1,2,3.... a left,left+1,left+2...mid-1
		//~ r0,1,2,3.... a mid,mid+1,mid+2...right
		LOOP(i,0,n1) {l[i]=a[left+i];}
		LOOP(i,0,n2) {r[i]=a[mid+i];}
		l[n1] = 1000000006;
		r[n2] = 1000000006;
		int i=0,j=0;
		//~ it input smaller number of leftside or rightside  
		for(int k=left;k<right;k++){
			cnt++;
			//~ compare li and rj like a_left+1,a_mid+1
			if(l[i]<=r[j]){
				a[k] = l[i];
				i += 1;
				}
			else{
				a[k] = r[j];
				j += 1;
				}
			}
	}

//~ start
//~ at first left fixed and right changed
//~ left_fixed = right_changed = left -> mid = left
//~ 2 intengers are arranged at first
void MergeSort(int a[], int left, int right){
	if(left+1<right){
		int mid = (left+right)/2;
		MergeSort(a,left,mid);
		MergeSort(a,mid,right);
		Merge(a,left,mid,right);
		}
	}

int main(){
	int n;
	cin >> n;
	int a[n] = {};
	LOOP(i,0,n) cin >> a[i];
	//~ a[n+1] = 1000000006;
	MergeSort(a,0,n);
	LOOP(i,0,n) cout << a[i] << ((i==n-1)?"\n":" ");
	cout << cnt << "\n";
	}

