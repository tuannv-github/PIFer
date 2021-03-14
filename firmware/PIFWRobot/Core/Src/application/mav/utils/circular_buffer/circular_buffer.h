#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct{
	uint8_t *buffer;
	size_t  size;
	size_t  head;
	size_t  tail;
	bool    full;
}circular_buf_t;

void cbuf_init(circular_buf_t *cbuf, uint8_t *buf, size_t size);
void cbuf_reset(circular_buf_t  *cbuf);

int cbuf_put(circular_buf_t* cbuf, char data);
int cbuf_get(circular_buf_t* cbuf, char *data);

bool cbuf_empty(circular_buf_t *cbuf);
bool cbuf_full(circular_buf_t *cbuf);
size_t cbuf_size(circular_buf_t* cbuf);

#endif //CIRCULAR_BUFFER_H_
