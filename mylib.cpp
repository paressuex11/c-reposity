#include<stdio.h>
int reverse(int i){
	int m, n;   //��ת���� 
	int rei = 0;   //ȡÿһλȻ��˻�ȥ 
	do{
		m = i / 10;
		n = i % 10;
		i /= 10;
		rei = rei * 10 + n;
	}while(m != 0); 
	return rei;
}


int sum_digits(int i){
	int m, n;            //�ֽ���������� 
	int sum = 0; 
	do{
		m = i / 10;
		n = i % 10;
		i /= 10;
		sum += n;
	}while(m != 0); 
	return sum;
}



int isPrime(int n){
	int bol = 1;  //�ж����� 
	int i = 2;
	if (n <= 1){
		bol = 0;
	}
	for (; i < n ; i ++ ){
		if (n % i == 0){
			bol = 0;
			break;
		}
	}
	return bol;
}

void print_triangle(){
	int n;								//	eg: n = 6
	int i = 1;							//	����ӡ��	
	int rank = 1;                       //            000001
	int num = 0;                        //			  000021
	scanf("%d", &n);                    // 			  000321
	for (; i <= n ; i ++ ){             //            004321
		num += i * rank;                //            054321
		rank *= 10;                     //            654321
		printf("%0*d\n", n, num);       // ȥ��0������ ' ' ����� 
	}
}

/*           ��λ��ӡ 8 bits ����    						printBit 
void printInt(int val) { 
    printf("%d", val);  
} 
 
void printBit(char val, int bitPos) { 
    int bit = (val >> bitPos) & 1; 
    printInt(bit); 
} 
 
void printBits(char val) {                     
    int i = 0; 
    while (i < 8) { 
        printBit(val, 7 - i); 
        i = i + 1; 
    } 
} 
*/

/*		��λ��ӡ 32 bits ����		printBitss 
void printInt(int val) { 
    printf("%d", val);  
} 
 
void printBit(int val, int bitPos) { 
    int bit = (val >> bitPos) & 1; 
    printInt(bit);                                  
} 
 
void printBits(int intVal) { 
    int i = 0; 
    while (i < 32) { 
        printBit(intVal, 31 - i); 
        i = i + 1; 
    } 
} 

*/

/*   Greatest Common Dividers  ��������� 
int min(int n, int m){
	if (n <= m){
		return n;
	}
	else {
		return m;
	}
}
int max(int n, int m){
	return m + n - min(n, m);
}
int find_gcd(int n, int m){         
	int gcd, x, y;
	y = min(n, m);
	x = max(n, m);
	while (y != x && y != 1){
		if (y <= 0){
			gcd = -1;
		}
		else{
			int y1 = y;
			int x1 = x;
			y = min(x1 - y1, y1);
			x = max(x1 - y1, y1);
		}
	}
	gcd = x;
	return gcd;
}

*/




//Ҫ����ÿ�����������������count������count % 10 == 0ʱ���� 

int find(double data[], int size, double value_to_find){   //��������... 
	for (int i = 0; i < size ; i ++ ){
		if (data[i] == value_to_find){
			return i;
		}
	}
	return -1;
}


void sort(double data[], int size){      //��������... 
	if (size == 1){
		
	}
	else {
		double m = data[0];
		int t;
	for (int i = 0 ; i < size ; i ++ ){
		if (data[i] >= m){
			m = data[i];
			t = i;
		}
	}
	swap(data + t, data + size - 1);
	sort(data, size - 1);
	}
}

