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
  
  int n, m, j;
  n = s.length();
  m = p.length();
  
  for(int i=0; i<=n-m; i++)
  {
      for(j=0; j<m; j++)
      {
          if(p[j]!=s[i+j])
            break;
      }
      
      if(j==m)
        cout << "\nMatch occurred at position: " << i << endl;
  }
}
