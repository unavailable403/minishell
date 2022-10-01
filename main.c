#include "main.h"

void error_exit(int err_num)
{
    if (err_num == 0)
        printf("Error: Arguments error");
    exit(0);
}



// env 
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



//get the linked list from char** ENV
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
        list_env = list_env->next;
        index++;
    }
    return env_start;
}
//++++++++++++++++++++++++++++++++++++++++++++
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
    printf("%s\n", line);
    return line;
}

// get the char ** from linked list 
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


int main(int argc, char **argv, char **env_main)
{
    t_env *env;
    char **environ;
    if (argc != 1)
        error_exit(0);
    // parse the env and get the linked list
    env = pars_env(env_main);
    // parse back and get the 2 dimensional array
    environ = get_arr_env(env);

    
}
   
