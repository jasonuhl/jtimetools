#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

int main(void) {

        struct timeval tv;

        for (;;) {
                gettimeofday(&tv, NULL);
                printf("%ld %ld %s",
			(long)tv.tv_sec, (long)tv.tv_usec, ctime(&tv.tv_sec));
                tv.tv_sec = 0;
                tv.tv_usec = 1000000 - tv.tv_usec;
                select(0, NULL, NULL, NULL, &tv);
        }
}

