# libmillipede

Library to print a beautiful millipede

# API

```c
struct millipede *millipede_init(void);
```

Initialize a millipede context.

```c
int millipede_set_curve(struct millipede *ctx, unsigned int curve);
```

Change the curve of the millipede (i.e. how many max spaces before the left-most body part)

```c
int millipede_set_start(struct millipede *ctx, unsigned int start);
```

Change the beginning position of the first millipede body part, the head position is automatically calculated.

```c
void millipede_set_dir(struct millipede *ctx, int dir);
```

Change the direction of the millipede, default is to go left.

```c
int millipede_set_head(struct millipede *ctx, const char *body);
```

Change the head of the millipede, the default is ```╚⊙ ⊙╝```.

```c
int millipede_set_body(struct millipede *ctx, const char *body);
```

Change the body of the millipede, the default is ```╚═(███)═╝```

```c
char *millipede_head(struct millipede *ctx);
```

Returns a NULL-terminated string containing the padded head of the millipede.

```
char *millipede_body(struct millipede *ctx);
```

Returns a NULL-terminated string containing the padded body of the millipede.

## Support

* [Stack Overflow](http://stackoverflow.com/questions/tagged/millipede)
* [Twitter](https://twitter.com/getmillipede)
* [#getmillipede](http://webchat.freenode.net?channels=%23getmillipede&uio=d4) on Freenode

## License

[MIT](https://github.com/getmillipede/millipede-asm-x86_64/blob/master/LICENSE)
