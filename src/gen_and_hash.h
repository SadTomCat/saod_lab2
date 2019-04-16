#ifndef GEN_AND_HASH_H_
#define GEN_AND_HASH_H_

#define HASH_SIZE 40

void generation_word2(char* str);
unsigned int DJBHash(char* str, unsigned int len);
unsigned int KRHash(char *s);
//void generation_word(char** word);

#endif //GEN_AND_HASH_H_