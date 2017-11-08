#include<iostream>
using namespace std;

void ext(int a,int b,int& d,int& x,int& y)
{
	if(b == 0)
	{
		d = a;
		x = 1;
		y = 0;
		return;
	}
	int d1,x1,y1;
	ext(b,a%b,d1,x1,y1);
	d = d1;
	x = y1;
	y = (x1-(a/b)*y1);
	cout<<d1<<" "<<x1<<" "<<y1<<"\n";
}

int main()
{
	int a,b;
	cin>>a>>b;
	int d,x,y;
	cout<<"Table :\n";
	ext(a,b,d,x,y);
	cout<<d<<" "<<x<<" "<<y<<"\n";
}
