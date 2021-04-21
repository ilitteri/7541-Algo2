#include "main.h" // No borrar

size_t raiz_entera(size_t n) {
    if (n < 2)
		return n;

	int res;

	int inicio = 1;
	int fin = n/2;

	while (inicio <= fin) {
		int mid = (inicio + fin) / 2;
		long sqr = mid*mid;

		if (sqr == n)
			return mid;

		else if (sqr < n) {
			inicio = mid + 1;
			res = mid;
		}

		else
			fin = mid - 1;
	}

	return res;
}