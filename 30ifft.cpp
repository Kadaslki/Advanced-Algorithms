#include<bits/stdc++.h>
using namespace std;
 
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

void fft(CArray &x)
{
	unsigned int N = x.size(), k = N, n;
	double thetaT = 3.14159265358979323846264338328L / N;
	Complex phiT = Complex(cos(thetaT), -sin(thetaT)), T;
	while (k > 1){
		n = k;
		k >>= 1;
		phiT = phiT * phiT;
		T = 1.0L;
		for (unsigned int l = 0; l < k; l++){
			for (unsigned int a = l; a < N; a += n)
			{
				unsigned int b = a + k;
				Complex t = x[a] - x[b];
				x[a] += x[b];
				x[b] = t * T;
			}
			T *= phiT;
		}
	}
	unsigned int m = (unsigned int)log2(N);
	for (unsigned int a = 0; a < N; a++){
		unsigned int b = a;
		b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
		b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
		b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
		b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
		b = ((b >> 16) | (b << 16)) >> (32 - m);
		if (b > a){
			Complex t = x[a];
			x[a] = x[b];
			x[b] = t;
		}
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

