#include "../Includes/main.h"

// unset builtin 
void ft_unset(t_env **env, char *var_name)
{
    t_env *curr_env;
    int i;
   
    if (!var_name)
        return ;
    curr_env = *env;
    while (curr_env) 
    {
        if (ft_strcmp(curr_env->val_name, var_name) == 0)
        {
            curr_env->prev->next = curr_env->next;
            free(curr_env);
            return ;
        }
        curr_env = curr_env->next;
    }
}

int main(int argc, char **argv, char **env)
{
    t_env *environ;

    if (!argv[1])
        return (1);
    environ = pars_env(env);
    ft_unset(&environ, argv[1]);
    env = get_arr_env(environ);
}