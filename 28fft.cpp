#include<bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238460;
 
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
void fft(CArray& x)
{
    const size_t N = x.size();
    if (N <= 1) return;
    CArray even = x[slice(0, N/2, 2)];
    CArray  odd = x[slice(1, N/2, 2)];
    fft(even);
    fft(odd);
    for (size_t k = 0; k < N/2; ++k){
        Complex t =polar(1.0, -2 * PI * k / N) * odd[k];
        x[k] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
}
 
 
int main()
{
	int n;
	cout<<"\nEnter number of coefficients: ";
	cin>>n;
    Complex test[n];
    for(int i=0;i<n;i++)
       	cin>>test[i];
    CArray data(test, n);
    fft(data);
    cout << "Fast Fourier Transform points are: " <<endl;
    for (int i = 0; i < 8; ++i)
        cout << data[i] <<endl;
    return 0;
}
