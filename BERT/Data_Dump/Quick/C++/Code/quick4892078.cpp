#include <iostream>
using namespace std;
#define LOOP(i,v,n) for(int i=v;i<n;i++)

bool check = true;

int Partition(int a[],char b[],int p,int r){
	int x = a[r];
	int i=p-1;
	LOOP(j,p,r){
		if(a[j]<=x){
			i++;
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			}
		}
		swap(a[i+1],a[r]);
		swap(b[i+1],b[r]);
		return i+1;
	}

void QuickSort(int a[],char b[],int p, int r){
	if(p<r){
		int q = Partition(a,b,p,r);
		QuickSort(a,b,p,q-1);
		QuickSort(a,b,q,r);
		}
	}

void CountingSort(int a[],int b[],char c[],char d[],int k,int n){
	int e[k+1]={};
	LOOP(i,0,n)e[a[i]]+=1;
	LOOP(i,1,k+1)e[i]=e[i-1]+e[i];
	for(int i=n-1;i>=0;i--){
		b[e[a[i]]-1] = a[i];
		d[e[a[i]]-1] = c[i];
		e[a[i]] = e[a[i]]-1;
		}
	}

void BubbleSort(int a[],char b[],int n){
	LOOP(i,0,n){
		for(int j=n-1;j>i;j--){
			if(a[j-1]>a[j]){
				swap(a[j-1],a[j]);
				swap(b[j-1],b[j]);
				}
			}
		}
	}

void Merge(int a[],char b[],int left,int mid,int right){
	//~ compare leftside and rightside
	int n1 = mid - left;
	int n2 = right - mid;
		//~ cout << "left:" << left+1 <<  " n1:" << n1 << " right:"<< mid+1 << " n2:"<< n2 << "\n"; 
		int l[n1+1]={},r[n2+1]={};
		char cl[n1+1]={},cr[n2+1]={};
		//~ seperated two arrays
		//~ l0,1,2,3.... a left,left+1,left+2...mid-1
		//~ r0,1,2,3.... a mid,mid+1,mid+2...right
		LOOP(i,0,n1) {l[i]=a[left+i];cl[i]=b[left+i];}
		LOOP(i,0,n2) {r[i]=a[mid+i];cr[i]=b[mid+i];}
		l[n1] = 1000000006;
		r[n2] = 1000000006;
		int i=0,j=0;
		//~ it input smaller number of leftside or rightside  
		for(int k=left;k<right;k++){
			//~ compare li and rj like a_left+1,a_mid+1
			if(l[i]<=r[j]){
				a[k] = l[i];
				b[k] = cl[i];
				i += 1;
				}
			else{
				a[k] = r[j];
				b[k] = cr[j];
				j += 1;
				}
			}
	}

void MergeSort(int a[],char b[], int left, int right){
	if(left+1<right){
		int mid = (left+right)/2;
		MergeSort(a,b,left,mid);
		MergeSort(a,b,mid,right);
		Merge(a,b,left,mid,right);
		}
	}



int main(){
	int n;
	cin >> n;
	int q_a[n]={};
	int m_a[n]={};
	//~ int b_a[n]={};
	//~ int c_a[n] = {};
	//~ char c_c[n] = {};
	//~ int max=0;
	char q_b[n]={};
	char m_b[n]={};
	//~ char b_b[n]={};
	LOOP(i,0,n){
		cin>>q_b[i]>>q_a[i];
		m_b[i] = q_b[i];
		//~ b_b[i] = q_b[i];
		//~ c_c[i] = q_b[i];
		m_a[i] = q_a[i];
		//~ b_a[i] = q_a[i];
		//~ c_a[i] = q_a[i];
		//~ max = (max>q_a[i])?max:q_a[i];
		}
	QuickSort(q_a,q_b,0,n-1);
	//~ int c_b[n] = {};
	//~ char c_d[n] = {};
	
	//~ CountingSort(c_a,c_b,c_c,c_d,max,n);
	//~ LOOP(i,0,n){
		//~ if(q_b[i] != c_d[i]) {
			//~ cout << "Not stable" << "\n";
			//~ break;
			//~ }
		//~ if(i==n-1) cout << "Stable" << "\n";
		//~ }
		
		//~ BubbleSort(b_a,b_b,n);
	//~ LOOP(i,0,n){
		//~ if(q_b[i] != b_b[i]) {
			//~ cout << "Not stable" << "\n";
			//~ break;
			//~ }
		//~ if(i==n-1) cout << "Stable" << "\n";
		//~ }
		
	MergeSort(m_a,m_b,0,n);
	LOOP(i,0,n){
		if(m_b[i] != q_b[i]) {
			cout << "Not stable" << "\n";
			break;
			}
		if(i==n-1) cout << "Stable" << "\n";
		}
	LOOP(i,0,n)cout<<q_b[i]<<" "<<q_a[i]<<"\n";
	//~ LOOP(i,0,n)cout<<m_b[i]<<" "<<m_a[i]<<"\n";
	//~ LOOP(i,0,n)cout<<b_b[i]<<" "<<b_a[i]<<"\n";
	//~ LOOP(i,0,n)cout<<c_d[i]<<" "<<c_b[i]<<"\n";
	}

