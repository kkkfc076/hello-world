#include <iostream>
#include <time.h> 
class DateTime {
private:
	int seconds;//��1970��1��1��0ʱ��ʼ��������� 
	int year,month,day;
  	int hour,minute,second;     
public:
  DateTime();
  DateTime(int y, int m, int d, int hour, int minute, int second); 
  DateTime(const DateTime &dt);
  ~DateTime();
  void showTime();
  void showMoon();  //��ҵ������ǰ����ת��Ϊũ����ʾ���� 
};

int main() {
  DateTime dt, dt1(2020, 3, 27, 10, 40, 55);
  DateTime dt2(dt), &dt3 = dt;
  DateTime *dt4 = &dt;
  dt.showTime();
  dt.showMoon();
  //dt1.showTime();
  dt2.showTime();
  dt3.showTime();
  dt4->showTime();
  return 0;
}
using namespace std;

DateTime::DateTime()
{
	time_t t;
    struct tm * lt;
    time (&t);//��ȡUnixʱ�����
    lt = localtime (&t);//תΪʱ��ṹ��
    year=lt->tm_year+1900; month=lt->tm_mon+1; day=lt->tm_mday;
	hour=lt->tm_hour; minute=lt->tm_min; second=lt->tm_sec;
    
}
DateTime::DateTime(int y, int m, int d, int hour, int minute, int second)
{
	this->hour = hour; this->minute = minute; this->second = second;
}
DateTime::DateTime(const DateTime &dt)
{
	*this = dt;
}
DateTime::~DateTime() 
{
  std::cout << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void DateTime::showMoon()
{
	int calendar[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int Lunar_calendar[13] = {0,29,30,30,30,29,30,29,29,30,29,30,29};
	
	int Lunar_mon, Lunar_day;
	int time=0;
	for(int i=0;i<month;i++)
	{
		time+=calendar[i];
	} 
	time+=day;
	if (time<=24)
	{
		Lunar_mon=12;
		Lunar_day=day-1+7;
	} 
	else 
	{
		time-=25;
		int i=1;
		while(time>Lunar_calendar[i+1])
		{
			time-=Lunar_calendar[i];
			i++;
		}
		if(i<5) 
		{
			Lunar_mon=i-1;
		} 
		else
		{
			Lunar_mon=i;
		}
		Lunar_day=time;
	}
	
	printf("��ǰũ��ʱ��: %d/%d/%d %d:%d:%d\n",year,Lunar_mon, Lunar_day, hour, minute, second);
}
