#include <stdio.h>
#include <stdlib.h>
#include <linear_probing.h>

H_HASH hash_fn(H_KEY key, int m){
    return key % m;
}

void empty_hash_table(H_TABLE h_table, int size){
    for(int i=0; i<size; i++){
        h_table[i] = -1;
    }
}
H_TABLE create_hash_table(int size){
    int* h_table = (int*)calloc(size, sizeof(int));
    empty_hash_table(h_table, size);
    return h_table;
}

int insert(H_KEY key, int m, H_TABLE h_table, int size){
    H_HASH hash= hash_fn(key, m) % size;
    if(h_table[hash] != -1){
        hash = linear_probe(key, m, h_table, size);
    }
    if(hash==-1){
        return 0;
    }
    h_table[hash] = key;
    return 1;
}

int linear_probe(H_KEY key, int m, H_TABLE h_table, int size) {
    int i=0;
    H_HASH hash = (hash_fn(key,  m) + i % m ) % size;
    while(i < size){
        ++i;
        hash = (hash_fn(key,  m) + i % m ) % size;
        if(h_table[hash]==-1){
            break;
        }
    }

    if(i==size)
    {
        return -1;
    }
    return hash;
}

void print_table(int *h_table, int size){
    printf("\n");
    for(int i=0; i<size; i++){
        printf("%d\n", h_table[i]);
    }
    printf("\n");
}


int delete(H_KEY key, int m, H_TABLE h_table, int size){
    H_HASH hash= hash_fn(key, m) % size;

    if(h_table[hash] != key){
        hash = linear_probe(key, m, h_table, size);
    }
    if(hash==-1){
        return 0;
    }
    h_table[hash] = -1;
    return 1;
}
