
#include "shell.h"

bool    clear_lexer(t_lexer **head)
{
    t_lexer *next;
    t_lexer *temp;

    temp = *head;
    while (temp)
    {
        next = temp->next;
        free(temp);
        temp->next;
    }
    *head = NULL;
    return (false);
}
