//作业：完成以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
class SuperPrime {
  public:
  	SuperPrime():number(0) {
	}
  	~SuperPrime() {
	}
	void SetNum(int n) {    //对每一个set里的number赋值 
	  int *a = (int *) &number;
	  *a = n;
	}
  	bool isSuperPrime() {
  	  split(number, N);
  	  int a = sum();   //和为质数 
	  int b = multi();   //乘积为质数 
	  int c = squareSum();   //各个数平方和为质数 
	  if (isPrime(number) && isPrime(a) && isPrime(b) && isPrime(c))
	    return true; 
  	  return false;
	}
  private:
  	const int number;
  	int N[10], size;
  	bool isPrime(int n) {  //是质数就返回true，不是就false 
	  int i = 2;  
  	  for(i=2; i<n; i++ ) {
  	  	if(n % i == 0) {
  	  		break;
			}
		}
	  if( i == n - 1 ) {
	  	return true;
	  }
  	  return false;
	}
	void split(const int number,int *N) {
	  // number split into N
	  int i=0, a=number;
	  for (i = 0; a > 0; i++) {
	  	N[i] = a % 10;
	  	a = a / 10;
	  }
	  size = i + 1;
	}
	int sum() {
	  int a;
	  for(int i=0; i< size; i++) {
	  	a += N[i];
	  } 
	  return a;
	}
	int multi() {
	  int b;
	  for(int i=0; i< size; i++) {
	  	b *= N[i];
	  }
	  return b;
	}
	int squareSum() {
	  int c;
	  for(int i = 0; i< size; i++)
	    c += (N[i] * N[i]);
	  return c;
	}
};
class Set {
  public:
  	Set(int from, int to) {
  	  size = to - from;
  	  begin = from;  end = to;
	}
  	~Set() {
	}
  	int count() {
  	  int count = 0;
  	  int i =0;
  	  for (i = 0; i < size; i++)
  	  	set[i].SetNum(i+begin);
  	    if(set[i].isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  for(int i=0; i<size; i++) {
  	  	set[i].SetNum(i+begin);
  	  	if(set[i].isSuperPrime())
  	  	  sum += set[i].number;
		}
	  return sum; 
	}
  private:
  	SuperPrime set[1000];
  	int size;
  	int begin, end;
};
int main() {
  Set ss(100, 999);
  std::cout << "How Many: " << ss.count() << std::endl;
  std::cout << "Sum is " << ss.sum() << std::endl;
  return 0;
}
