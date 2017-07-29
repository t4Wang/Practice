/*
	多项式的和
	1. a0 + a1*x + a2*x^2 + ... +an*x^n
	2. a0 + x(a1 + x(a2 + ... x(an-1 + x(an))))	n项
*/
#include <math.h>
#include <stdio.h>
#include <time.h>

int fun1(int n, int a[], int x) {
	int sum = a[0];
	for (int i = 1; i <= n; i++) {
		sum += a[i] * pow(x, i);
	}
	return sum;
}
int fun2(int n, int a[], int x) {
	int sum = a[n];
	for (int i = n - 1; i >= 0; i--) {
		sum = a[i] + x * sum;
	}
	return sum;
}
/*
	param: n 项数, a 参数, x 未知数
*/
int polynomial(int n, int a[], int x) {
	return fun2(n, a, x);
}

int main() {
	int n = 11;
	int a[12];
	for (int i = 0; i <= n; i++) {
		a[i] = i % 8 - i % 3;
	}
	int x = 2;
	
	clock_t start, stop;
	double duration;

	start = clock();
	for (int i = 0; i < 1000000; i++)
		polynomial(n, a, x);
	stop = clock();

	duration = ((double)(stop - start)) / CLK_TCK;

	printf("\n%f\n", duration);

	scanf("%f", &x);
	return 0;
}
