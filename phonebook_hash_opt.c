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
/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *table[])
{
    /* TODO: implement */
    unsigned int h_index = BKDRHash(lastName);
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
    unsigned int h_index = BKDRHash(lastName);
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


