#include <stdio.h>
#include "perms.h"

int main(void) {
    struct perms_t hello_txt;
    hello_txt.user.read = true;
    hello_txt.group.read = true;
    hello_txt.others.read = true;

    //Jeg giver goodbye.txt rettighederne: -rwxr--r--
    struct ny_perms_t goodbye_txt;
    goodbye_txt.bits = USER_READ | USER_WRITE | USER_EXECUTE | GROUP_READ | OTHERS_READ;

    char *ny_perms = ny_fmt_perms(goodbye_txt);
    printf("goodbye.txt bits er: %o\n", goodbye_txt.bits);


    char *perms = fmt_perms(hello_txt);
    printf("hello.txt har rettighederne %s\n", perms);

    // TODO: Lav en masse tests

    //Jeg tjekker om goodbye text er læselig af sin owner
    if (goodbye_txt.bits & USER_READ) {
        printf("Goodbye.txt er læselige for sin owner\n");
    }
    //Jeg tjekker om den kan executes af group
    if (goodbye_txt.bits & GROUP_EXECUTE) {
        printf("Goodbye.txt kan executes af sin group");
    }
    else {
        printf("Goodbye.txt kan ikke executes af sin group");
    }



    return 0;
}