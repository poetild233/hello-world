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
 	bool isPrime() { 
  	  //2��number-1������
		 for(int i=2; i<number; i++) {
	  	if(number % i == 0 && i != number -1)
	  		return false;
	  } 
  	  return true; 
	}
	int getnum() {
		return number;
	}
  private:
  	const int number;
}; 
class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0),index(0) {  //Ϊʲô�����У� 
  		
  	}
  	SuperPrime(int n):Prime(n),index(0) {
	  // number split into N
	  int temp = n;
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	    pset[index]= new Prime(t);
	    index++;
	  } 
	}
  	~SuperPrime() {
	}
  	bool isPrime() {   //��/����Ľӿڣ�������˵����� 
	  if (Prime::isPrime() && isAllPrime())
	    return true; 
  	  return false;
	}

  private:
  	Prime *pset[];
  	int index;
	int sum() {
	  int sum = 0;
	  for(int i=0;i<index;i++) {
	  	sum += pset[i]->getnum();
	  }
	  return sum;
	}
	int multi() {
	  int multi=1;
	  for(int i=0;i<index;i++) {
	  	multi *= pset[i]->getnum();
	  }
	  return multi;
	}
	int squareSum() {
	  int squaresum=0;
	  for(int i=0;i<index;i++) {
	  	squaresum += pset[i]->getnum() * pset[i]->getnum();
	  }
	  return squaresum;
	}
	bool isAllPrime() {
		Prime a(sum()); Prime b(multi()); Prime c(squareSum());
		if(a.isPrime() && b.isPrime() && c.isPrime())
	      return true;
	  return false;
	} 
};
class PrimeSet {
  public:
  	PrimeSet(int size) {
  	  //���ϵĹ���ʲô�� 
  	  for(int i=0;i<size;i++) {
  	  	set[i] = new SuperPrime(100+i);
		}
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  for (int i = 0; i < index; ++i)  //���ٶ��� 
		delete set[i]; 
	}
 	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isPrime())
  	      count += 1;
	  return count; 
	}
	int sum() {
		int sum=0;
		for(int i = 0; i<size; i++ ) {
			if(set[i]->isPrime())
			sum += set[i]->getnum();
		}
		return sum;
	}
  private:
  	SuperPrime *set[];
	int size, index;
};
int main() {
  SuperPrime sp(113);
  if (sp.isPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}

