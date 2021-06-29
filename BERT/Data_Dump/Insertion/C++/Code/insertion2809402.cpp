#include<iostream>
#include<vector>
int main(void){
	int n;
	std::cin>>n;
	std::vector<int> array(n);
	
	for(int i=0;i<n;i++){
		std::cin>>array[i];
	}
	
	int i,j,v,k;
	
	for(i=0;i<n-1;i++){
		
	std::cout<<array[i]<<' ';
	
	}
	
	std::cout<<array[i]<<'\n';
	
	for(i=1;i<n;i++){
	
		v=array[i];
		j=i-1;
		
		while(j>=0 && array[j]>v){
			array[j+1]=array[j];
			j--;
		}
		
		array[j+1]=v;
		
		for(k=0;k<n-1;k++){
			std::cout<<array[k]<<' ';
		}
		
		std::cout<<array[k]<<'\n';
		
	}
	
	return 0;
}
