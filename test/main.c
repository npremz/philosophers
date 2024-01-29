#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>

void timetest()
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return ;
	printf("%ld seconds\n", time.tv_sec);
	printf("%d microseconds\n", time.tv_usec);
	printf("%ld", time.tv_sec / 60 / 60 / 24 / 365);
}

int main(void)
{
	timetest();
	return (0);
}
