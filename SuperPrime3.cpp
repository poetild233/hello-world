//作业：大整数，比如9081321110693270343633073697474256143563558458718976746753830538032062222085722974121768604305613921745580037409259811952655310075487163797179490457039169594160088430571674960498834085812920457916453747019461644031395307920624947349951053530086146486307198155590763466429392673709525428510973272600608981219760099374675982933766845473509473676470788342281338779191792495900393751209539300628363443012 6538005862664913074813656220643842443844131905754565672075358391135537108795991638155474452610874309742867231360502542308382199053675592825240788613991898567277116881793749340807728335795394301261629479870548736450984003401594705923178314906195914825136973281314862289454100745237769034410057080703111299605127114594552921209928891515242515620324828055912854227507525717981351447473570262981491527798 
//重新设计下面的代码，使其可以处理大整数的素数与超级素数
//同时仔细理解面向对象的编程方式 
#include<iostream>
#include<string>
using namespace std;
class BigPrime {
public:
  BigPrime(string n){
  	for(int i=0; i< n.length(); i++) {
  		num[i] = n[i]; 
	  }
  }
  virtual bool isPrime() const {
  	
  		//这里需要一个我做不出的判断素数的方法 
    return false;
  }
private:
  string num;
}; 
class BigSuperPrime : public BigPrime {
public:
  BigSuperPrime(string n) : BigPrime(n){
  	for(int i=0; i< n.length(); i++) {
  		num[i] = n[i]; 
	  }
  }
  virtual bool isPrime() const {
  		
  	 if(BigPrime::isprime && BigPrime(sum()).isPrime() 
	   && BigPrime(squareSum()).isPrime()&& BigPrime(multi).isPrime() )
	   return true;
	 return false;
  }
private:
  string num;
  string sum() {
  	string a;
  	int temp;
  	for(int i=0; i< num.length(); i++) {
  		temp += (int)num[i];
	  }
	a = (char)temp;
	return a;
  } 
  string multi() {
  	string a;
  	int temp;
  }
  string squareSum() {
  	string a;
  	int temp;
  	for(int i=0; i< num.length(); i++) {
  		temp += (int)num[i] * (int)num[i];
	  }
	a = (char)temp;
	return a;
  }
};
class Set {
public:
  Set(int sz);
  ~Set();
  bool add(BigPrime *bp);
  bool remove(BigPrime *bp);
  int count() const {
  	int ret = 0;
  	for (int i = 0; i < index; i++) {
  	  if (pset[i]->isPrime())
  	    ret += 1;
	  }
  	return ret;
  }
  int sum() const {
  	return 0;
  } 
private:
  BigPrime **pset;
  int size, index;
};
int main() {
  Set set(1000);
  int a;
  string str1,str2;
  cin >> str1 >> str2;
  BigSuperPrime bp(str1), bp1(str2);
  set.add(&bp);
  set.add(&bp1);
  cout << set.count() << endl;
  return 0;
} 

Set::Set(int sz):size(sz) {
  index = 0;
  pset = new BigPrime*[size];  //分配存储空间 
}

Set::~Set() {
  delete[] pset;  //回收 
}
bool Set::add(BigPrime *bp) {
  pset[index++] = bp;
  return true;
}
