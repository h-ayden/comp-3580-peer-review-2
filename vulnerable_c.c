// vulnerable_c.c

/*
Demonstrates:
- Stack buffer overflow
- Format string vulnerability

Compile

On Linux:

gcc vulnerable_c.c -o vulnerable_c -fno-stack-protector -no-pie

(Those flags disable some protections so the vulnerabilities are easier to observe in a lab.)

Example attacks (next 2):

Buffer overflow
Input a very long string:
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

Format string exploit
Input:
%x %x %x %x
or
%s%s%s%s
*/
#include <stdio.h>
#include <string.h>

int main() {
    char name[32];

    printf("Enter your name: ");

    // Vulnerability #1: Buffer overflow
    gets(name);

    // Vulnerability #2: Format string vulnerability
    printf(name);

    printf("\n");

    return 0;
}
