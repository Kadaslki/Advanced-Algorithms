#include<iostream>
using namespace std;

int expo(int base,int exp,int mod)
{
	int ans = 1;
	while(exp)
	{
		if(exp&1)
		{
			ans = (ans*base)%mod;
		}
		base = (base*base)%mod;
		exp = exp/2;
	}
	return ans;
}

int main()
{
	string txt;
	int i,j,k,n;
	cout<<"\nEnter text: ";
	cin>>txt;
	cout<<"\nEnter number and size of patterns: ";
	cin>>n>>k;
	string pat[n+1];
	cout<<"\nEnter patterns to be found: \n";
	for(i = 0;i<n;i++)
	{
		cin>>pat[i];
	}
	//cout<<"Here\n";
	int p[n+1];
	for(i = 0;i<=n;i++)
	{
		p[i] = 0;
	}
	int d = 10,q = 13;
	int h = expo(d,k-1,q),t,ln = txt.length();
	bool pos = false;
	for(i = 0;i<k;i++)
	{
		for(j = 0;j<n;j++)
		{
			p[j] = ((p[j]*d)%q+pat[j][i])%q;
		}
	}
	t = 0;
	for(i = 0;i<k;i++)
	{
		t = ((t*d)%q+txt[i])%q;
	}
	for(i = 0;i<n;i++)
	{
		if(t == p[i])
		{
			pos = true;
			break;
		}
	}
	//cout<<"H2\n";
	if(pos == false)
	{
		for(i = k;i<ln&&(!pos);i++)
		{
			t = (((t-(h*txt[i-k])%q)*d)%q+txt[i])%q;
			for(j = 0;j<n;j++)
			{
				if(t == p[j])
				{
					pos = true;
					break;
				}
			}
		}
	}
	//cout<<"H3\n";
	if(pos)
	{
		cout<<"Found\n";
	}
	else
	{
		cout<<"Not found\n";
	}
}
