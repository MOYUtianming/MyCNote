#include "main.h"
#include "uthash.h"
#include "status_report.h"
typedef struct HashTableT {
    int intNum;
    double doubleNum;
    char str[10];
    UT_hash_handle hh;
} HashT;

SType AddHash(HashT* hashT, HashT* hashElem)
{
    HASH_ADD_INT(hashT, str, hashElem);
}
