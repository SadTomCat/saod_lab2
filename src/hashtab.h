#ifndef HASHTAB_H_
#define HASHTAB_H_

struct HashTab {
    char *key;
    uint32_t value;
};

unsigned int KRHash(char *s); // // 
unsigned int DJBHash(char* str, unsigned int len) ; // //
void hashtab_init(struct HashTab **hashtab); // //
void hashtab_print(struct HashTab **hashtab); // //
void hashtab_add_DJB(struct HashTab **hash_tab, char *key, int value); // //
void hashtab_add_KR(struct HashTab **hash_tab, char *key, int value); // // 
struct HashTab *hashtab_lookup_KR(struct HashTab **hash_tab, char *key); // // 
struct HashTab *hashtab_lookup_DJB(struct HashTab **hash_tab, char *key); // // 
void hashtab_delete_KR(struct HashTab **hash_tab, char *key);
void hashtab_delete_DJB(struct HashTab **hash_tab, char *key);

#endif //HASHTAB_H_