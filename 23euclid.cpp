#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b,a%b);
}

int main()
{
	int a,b;
	cout<<"\nEnter a and b: ";
	cin>>a>>b;
	cout<<"\nGCD of a and b: "<<gcd(a,b);
}
