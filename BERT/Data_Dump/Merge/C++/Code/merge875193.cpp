#include<iostream>
using namespace std;


unsigned int val[500000];
unsigned int buf[500000];
int counter = 0;

void margeSort(int left, int right){
	int mid = (left + right) / 2;

	if(left == right) return;

	margeSort(left, mid);
	margeSort(mid + 1, right);

	for(int i = left; i <= mid; i ++){
		//cout << "val[" << i << "] = " << val[i] << endl;
		buf[i] = val[i];
	}
	
	for(int i = mid + 1; i <= right; i ++){
		//cout << "val[" << i << "] = " << val[i] << endl;
		buf[right - i + mid + 1] = val[i];
	}
	
	int rightCounter = right;
	int leftCounter = left;

	//cout << "==========compairsion is started=============" << endl;

	for(int i = left; i <= right; i ++){
		if(buf[leftCounter] <= buf[rightCounter]){
			//cout << "L is small:val[" << i << "] <-- " <<  "buf[" << leftCounter << "]:" <<  buf[leftCounter] << endl;	
			val[i] = buf[leftCounter];	
			leftCounter ++;
		}else{
			//cout << "R is small:val[" << i << "] <-- " <<  "buf[" << rightCounter << "]:" << buf[rightCounter] << endl;	
			val[i] = buf[rightCounter];
			rightCounter --;
		}
		counter ++;
	}
};


int main(){

	ios_base::sync_with_stdio(false);

	int number;
	cin >> number;
	int i = 0;
	while(cin >> number){
		val[i] = number; 
		i++;
	}

	margeSort(0 , i - 1);

	for(int j = 0; j < i; j++)
		cout << val[j] << (j + 1 < i  ? " ":"");
	
	cout << endl;
	cout << counter << endl;

	return 0;
}
