#include <stdio.h>

int main(){
	int a, b, c;
	a = 1;
	b = 2;
	asm volatile (
		"sha512sig1l %[z], %[x], %[y]\n\t"
		: [z] "=r" (c)
		: [x] "r" (a), [y] "r" (b)
	);
	asm volatile (
		"sha512sig1h %[z], %[x], %[y]\n\t"
		: [z] "=r" (c)
		: [x] "r" (a), [y] "r" (b)
	);
	asm volatile (
		"sha512sum0r %[z], %[x], %[y]\n\t"
		: [z] "=r" (c)
		: [x] "r" (a), [y] "r" (b)
	);
	asm volatile (
		"sha512sum1r %[z], %[x], %[y]\n\t"
		: [z] "=r" (c)
		: [x] "r" (a), [y] "r" (b)
	);
  return 0;
}
