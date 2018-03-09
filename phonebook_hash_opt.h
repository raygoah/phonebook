#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define HASH_TABLE_LENGTH 1024
#define HASH_OPT 1
typedef struct __PHONE_OTHER_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} otherEntry;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
    otherEntry *other;
} entry;



entry *findName(char lastName[], entry *table[]);
void append(char lastName[], entry **table);
unsigned int BKDRHash(char *str);
unsigned int APHash(char *str);
unsigned int DJBHash(char *str);
unsigned int SDBMHash(char *str);
unsigned int ELFHash(char *str);
void init(entry * table[]);

#endif
