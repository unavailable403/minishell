#include "main.h"

int get_env_var_count(t_env *l_env)
{
    int l;

    l = 0;
    while (l_env->next)
    {
        l++;
        l_env = l_env->next;
    }
    return l + 1;
}

char *get_line_env(t_env *l_env)
{
    char *line;
    int i;
    int j;
    int name;
    int value;

    name = ft_strlen(l_env->val_name);
    value = ft_strlen(l_env->val_value);
    i = 0;
    line = malloc(name + value + 2);
    if (!line)
        return NULL;
    while (i < name)
    {
        line[i] = l_env->val_name[i];
        i++;
    }
    line[i] = '=';
    i++;
    j = 0;
    while (j < value)
    {
        
        line[i] = l_env->val_value[j];
        i++;
        j++;
    }
    line[i] = '\0';
    return line;
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    if (ft_strlen(s1) != ft_strlen(s2) || !s1 || !s2)
        return (-1);
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return(-1);
        i++;
    }
    return (0);
}

char *get_val(char *env_line)
{
    int i;
    int tmp;
    char *value;

    i = 0;
    while (env_line[i] != '=')
        i++;
    tmp = i;
    i++;
    while (env_line[i] != '\0')
        i++;
    value = malloc(i - tmp);
    if (!value)
        return NULL;
    while (i > tmp)
    {
        value[i - tmp - 1] = env_line[i];
        i--;
    }
    return value;
}

char *get_val_name(char *env_line)
{
    int i;
    char *value;

    i = 0;
    while (env_line[i] != '=' && env_line[i] != '\0')
        i++;
    value = malloc(i);
    if (!value)
        return (NULL);
    value[i] = '\0';
    i--;
    while(i >= 0)
    {
        value[i] = env_line[i];
        i--;
    }
    return value;
}
