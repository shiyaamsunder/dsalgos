#pragma once

#define H_HASH unsigned int
#define H_KEY int
#define H_TABLE H_KEY*

/*
    Computes a simple hash on the given value. (key mod m).

    Use mode 'size' on the hash value
*/
H_HASH hash_fn(H_KEY key, int m);

/*
    Inserts -1 to all the values in the hash_table.
*/
void empty_hash_table(H_TABLE h_table, int size);
/*
    Creates a new hash_table that can be reallocated later.
*/
int* create_hash_table(int size);

int insert(H_KEY key, int m, H_TABLE h_table, int size);
int delete(H_KEY key, int m, H_TABLE h_table, int size);

int linear_probe(H_KEY key, int m, H_TABLE h_table, int size);

void print_table(H_TABLE h_table, int size);
