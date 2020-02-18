#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int num=0;
	ifstream BAT1;
	BAT1.open("/sys/class/power_supply/BAT1/capacity");
	if (!BAT1)
	{ cout << "BAT = X";
	return 0;
	}
	if (BAT1)
	{
		BAT1 >> num;
	

		if ( num < 98)
		{
			cout << "BAT = " << num << "%";
		}
		else if (num > 98 )
		{
			cout << "BAT = FULL";
		}
	}
	BAT1.close();

	return 0;


} 
