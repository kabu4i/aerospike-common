/******************************************************************************
 * Copyright 2008-2013 by Aerospike.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to 
 * deal in the Software without restriction, including without limitation the 
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
 * sell copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *****************************************************************************/
#pragma once

#include <aerospike/as_serializer.h>

#define AS_PACKER_BUFFER_SIZE 8192

typedef struct as_packer_buffer {
	struct as_packer_buffer * next;
	unsigned char * buffer;
	int length;
} as_packer_buffer;

typedef struct as_packer {
	struct as_packer_buffer * head;
	struct as_packer_buffer * tail;
	unsigned char * buffer;
	int offset;
	int capacity;
} as_packer;

typedef struct as_unpacker {
	unsigned char * buffer;
	int offset;
	int length;
} as_unpacker;

/******************************************************************************
 * FUNCTIONS
 ******************************************************************************/

as_serializer * as_msgpack_new();
as_serializer * as_msgpack_init(as_serializer *);

int as_pack_val(as_packer * pk, as_val * val);
int as_unpack_val(as_unpacker * pk, as_val ** val);