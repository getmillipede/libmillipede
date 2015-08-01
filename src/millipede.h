#ifndef __MILLIPEDE_H__
# define __MILLIPEDE_H__

struct millipede;

struct millipede *millipede_init(void);
char *millipede_head(struct millipede *ctx);
char *millipede_body(struct millipede *ctx);
int millipede_set_curve(struct millipede *ctx, unsigned int curve);
int millipede_set_start(struct millipede *ctx, unsigned int start);
void millipede_set_dir(struct millipede *ctx, int dir);
int millipede_set_head(struct millipede *ctx, const char *body);
int millipede_set_body(struct millipede *ctx, const char *body);

#endif
