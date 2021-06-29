#include<iostream>
int main(){
	int n,ret=0,b1,b2,list[101];
	bool isrev=true;
	std::cin>>n;
	for(int i=0;i<n;i++){
		std::cin>>list[i];
	}
	while(isrev){
		isrev=false;
		for(int i=n-1;i>=1;i--){
		    if(list[i]<list[i-1]){
		    	b1=list[i],b2=list[i-1];
		    	list[i]=b2,list[i-1]=b1;
			    isrev=true;
			    ret++;
		    }
	    }

	}
	for(int i=0;i<n;i++){
		std::cout<<list[i];
		if(i!=n-1)std::cout<<" ";
		else std::cout<<"\n";
	}
	std::cout<<ret<<"\n";
	return 0;
}
