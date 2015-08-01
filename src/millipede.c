#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MILLIPEDE_PART_MAX_SIZE	42

#define MILLIPEDE_HEAD "╚⊙ ⊙╝"
#define MILLIPEDE_BODY "╚═(███)═╝"

struct millipede {
	unsigned int curve;
	unsigned int pos;
	int dir;

	char	*head;
	char	*body;

	char	buf[MILLIPEDE_PART_MAX_SIZE];
};

char *
millipede_head(struct millipede *ctx) {
	int i;

	for (i = 0; i < ctx->pos + 2; i++)
		ctx->buf[i] = ' ';

	if (sprintf(ctx->buf + i, "%s", ctx->head ? ctx->head : MILLIPEDE_HEAD) < 0)
		return NULL;

	return ctx->buf;
}

char *
millipede_body(struct millipede *ctx) {
	int i;

	for (i = 0; i < ctx->pos; i++)
		ctx->buf[i] = ' ';

	ctx->pos += ctx->dir;
	if (ctx->pos > ctx->curve) {
		ctx->dir = -1;
		ctx->pos = ctx->pos > ctx->curve ? ctx->pos - 1 : ctx->curve;
	} else if (ctx->pos == 0) {
		ctx->dir = 1;
	}

	if (sprintf(ctx->buf + i, "%s", ctx->body ? ctx->body : MILLIPEDE_BODY) < 0)
		return NULL;

	return ctx->buf;
}

int
millipede_set_curve(struct millipede *ctx, unsigned int curve) {
	if (curve + strlen(ctx->body ? ctx->body : MILLIPEDE_BODY) > MILLIPEDE_PART_MAX_SIZE)
		return 1;

	ctx->curve = curve;
	return 0;
}

int
millipede_set_start(struct millipede *ctx, unsigned int start) {
	if (start + strlen(ctx->body ? ctx->body : MILLIPEDE_BODY) > MILLIPEDE_PART_MAX_SIZE)
		return 1;
	
	ctx->pos = start;
	return 0;
}

void
millipede_set_dir(struct millipede *ctx, int dir) {
	ctx->dir = dir > 0 ? 1 : -1;
}

int
millipede_set_head(struct millipede *ctx, const char *head) {
	if (ctx->head)
		free(ctx->head);

	if ((ctx->head = strdup(head)) == NULL)
		return 1;

	return 0;
}

int
millipede_set_body(struct millipede *ctx, const char *body) {
	if (ctx->body)
		free(ctx->body);

	if ((ctx->body = strdup(body)) == NULL)
		return 1;

	return 0;
}

struct millipede *
millipede_init(void) {
	struct millipede *ctx = NULL;

	if ((ctx = calloc(1, sizeof(*ctx))) == NULL)
		goto err;

	/* Default value */
	ctx->curve = 4;
	ctx->pos = 2;
	ctx->dir = -1;

	return ctx;

 err:
	if (ctx)
		free(ctx);
	return NULL;
}
