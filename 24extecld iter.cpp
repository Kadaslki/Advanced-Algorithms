#include<iostream>
#include<stdio.h>

using namespace std;

int extecld(int a, int n){
	int t1=0, t2=1, r1=n, r2=a, q, tmp;
	cout<<"\nPrinting:\nQ\tT1\tT2\tR1\tR2\n";
	while(r2!=0){
		q=r1/r2;
		tmp=t1; t1=t2; t2=tmp-q*t2;
		tmp=r1; r1=r2; r2=tmp-q*r2;
		cout<<q<<'\t'<<t1<<'\t'<<t2<<'\t'<<r1<<'\t'<<r2<<endl;
	}
	if(r1>1)
		return -1;
	if(t1<0)
		t1=t1+n;
	return t1;
}

int main(){
	int n,a;
	cout<<"\nEnter the element: ";
	cin>>a;
	cout<<"\nEnter element space: ";
	cin>>n;
	cout<<"\nMultiplicative Inverse: "<<extecld(a,n);
}
