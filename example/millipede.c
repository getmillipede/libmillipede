/*
 * After installing libmillipede, compile with :
 * cc millipede.c `pkg-config --libs libmillipede` `pkg-config --cflags libmillipede`
 */

#include <err.h>
#include <stdio.h>
#include <getopt.h>

#include "millipede.h"

int
main(int argc, char *argv[]) {
	struct millipede *millipede;
	int opt;
	unsigned int size = 10;
	int dir = -1;
	unsigned int start = 2;
	unsigned int curve = 4;
	int i;

	while ((opt = getopt(argc, argv, "s:d:p:c:")) != -1) {
		switch (opt) {
		case 's':
			size = strtoul(optarg, NULL, 10);
			break;
		case 'd':
			dir = strtol(optarg, NULL, 10);
			break;
		case 'p':
			start = strtoul(optarg, NULL, 10);
			break;
		case 'c':
			curve = strtoul(optarg, NULL, 10);
			break;
		}
	}

	if ((millipede = millipede_init()) == NULL)
		errx(1, "millipede_init: error");

	if (millipede_set_head(millipede, "\\o o/"))
		errx(1, "millipede_set_head: error");
	if (millipede_set_body(millipede, "|=(###)=|"))
		errx(1, "millipede_set_head: error");

	if (millipede_set_start(millipede, start))
		errx(1, "millipede_set_start: error\n");
	if (millipede_set_curve(millipede, curve))
		errx(1, "millipede_set_curve: error\n");
	millipede_set_dir(millipede, dir);

	printf("%s\n", millipede_head(millipede));
	for (i = 0; i < size; i++)
		printf("%s\n", millipede_body(millipede));
	return 0;
}
