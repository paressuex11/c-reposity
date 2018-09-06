#include<stdio.h>
int reverse(int);
int main(){
	int n,m,t;
	scanf("%d",&n);
	m=reverse(n);
	do{
		t=m%10;
		m/=10;
		printf("%d ",t);
	}while(m>0);
	
}
int reverse(int n){
	int t;
	int m=0;
	do{
		t=n%10;
		m=m*10+t;
		n/=10;
	}while(n>0);
	return m;
	
}
