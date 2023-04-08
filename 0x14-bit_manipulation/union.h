#ifndef UNION_H
#define UNION_H

union
{
	int n;
	char c[sizeof(int)];
} endian;

#endif /* UNION_H */
