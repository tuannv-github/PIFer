#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "circular_buffer.h"

void cbuf_init(circular_buf_t *cbuf, uint8_t *buf, size_t size)
{
	cbuf->buffer = buf;
	cbuf->size = size;
	cbuf_reset(cbuf);
}

void cbuf_reset(circular_buf_t  *cbuf)
{
    cbuf->head = 0;
    cbuf->tail = 0;
    cbuf->full = false;
}

int cbuf_put(circular_buf_t* cbuf, char data)
{
    if(!cbuf_full(cbuf))
    {
        cbuf->buffer[cbuf->head] = data;
        cbuf->head = (cbuf->head + 1) % cbuf->size;
        cbuf->full = (cbuf->head == cbuf->tail);
        return 0;
    }
    return -1;
}

int cbuf_get(circular_buf_t *cbuf, char *data)
{
    if(!cbuf_empty(cbuf))
    {
        *data = cbuf->buffer[cbuf->tail];
    	cbuf->tail = (cbuf->tail + 1) % cbuf->size;
    	cbuf->full = false;
        return 0;
    }
    return -1;
}

bool cbuf_empty(circular_buf_t* cbuf)
{
    return (!cbuf->full && (cbuf->head == cbuf->tail));
}

bool cbuf_full(circular_buf_t *cbuf)
{
    return cbuf->full;
}

size_t cbuf_size(circular_buf_t* cbuf)
{
	size_t size = cbuf->size;

	if(!cbuf->full)
	{
		if(cbuf->head >= cbuf->tail)
		{
			size = (cbuf->head - cbuf->tail);
		}
		else
		{
			size = (cbuf->size + cbuf->head - cbuf->tail);
		}

	}

	return size;
}
