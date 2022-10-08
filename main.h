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
    struct s_env *prev;
} t_env;

int ft_strcmp(char *s1, char *s2);
t_env *pars_env(char **env);
char **get_arr_env(t_env *l_env);

#endif