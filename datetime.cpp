#include <iostream>
class DateTime {
private:
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  ~DateTime();
  void showTime();
};
int main() {
  DateTime dt, dt1;
  dt.showTime();
  dt1.showTime();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 13;
  hour = 11; minute = 27; second = 55;
}
DateTime::~DateTime() 
{
  std::cout << "Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
 
