#include<iostream>

int main(){
 	int N;
 	int A[100];
	int tmp;
  	std::cin>>N;
  	for(int i=0;i<N;i++){
    	std::cin>>A[i];
  	}
	for(int i=1;i<N;i++){
		for(int k=0;k<N-1;k++){
			std::cout<<A[k]<<" ";
		}
		std::cout<<A[N-1]<<"\n";
		int v=A[i];
    	int j=i-1;
    	while(j>=0&&A[j]>v){
    		A[j+1]=A[j];
    		j--;
    	}
		A[j+1]=v;
  	}
	for(int k=0;k<N-1;k++){
		std::cout<<A[k]<<" ";
	}
	std::cout<<A[N-1]<<"\n";
	return 0;
}
