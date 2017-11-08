#include <iostream>
using namespace std;

float abso(float t)
{
	if(t>=0)
	return t;
	else
	return t*(-1);
}

template <class t>
void swap(t* a,t* b)
{
	t temp=*a;
	*a=*b;
	*b=temp;
}

int main() {
	// your code goes here
	int n=3;
	float a[n][n]={{1,2,0},{3,4,4},{5,6,3}};
	
	int pi[n];
	for(int i=0;i<n;i++)
	pi[i]=i;
	
	for(int k=0;k<n;k++)
	{
		int index;
		float p=0;
		for(int i=k;i<n;i++)
		{
			if(abso(a[i][k])>p)
			{
				p=abso(a[i][k]);
				index=i;
			}
		}
		swap(&pi[k],&pi[index]);
		for(int i=0;i<n;i++)
		swap(&a[k][i],&a[index][i]);
		for(int i=k+1;i<n;i++)
		{
			a[i][k]=a[i][k]/a[k][k];
			for(int j=k+1;j<n;j++)
			a[i][j]=a[i][j]-a[i][k]*a[k][j];
		}
		
	}
	
	cout<<"L matrix\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			cout<<"1.0\t";
			else if(i>j)
			cout<<a[i][j]<<"\t";
			else
			cout<<"0.0\t";
		}
		cout<<endl;
	}
	
	cout<<"U matrix\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<=j)
			cout<<a[i][j]<<"\t";
			else
			cout<<"0.0\t";
		}
		cout<<endl;
	}
	
	cout<<"P matrix\n";
	for(int i=0;i<n;i++)
	cout<<pi[i]<<endl;
	return 0;
}