#ifndef MAIN_H
# define MAIN_H

// libs
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "libft/libft.h"


typedef struct s_env {
    char *val_name;
    char *val_value;
    struct s_env *next;
} t_env;

#endif