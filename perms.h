#ifndef AFL_2_DEMO_PERMS_H
#define AFL_2_DEMO_PERMS_H
#include <stdint.h>

struct rwe_t {
    bool read;
    bool write;
    bool execute;
};

// TODO: Lav den interne repræsentation i struct perms_t
// helt om, så den i stedet indeholder en enkelt uint32_t
struct perms_t {
    struct rwe_t user;
    struct rwe_t group;
    struct rwe_t others;
};

// Eksempel på hvordan det kan se ud:
struct ny_perms_t {
    uint32_t bits;
};

#define USER_READ     0400
#define USER_WRITE    0200
#define USER_EXECUTE  0100

#define GROUP_READ    0040
#define GROUP_WRITE   0020
#define GROUP_EXECUTE 0010

#define OTHERS_READ   0004
#define OTHERS_WRITE  0002
#define OTHERS_EXECUTE 0001

// Returner jeg en string, SKAL jeg heap-allokere
char *fmt_perms(struct perms_t);
char *ny_fmt_perms(struct ny_perms_t);

// Tager jeg output-string'en som input, undgår jeg
// at allokere inde i funktionen jeg bygger
// void fmt_perms(struct perms_t, char *);

#endif //AFL_2_DEMO_PERMS_H