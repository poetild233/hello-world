//��ҵ���������������¿�ܵĴ���ϸ�ڣ������ܱ������еõ���ȷ��� 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	bool isPrime() { 
  	  //2��number-1������
		 for(int i=2; i<number; i++) {
	  	if(number % i == 0 && i != number -1)
	  		return false;
	  } 
  	  return true; 
	}
  private:
  	const int number;
}; 
class PrimeSet {
  public:
  	PrimeSet(int size) {
  	  //���ϵĹ���ʲô�� 
  	  N = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  for (int i = 0; i < index; ++i)  //���ٶ��� 
		delete N[i];  //ɾ��ָ��prime��ָ�� 
	  delete[] N;    //��ɾ��ָ��primeָ�������ָ�� 
	}
	bool add(int n) {
	  if(index == size)  return false;
	  Prime *p = new Prime(n);
	  N[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!N[i]->isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **N;
	int size, index;
};
class SuperPrime {
  public:
  	SuperPrime():number(0), pset(3) {  //Ϊʲô�����У� 
  		size=0;
  	}
  	SuperPrime(int n):number(n), pset(3) {
  	  size = 0;
  	  split();  //�����ǹ������ 
	}
  	~SuperPrime() {
	}
  	bool isSuperPrime() {
  	  //��ôʹ��pset�� 
  	  Prime p(number);
	  if (p.isPrime())
	    return true; 
  	  return false;
	}
	int shownum() {
		return number;
	}
  private:
  	const int number;
  	int size;
  	int numSet[10]; 
  	PrimeSet pset;     //��number��ֳ����������� 
	void split() {   //�����������ģʽ 
	  // number split into N
	  int temp = number;
	  while(temp > 0) {
	  	int n = temp % 10;
	  	temp /= 10;
	  	numSet[size]= n;
	  	size++;
	  }
	  pset.add(sum());  //��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ���� 
	  pset.add(multi());
	  pset.add(squareSum());
	}
	int sum() {
      int sum;
	  for(int i=0; i< size; i++ ) {
	  	sum += numSet[i];
	  }
	  return sum;
	}
	int multi() {
	  int mul;
	  for(int i=0; i< size; i++ ) {
	  	mul *= numSet[i];
	  }
	  return mul;
	}
	int squareSum() {
	  int sqsum;
	  for(int i=0; i< size; i++) {
	  	sqsum += (numSet[i] * numSet[i]);
	  }
	  return sqsum;
	}
};
class SuperPrimeSet {
  public:
  	SuperPrimeSet(int from, int to) {
  	  size = to - from;
  	  index = 0;
  	  for (int i = from; i < to; i++)
  	    set[i-from] = new SuperPrime(i);
	}
  	~SuperPrimeSet() {
  	  for(int i = 0; i < size; i++)
  	    delete set[i];
  	    delete [] set;
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  for (; index < size; index++)
  	    if(set[index]->isSuperPrime())
  	      sum += set[index]->shownum();
  	
	  return sum; 
	}
  private:
  	SuperPrime **set;
  	int size, index;
};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}

