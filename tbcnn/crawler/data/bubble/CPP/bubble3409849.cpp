#include<iostream>
#include<vector>
using namespace std;

int main(){
	int i,N,num,num1,num2;
	int change_times=0;
	bool flag=false;
	vector<int> numbers;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>num;
		numbers.push_back(num);
	}
	
	while(flag==false){
		flag=true;
		for(i=N-1;i>=1;i--){
			if(numbers[i]<numbers[i-1]){
				num1=numbers[i];
				num2=numbers[i-1];
				numbers[i]=num2;
				numbers[i-1]=num1;
				flag=false;
				change_times+=1;
			}
		}
	}
	
	cout<<numbers[0];
	for(i=1;i<N;i++)cout<<" "<<numbers[i];
	cout<<endl<<change_times<<endl;
	return 0;
}
