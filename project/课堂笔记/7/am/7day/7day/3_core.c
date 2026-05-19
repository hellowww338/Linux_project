#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{   
    char *p = NULL;
    *p = 'x';
    printf("%c\n", *p);
    printf("game over\n");
    return 0;

}

