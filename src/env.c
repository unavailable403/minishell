#include "main.h"

char **get_arr_env(t_env *l_env)
{
    char **env;
    int l;
    int i;

    l = get_env_var_count(l_env);
    env = (char **)malloc((1 + l) * sizeof(char *));
    i = 0;
    while (i < l)
    {
        env[i] = get_line_env(l_env);
        l_env = l_env->next;
        i++;
    }
    env[i] = NULL;
    return env;
}

t_env *pars_env(char **env)
{
    t_env *list_env;
    t_env *env_start;
    int index;

    list_env = malloc(sizeof(t_env));
    env_start = list_env;
    if (!list_env)
        return NULL;
    index = 0;
    while (env[index] != NULL)
    {
        list_env->val_name = get_val_name(env[index]);
        list_env->val_value = get_val(env[index]);
        if (env[index + 1] == NULL)
        {
            list_env->next = NULL;
            break ;
        }
        list_env->next = malloc(sizeof(t_env));
        if (!list_env->next)
            return NULL;
        list_env->next->prev = list_env;
        list_env = list_env->next;
        index++;
    }
    return env_start;
}