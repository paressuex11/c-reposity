#include<stdio.h>
#include<stdbool.h>
bool isPrime(int); 
main(){
	for(int i=2;i<100;i++){
		if(isPrime(i)){
			printf("%d\n",i);
		}
	}
	
	
}
bool isPrime(int n){
	int boolen=1;
	for(int i=2;i<n;i++){
		if(n % i == 0){
			boolen = 0;
			break;
		}
		
	}
	return boolen;
	
}	
		
		
		
		
		
		
		


