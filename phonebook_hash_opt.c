#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash_opt.h"

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }
    return (hash % HASH_TABLE_LENGTH);
}
unsigned int APHash(char *str)
{
    unsigned int hash = 0;

    for (int i=0; *str; ++i) {
        if ((i & 1) == 0) {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        } else {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }

    return ((hash & 0x7FFFFFFF) % HASH_TABLE_LENGTH);

}
unsigned int DJBHash(char *str)
{
    unsigned int hash = 5381; // magic number

    while (*str) {
        hash += (hash << 5) + (*str++);
    }

    return ((hash & 0x7FFFFFFF) % HASH_TABLE_LENGTH);

}
unsigned int SDBMHash(char *str)
{
    unsigned int hash = 0;
    while (*str) {
        hash = hash * 65599 + (*str++);
    }
    return ((hash & 0x7FFFFFFF) % HASH_TABLE_LENGTH);
}
unsigned int ELFHash(char *str)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    while (*str) {
        hash = (hash << 4) + (*str++);
        if ((x = hash & 0xF0000000L) != 0) {// 28-31 is 1 others are 0
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }
    return ((hash & 0x7FFFFFFF) % HASH_TABLE_LENGTH);
}
/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *table[])
{
    /* TODO: implement */
    //unsigned int h_index = BKDRHash(lastName);
    //unsigned int h_index = APHash(lastName);
    //unsigned int h_index = DJBHash(lastName);
    //unsigned int h_index = SDBMHash(lastName);
    unsigned int h_index = ELFHash(lastName);

    while (table[h_index] != NULL) {
        if (strcasecmp(lastName, table[h_index]->lastName ) == 0) {
            return table[h_index];
        }
        table[h_index] = table[h_index]->pNext;
    }
    return NULL;
}

void append(char lastName[], entry *table[])
{
    /* TODO: implement */
    //unsigned int h_index = BKDRHash(lastName);
    //unsigned int h_index = APHash(lastName);
    //unsigned int h_index = DJBHash(lastName);
    //unsigned int h_index = SDBMHash(lastName);
    unsigned int h_index = ELFHash(lastName);

    entry *slot = (entry *)malloc(sizeof(entry));
    slot->pNext = table[h_index];
    if (!table[h_index]) {
        table[h_index] = slot;
        strcpy(slot->lastName, lastName);
    } else {
        table[h_index]->pNext = slot;
        strcpy(slot->lastName, lastName);
    }

}

void init(entry *table[])
{
    for (int i = 0; i < HASH_TABLE_LENGTH; ++i) {
        table[i] = NULL;
    }
}


