#ifndef HASHTAB_H_
#define HASHTAB_H_

struct HashTab {
    char *key;
    uint32_t value;

    struct HashTab *next;
};

unsigned int KRHash(char *s); // // 
unsigned int DJBHash(char* str, unsigned int len) ; // //
void hashtab_init(struct HashTab **hashtab); // //
void hashtab_print(struct HashTab **hashtab); // //
void hashtab_add(struct HashTab **hash_tab, char *key, int value); // //
struct HashTab *hashtab_lookup(struct HashTab **hash_tab, char *key); // // 
void hashtab_delete(struct HashTab **hash_tab, char *key);
void hashtab_clear(struct HashTab **hash_tab);

#endif //HASHTAB_H_