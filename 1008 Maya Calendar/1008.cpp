#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	int n,k,l,t,h,y,m,d;
	char c;
	string s,s2;
	cin>>n;
	cout<<n<<endl;
	for (int i=1;i<=n;i++)
	{
		cin>>k>>c>>s>>l;
		if (s=="pop") h=1;
		if (s=="no") h=2;
		if (s=="zip") h=3;
		if (s=="zotz") h=4;
		if (s=="tzec") h=5;
		if (s=="xul") h=6;
		if (s=="yoxkin") h=7;
		if (s=="mol") h=8;
		if (s=="chen") h=9;
		if (s=="yax") h=10;
		if (s=="zac") h=11;
		if (s=="ceh") h=12;
		if (s=="mac") h=13;
		if (s=="kankin") h=14;
		if (s=="muan") h=15;
		if (s=="pax") h=16;
		if (s=="koyab") h=17;
		if (s=="cumhu") h=18;
		if (s=="uayet") h=19;
		t=l*365+k+h*20-20;
		y=t/260;
		m=t%20+1;
		d=t%13+1;
		switch (m)
		{
			case 1:s2="imix"; break;
			case 2:s2="ik"; break;
			case 3:s2="akbal"; break;
			case 4:s2="kan"; break;
			case 5:s2="chicchan"; break;
			case 6:s2="cimi"; break;
			case 7:s2="manik"; break;
			case 8:s2="lamat"; break;
			case 9:s2="muluk"; break;
			case 10:s2="ok"; break;
			case 11:s2="chuen"; break;
			case 12:s2="eb"; break;
			case 13:s2="ben"; break;
			case 14:s2="ix"; break;
			case 15:s2="mem"; break;
			case 16:s2="cib"; break;
			case 17:s2="caban"; break;
			case 18:s2="eznab"; break;
			case 19:s2="canac"; break;
			case 20:s2="ahau"; break;
		}
		cout<<d<<' '<<s2<<' '<<y<<endl;
	}
}
