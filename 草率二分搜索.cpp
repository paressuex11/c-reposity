#include<stdio.h>
int binarysearch(int num[],int,int);
main(){
	int num[10]={1,2,3,4,5,6,7,8,9,10,};
	printf("%d",binarysearch(num,10,5));
} 
int binarysearch(int num[],int length,int value){
	int index=-1,mid,left,right;
	left=0;right=length-1;mid=(left+right)/2;
	while(right>left){
		if(num[mid]>value){
			right=mid;
			mid=(right+left)/2;
		}else if(num[mid]<value){
			left=mid;
			mid=(right+left)/2;	
		}else if(num[mid]=value){
			index=mid;
			break;
		}
	} 
	
	return index;
	
	
}
