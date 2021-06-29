#include<iostream>
#include<algorithm>
#include<array>
#include<utility>

int main(){
	int N;
	std::cin >> N;
	
	std::array<int,100> A;
	
	for(int i=0;i<N;i++){
		std::cin >> A[i];
	}
	
	int change = 0;
	
	for(int i=0;i<N;i++){
		int min_num =std::min_element(A.begin()+i,A.begin()+N) - A.begin();
		if(i!=min_num){
			change++;
			std::swap(A[i],A[min_num]);
		}
	}
	
	for(int i=0;i<N;i++){
		std::cout << A[i];
		if(i!=N-1){
			std::cout<<" ";
		}else{
			std::cout<<std::endl;
		}
	}
	
	std::cout << change <<std::endl;
	
	return 0;
}
