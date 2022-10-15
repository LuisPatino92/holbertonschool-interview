#include <stdio.h>
#include "palindrome.h"

/**
 * invert - inverts a value in an int pointer
 *
 * @n: Val to invert
 * @store: P to value will be stored
 *
 * Return: No Return
 */
void invert(unsigned long n, unsigned long *store) {
	if (n > 0) {
		*store = *store * 10 + (n % 10);
		n /= 10;
		invert(n, store);
	}

}

/**
 * is_palindrome - Entry point
 *
 * @n: Number to check
 *
 * Return: 0 if not a Pal
 */
int is_palindrome(unsigned long n) {
	unsigned long store = 0;

	invert(n, &store);

	if (store != n)
		return (0);

	return (1);
}
