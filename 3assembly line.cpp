#include<iostream>
#include<vector>

using namespace std;

int _l, _f;

void fastest_way(int a[2][6], int t[2][6], int *f1, int *f2, int *l1, int *l2, int *e, int *x, int n)
{
 f1[0]=e[0]+a[0][0];
 f2[0]=e[1]+a[1][0];
 int r1, r2, r3, r4;
 for(int i=1; i<n; i++)
 {
  r1=(f1[i-1]+a[0][i]);
  r2=(f2[i-1]+a[0][i]+t[1][i]);
  r3=(f2[i-1]+a[1][i]);
  r4=(f1[i-1]+a[1][i]+t[0][i]);
  if(r1<r2)
  {
   f1[i]=r1;
   l1[i]=0;
  }
  else
  {
   f1[i]=r2;
   l1[i]=1;
  }
  if(r3<r4)
  {
   f2[i]=r3;
   l2[i]=1;
  }
  else
  {
   f2[i]=r4;
   l2[i]=0;
  }
 }
 r1=(f1[n-1]+x[0]);
 r2=(f2[n-1]+x[1]);
 if(r1<r2)
 {
  _f=r1;
  _l=0;
 }
 else
 {
  _f=r2;
  _l=1;
 }
}

void print_way(int *l1, int *l2, int n)
{
 vector <int> s;
 s.push_back(_l);
 int r=_l;
 for(int i=(n-1); i>=0; i--)
 {
  if(r)
  {
   s.push_back(l2[i]);
   r=l2[i];
  }
  else
  {
   s.push_back(l1[i]);
   r=l1[i];
  }
 }
 int i=0;
 while(i<n)
 {
  cout<<"s("<<s[i]+1<<","<<i+1<<") -> ";
  i++;
 }
 cout<<(_f)<<endl;
}

int main()
{
 int e[2]={2, 4}, x[2]={3, 2};
 const int n = 6;
 //cin>>n;
 int f1[n]={-1}, f2[n]={-1}, l1[n]={-1}, l2[n]={-1}, a[2][n]={{7,9,3,4,8,4},{8,5,6,4,5,7}}, t[2][n]={{0,2,3,1,3,4},{0,2,1,2,2,1}};
 fastest_way(a, t, f1, f2, l1, l2, e, x, n);
 cout<<endl;
 print_way(l1, l2, n);
 return 0;
}