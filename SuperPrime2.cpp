//��ҵ���������������¿�ܵĴ���ϸ�ڣ������ܱ������еõ���ȷ��� 
#include <iostream>
class SuperPrime {
  public:
  	SuperPrime():number(0) {  //Ϊʲô�����У� 
  	  size = 0;
  	}
  	SuperPrime(int n):number(n) {
  	  size = 0;
  	  split();  //�����ǹ������ 
	}
  	~SuperPrime() {
  	  for (int i = 0; i < size; ++i)  //���ٶ��� 
		delete N[i]; 
	}
  	bool isSuperPrime() {
  	  SuperPrime a(sum());   //����ͨ����ת��Ϊ����a.number = sum 
	  SuperPrime b(multi());
	  SuperPrime c(squareSum());
	  if (isPrime() && a.isPrime() && b.isPrime() && c.isPrime())
	    return true; 
  	  return false;
	}
	int shownum() {
		return number;
	}
  private:
  	const int number;
  	SuperPrime *N[100];   //�����ָ������ 
	int size;    //number ��λ�� 
  	bool isPrime() { 
  	  //2��number-1������
	  for(int i=2; i<number; i++) {
	  	if(number % i == 0 && i != number -1)
	  		return false;
	  } 
  	  return true;
	}
	void split() {   //�����������ģʽ 
	  // number split into N
	  int temp = number;
	  while(temp > 0) {
	  	int n = temp % 10;
	  	temp /= 10;
	  	N[size] = new SuperPrime(n);   //������� ,�����ɶ��������superprime��isprime���� 
	  	size += 1;
	  } 
	}
	int sum() {
      int sum;
	  for(int i=0; i< size; i++ ) {
	  	sum += N[i]->number;
	  }
	  return sum;
	}
	int multi() {
	  int mul;
	  for(int i=0; i< size; i++ ) {
	  	mul *= N[i]->number;
	  }
	  return mul;
	}
	int squareSum() {
	  int sqsum;
	  for(int i=0; i< size; i++) {
	  	sqsum += (N[i]->number * N[i]->number);
	  }
	  return sqsum;
	}
};
class Set {
  public:
  	Set(int from, int to) {
  	  init = from;
  	  size = from - to + 1;
	}
  	~Set() {
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++,init++)
  	    if(set[init].isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  for (int i = 0; i < size; i++,init++)
  	    if(set[init].isSuperPrime())
  	      sum += set[init].shownum();
  	
	  return sum; 
	}
  private:
  	SuperPrime set[1000];
  	int init;
  	int size;
};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}

