#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdbool.h>

/// Opaque circular buffer structure
// The definition of our circular buffer structure is hidden from the user
typedef struct{
	uint8_t * buffer;
	size_t head;
	size_t tail;
	size_t max; //of the buffer
	bool full;
}circular_buf_t;

/// Pass in a size, returns a circular buffer handle
/// Requires: size > 0
/// Ensures: cbuf has been created and is returned in an empty state
void circular_buf_init(circular_buf_t* circular_buf, uint8_t* buf,size_t size);

/// Free a circular buffer structure
/// Requires: cbuf is valid and created by circular_buf_init
/// Does not free data buffer; owner is responsible for that
void circular_buf_free(circular_buf_t* cbuf);

/// Reset the circular buffer to empty, head == tail. Data not cleared
/// Requires: cbuf is valid and created by circular_buf_init
void circular_buf_reset(circular_buf_t* cbuf);

/// Put version 1 continues to add data if the buffer is full
/// Old data is overwritten
/// Requires: cbuf is valid and created by circular_buf_init
/// Returns 0 on success, -1 if buffer is full
int circular_buf_put(circular_buf_t* cbuf, uint8_t data);

/// Put Version 2 rejects new data if the buffer is full
/// Requires: cbuf is valid and created by circular_buf_init
/// Returns 0 on success, -1 if buffer is full
int circular_buf_put2(circular_buf_t* cbuf, uint8_t data);

/// Retrieve a value from the buffer
/// Requires: cbuf is valid and created by circular_buf_init
/// Returns 0 on success, -1 if the buffer is empty
int circular_buf_get(circular_buf_t* cbuf, uint8_t * data);

/// CHecks if the buffer is empty
/// Requires: cbuf is valid and created by circular_buf_init
/// Returns true if the buffer is empty
bool circular_buf_empty(circular_buf_t* cbuf);

/// Checks if the buffer is full
/// Requires: cbuf is valid and created by circular_buf_init
/// Returns true if the buffer is full
bool circular_buf_full(circular_buf_t* cbuf);

/// Check the capacity of the buffer
/// Requires: cbuf is valid and created by circular_buf_init
/// Returns the maximum capacity of the buffer
size_t circular_buf_capacity(circular_buf_t* cbuf);

/// Check the number of elements stored in the buffer
/// Requires: cbuf is valid and created by circular_buf_init
/// Returns the current number of elements in the buffer
size_t circular_buf_size(circular_buf_t* cbuf);

//TODO: int circular_buf_get_range(circular_buf_t cbuf, uint8_t *data, size_t len);
//TODO: int circular_buf_put_range(circular_buf_t cbuf, uint8_t * data, size_t len);

#endif //CIRCULAR_BUFFER_H_
