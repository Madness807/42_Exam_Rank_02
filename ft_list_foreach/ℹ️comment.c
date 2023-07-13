// Inclusion du fichier d'en-tête approprié
#include "ft_list.h"

// Cette fonction applique une fonction fournie par l'utilisateur (f) à chaque élément d'une liste
void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *list_ptr; // Pointeur de liste pour parcourir la liste

	list_ptr = begin_list; // Initialisation du pointeur de liste à l'élément de début de la liste
	// Parcourt la liste jusqu'à la fin
	while (list_ptr)
	{
		(*f)(list_ptr->data); // Appelle la fonction f avec l'élément actuel de la liste
		list_ptr = list_ptr->next; // Passe à l'élément suivant de la liste
	}
}

/*
///////////////////////////////////////////////////////////////
A inclure dans le fichier ft_list.h

#ifndef FT_LIST_H
#define FT_LIST_H

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

#endif
///////////////////////////////////////////////////////////////
*/