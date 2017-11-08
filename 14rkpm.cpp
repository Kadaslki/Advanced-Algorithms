#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s, p;
  
  cout << "\nEnter the string: ";
  getline(cin, s);
  cout << "\nEnter the pattern: ";
  getline(cin, p);
  
  int i, j, m, n, sh=0, ph=0, h=1;
  n=s.length();
  m=p.length();
    
  int d=10, q=13;
  
  for(i=0; i<m-1; i++)
    h = (h*d)%q;
  
  for(i=0; i<m; i++)
  {
      sh=(d*sh + s[i])%q;
      ph=(d*ph + p[i])%q;
  }
  
  for(i=0; i<=n-m; i++)
  {
      if(ph==sh)
      {
          for(j=0; j<m; j++)
            if(s[i+j]!=p[j])
            {
            	cout << "\nSpurious at position " << i;
                break;
            }
          if(j==m)
            cout << "\nValid pattern found at position " << i;  	
      } 
      if(i<n-m)
      {
          sh = (d*(sh - s[i]*h) + s[i+m])%q;
          if(sh<0)
          {
              sh+=q;
          }
      }
  }
  cout << endl << endl;
}
