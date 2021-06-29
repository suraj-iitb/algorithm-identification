#include<iostream>
using namespace std;

int BubbleSort(int A[],int N){
	int count=0;
	bool flag=1;
	while(flag){
		flag=0;
		for(int j=N-1;j>=1;j--){
			if(A[j]<A[j-1]){
				swap(A[j],A[j-1]);
				count++;
				flag=1;
			}
		}
	}
	return count;
}

int main(){
	int num=0;
	cin >> num;
	int array[num];
	for(int i=0;i<num;i++){
		cin >> array[i];
	}
	int count = BubbleSort(array,num);
	for(int i=0;i<num-1;i++){
		cout << array[i] << " ";
	}
	cout << array[num-1] << endl << count << endl;
	return 0;
	
}
