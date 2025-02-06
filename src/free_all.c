/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** free_all.c
*/

#include "../include/minishell.h"
#include "my.h"

static
void free_struct_shell(all_t *all)
{
    free(all->shell.cmd);
    free(all->shell.my_env);
    free(all->shell.pwd);
    free(all->shell.buffer);
}

static
void free_linked_list(all_t *all)
{
    node_t *current = all->list.first;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

void free_all(all_t *all)
{
    free_struct_shell(all);
    free_linked_list(all);
    free(all);
}
