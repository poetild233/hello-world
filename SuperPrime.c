#include<stdio.h>  
//�� 100~10000 �ڵ����г��������������ǵ�ƽ������ 
//������������������λ���ֵĺͣ���λ���ֵ�ƽ���ͣ����������� 
//�� 100~10000 �ڵ����г��������������ǵ�ƽ������ 

int num[100]; 
int isPrime(int x); 
//int splitNum(int x, int num[]); 
int main() 
{ 
	int Startnum = 0; 
	int i = 101; 

	for(i=101; i <= 10000; i++) { 
		if(isPrime(i)) { 
			int j=0; 
			int temp = i; 
			while(temp>0) { 
				j += temp % 10; 
				temp = temp / 10; 
			} 
			if(isPrime(j)) { 
				int k=0; 
				temp = i; 
				while(temp>0) { 
					k += (temp%10)*(temp%10); 
					temp = temp /10; 
					if(isPrime(k)) { 
						num[Startnum++] = i; 
					} 
				} 
			} 
		} 
	} 
	double sum; 
	for(i=0; i< Startnum; i++ ){ 
		printf("%d\n",num[i]); 
		sum += num[i]; 
	} 
	printf("%f\n",sum/(Startnum+1)); 
    return 0; 
} 
int isPrime(int x) 
{ 
	int i=2; 

	for(i=2; i<x; i++) { 
		if( x % i == 0) { 
			break; 
		}  
	} 
	if(i == x) { 
		return 1; 
	} else { 
		return 0; 
	} 
}
