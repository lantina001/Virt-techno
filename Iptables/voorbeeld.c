#include <getopt.h>
#include <sys/errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <time.h>
#include "libiptc/libiptc.h"
#include "iptables.h"

int main(void)
{
	iptc_handle_t h;
	const char *chain = NULL;
	const char *tablename = "filter";

	program_name = "p1";
	program_version = NETFILTER_VERSION;

	h = iptc_init(tablename);
	if (!h) {
		printf("Error initializing: %s\n", iptc_strerror(errno));
		exit(errno);
	}

	for (chain = iptc_first_chain(&h); chain; chain = iptc_next_chain(&h)) {
		printf("%s\n", chain);

	}