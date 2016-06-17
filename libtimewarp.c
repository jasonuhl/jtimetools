#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#define GNU_SOURCE
#include <dlfcn.h>
#include <assert.h>

int gettimeofday(struct timeval *tv, struct timezone *tz) {
	static struct timeval lasttv;
	int foo;
	void *dl;
	int (*realgettimeofday)(struct timeval *tv, struct timezone *tz);

	if (!lasttv.tv_sec) {
		dl = dlopen("libc.so.6", RTLD_LAZY);
		realgettimeofday = dlsym(dl, "gettimeofday");

		foo = realgettimeofday(&lasttv, tz);
		assert(!foo);
	}

	*tv = lasttv;
	lasttv.tv_sec += 5;

	return 0;
}

time_t time(time_t *t) {
	static time_t lastt;
	void *dl;
	int (*realtime)(time_t *t);

	if (!lastt) {
		dl = dlopen("libc.so.6", RTLD_LAZY);
		realtime = dlsym(dl, "time");

		lastt = realtime(NULL);
	}

	lastt += 5;

	if (t)
		*t = lastt;

	return lastt;
}
