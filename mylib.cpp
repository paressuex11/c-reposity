#include<stdio.h>
int reverse(int i){
	int m, n;   //反转整数 
	int rei = 0;   //取每一位然后乘回去 
	do{
		m = i / 10;
		n = i % 10;
		i /= 10;
		rei = rei * 10 + n;
	}while(m != 0); 
	return rei;
}


int sum_digits(int i){
	int m, n;            //分解整数后求和 
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
	int bol = 1;  //判断素数 
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
	int i = 1;							//	则会打印：	
	int rank = 1;                       //            000001
	int num = 0;                        //			  000021
	scanf("%d", &n);                    // 			  000321
	for (; i <= n ; i ++ ){             //            004321
		num += i * rank;                //            054321
		rank *= 10;                     //            654321
		printf("%0*d\n", n, num);       // 去掉0可以用 ' ' 来填充 
	}
}

/*           按位打印 8 bits 整数    						printBit 
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

/*		按位打印 32 bits 整数		printBitss 
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

/*   Greatest Common Dividers  求最大公因数 
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




//要限制每行输出个数可以引入count变量，count % 10 == 0时换行 

int find(double data[], int size, double value_to_find){   //垃圾搜索... 
	for (int i = 0; i < size ; i ++ ){
		if (data[i] == value_to_find){
			return i;
		}
	}
	return -1;
}


void sort(double data[], int size){      //垃圾排序... 
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

