#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int n,m,i,j=0;
	string txt, pt;
	cin>>txt>>pt;
	n=txt.length();
	m=pt.length();
	int ar[m];
	ar[0]=0;
	for(i=1;i<m;i++){
		if(pt[i]==pt[j]){
			j++;
			ar[i]=j;
			}
		else{
			if(j!=0)	j=ar[j-1];
			else	ar[i]=0;	}
	}
	i=j=0;
	while(i<n){
		if(pt[j]==txt[i]){	i++; j++;	}
		if(j==m){
			cout<<"\nPattern found at "<<i-j;
			j=ar[j-1];	}
		else if(i<n && pt[j]!=txt[i]){
			if(j!=0)	j=ar[j-1];
			else	i++;	}
    }
		cout<<"Transition State Table\n";
		cout<<"State"<<"\t\t"<<"a\tb\tc\n";
		for(i=0;i<m;i++){
			cout<<i<<"\t\t";
			if(pt[i]=='a')
				cout<<i+1<<"\t";
			else
				cout<<ar[i]<<"\t";
			if(pt[i]=='b')
				cout<<i+1<<"\t";
			else
				cout<<ar[i]<<"\t";
            if(pt[i]=='c')
				cout<<i+1<<"\t";
			else
				cout<<ar[i]<<"\t";
			cout<<endl;
		}
}
