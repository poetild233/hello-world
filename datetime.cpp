#include <iostream>
class DateTime {
private:
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  ~DateTime();
  void showTime();
  void showMoon();  //作业：将当前公历转换为农历显示出来 
};
int main() {
  DateTime dt, dt1;
  std::cout << &dt << std::endl;
  std::cout << &dt1 << std::endl;
  dt.showTime();
  dt.showMoon();
  dt1.showTime();
  dt1.showMoon();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
}
DateTime::~DateTime() 
{
  std::cout << this << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("当前时间：%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void Datetime::showMoon()  //这里只写了2020年  有闰四月 
{
	int calendar[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int lu_calendar[13] = {0,29,30,30,30,29,30,29,29,30,29,30,29};
	
	int lu_mon, lu_day;
	int time = 0;
	for(int i=0; i<month; i++) {
		time += calendar[i];
	} 
	time += day;
	if (time <= 24) {
		lu_mon = 12;
		lu_day = day - 1 + 7;
	} else {
		time -= 25;
		int i = 1;
		while(time > lu_calendar[i+1]) {
			time -= lu_calendar[i];
			i++;
		}
		if(i < 5) {
			lu_mon = i;
		} else {
			lu_mon = i - 1;
		}
		lu_day = time;
	}
	
	printf("Present lunar time: %d/%d %d:%d:%d:\n",lu_mon, lu_day, hour, minute, second);
}
 
