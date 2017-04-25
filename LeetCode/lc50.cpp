#include <cstdlib>

double myPow(double x, long long n){
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return x;
	}
	bool flag = n < 0 ? true : false;
	if (flag)
	{
		n = -n;
	}
	int hn = n / 2;
	int remain = n - hn * 2;
	double re = myPow(x, hn);
	re *= re;
	re *= myPow(x, remain);
	if (flag)
	{
		re = 1.0 / re;
	}
	return re;

}

double myPow(double x, int n) {
	long long tn = n;
	return myPow(x, tn);
}

int main50(){
	double re = myPow(4.0, -3);
	return 0;
}