//��ҵ��ɾ������ļ����࣬ʹ�ü̳з���ʵ����ͬ�Ĺ��ܡ� 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	virtual bool isPrime() { 
  	  //2��number-1������ 
  	  std::cout << "Prime's isPrime() call" << std::endl;
  	  
  	  	 for(int i=2; i<number; i++) {
	  	 if(number % i == 0 && i != number -1)
	  		return false;
	  } 
  	  return true; 
	}
	int shownum() {
		return number;
	}
  private:
  	const int number;
}; 
class PrimeSet {
	friend class SuperPrime;
  public:
  	PrimeSet(int size) {
  	  //���ϵĹ���ʲô�� 
  	  set = new Prime*[size];   
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  delete[] set;
	}
 	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isPrime())
  	      count += 1;
	  return count; 
	}
	bool add(int n) {
	  if(index == size)  
	  	return false;
	  Prime *p = new Prime(n);
	  set[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!set[i]->isPrime())
	    	return false;
	  return true;
	} 
  private:
  	Prime **set;
	int size, index;
};
class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0), pset(3) {  //Ϊʲô�����У� 
  	}
  	SuperPrime(int n):Prime(n), pset(3) {
	  // number split into N
	  int temp = n;
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	  	pset.add(t);  //��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ���� 
	  } 
	}
  	~SuperPrime() {
	}
  	virtual bool isPrime() {   //��/����Ľӿڣ�������˵����� 
  	  std::cout << "SuperPrime's isPrime() call" << std::endl;
	  if (Prime::isPrime() && Prime(sum()).isPrime() 
	  	&& Prime(multi()).isPrime() && Prime(squareSum()).isPrime())
	    return true; 
  	  return false;
	}
  private:
  	PrimeSet pset;
	 int sum() {
	  int sum;
	  for(int i=0; i<pset.index; i++) {
		sum += pset.set[i]->shownum();
	  }
	  return sum;
	}
	int multi() {
		int multi = 1;
	  for(int i=0; i<pset.index; i++) {
		multi *= pset.set[i]->shownum();
	  }
	  return multi;
	}
	int squareSum() {
		int squareSum = 1;
	  for(int i=0; i<pset.index; i++) {
		squareSum *= (pset.set[i]->shownum() * pset.set[i]->shownum());
	  }
	  return squareSum;
	}
};
int main() {
  SuperPrime p(13);
  SuperPrime sp(113);
  PrimeSet set(2);
  set.add(13); 
  set.add(113);
  std::cout << "How Many : " << set.count() << std::endl;
  return 0;
}
