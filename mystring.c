#include <math.h>

int mystrlen(char *s) {
	int i = 0;
	while (*(s + i)) {
		i++;
	}
	return i;
}

char *mystrncpy(char *dest, char *source, int n) {
	int i;
	for (i = 0; i < n; i++) {
		char c = *(source + i);
		if (c) {
			*(dest + i) = c;
		} else {
			for (int j = i; j < n; j++) {
				*(dest + j) = 0;
			}
			break;
		}
	}
	return dest;
}

char *mystrncat(char *dest, char *source, int n) {
	int len = mystrlen(dest);
	int i;
	int terminated = 0;
	for (i = 0; i < n; i++) {
		char c = *(source + i);
		if (c) {
			*(dest + len + i) = c;
		} else {
			*(dest + len + i) = 0;
			terminated = 1;
			break;
		}
	}
	if (!terminated) {
		*(dest + len + n) = 0;
	}
	return dest;
}

int mystrcmp(char *s1, char *s2) {
	int j = 0;
	int i = 0;
	int s1len = mystrlen(s1);
	int s2len = mystrlen(s2);
	if (s1len > s2len) {
		i = s1len - 1;
	} else {
		i = s2len - 1;
	}
	int sum = 0;
	char s1C = 'c';
	char s2C = 'c';
	int lock1 = 0;
	int lock2 = 0;
	while (1) {
		if (s1C == 0) {
			lock1 = 1;
			if (s2C == 0) {
				break;
			}
		}
		if (s2C == 0) {
			lock2 = 1;
			if (s1C == 0) {
				break;
			}
		}
		s1C = *(s1 + j);
		s2C = *(s2 + j);
		if (lock1) {
			s1C = 0;
		}
		if (lock2) {
			s2C = 0;
		}
		sum += (s1C - s2C) * pow(256, i); //difference can range from 0 to 255 (127 - (-128)) so represent string with base 256
		j++;
		i--;
	}
	return sum;
}

char *mystrchr(char *s, char c) {
	char f = 'c';
	int i = 0;
	while (f != 0) {
		f = *(s + i);
		if (c == f) {
			return (s + i);
		}
		i++;
	}
	return (char *)0;
}