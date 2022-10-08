#include "../main.h"
#include <fcntl.h>

int main(int ac, char **argv, char **env)
{
    if (argc < 2)
        chdir("~/");
    else if (argc > 3)
    {
        printf("cd: too many arguments\n");
        exit(2);
    }
    int fd = open("./README.md", O_RDONLY);
    printf("%d\n", fd);
    //Printing the now current working directory
    printf("%s\n",getcwd(s,100));
    return 0;
}