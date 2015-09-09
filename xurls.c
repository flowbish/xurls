#include <regex.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Must supply input!\n");
        return 1;
    }
    regex_t reg;
    char *regex = "\\bhttp://(.*)\\b";
    int cflags = REG_EXTENDED | REG_ICASE;
    int comp_error = regcomp(&reg, regex, cflags);
    regmatch_t matches[10];
    int exec_error = regexec(&reg, argv[1], 10, matches, 0);  
    if (exec_error) {
        char buf[200];
        regerror(exec_error, &reg, buf, 200);
        fprintf(stderr, "%s\n", buf);
        return 1;
    }
    printf("works!");
    regfree(&reg);
}
