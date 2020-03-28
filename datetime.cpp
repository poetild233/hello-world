#include <iostream>
class DateTime {
private:
  static int sth;
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  DateTime(int y, int m, int d, int hour, int minute, int second); 
  DateTime(const DateTime &dt);
  ~DateTime();
  static void showTime();
  void showMoon();  //作业：将当前公历转换为农历显示出来 
};

<<<<<<< HEAD
=======
int DateTime::sth = 0;

>>>>>>> upstream/master
int main() {
  DateTime dt, dt1(2020, 3, 27, 10, 40, 55);
  DateTime dt2(dt), &dt3 = dt;
  DateTime *dt4 = &dt;
  dt.showTime();
  dt.showMoon();
  dt1.showTime();
<<<<<<< HEAD
  dt1.showMoon();
=======
  dt2.showTime();
  dt3.showTime();
  dt4->showTime();
>>>>>>> upstream/master
  return 0;
}

DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
  sth = 11;
}
DateTime::DateTime(int y, int m, int d, int hour, int minute, int second)
{
  year = y; month = m; day = d;
  this->hour = hour; this->minute = minute; this->second = second;
}
DateTime::DateTime(const DateTime &dt)
{
  year = dt.year; month = dt.month; day = dt.day;
  hour = dt.hour; minute = dt.minute; second = dt.second;
}

DateTime::~DateTime() 
{
  std::cout << " Go die, Ha~Ha~" << std::endl;
}

void DateTime::showTime()
{
  printf("当前时间：%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
  std::cout << sth << std::endl;
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
 
