#include <stdlib.h>
#include "ft_list.h"

// La fonction prend en entrée un pointeur vers le début de la liste, une référence de données et un pointeur vers une fonction de comparaison
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    // Si la liste est vide ou si le début de la liste est nul, on retourne
    if (begin_list == NULL || *begin_list == NULL)
        return;

    // On crée un pointeur 'cur' pour parcourir la liste
    t_list *cur = *begin_list;

    // Si les données du nœud actuel correspondent à la référence de données (selon la fonction de comparaison)
    if (cmp(cur->data, data_ref) == 0)
    {
        // On fait pointer le début de la liste vers le nœud suivant
        *begin_list = cur->next;
        // On libère la mémoire du nœud actuel
        free(cur);
        // On fait un appel récursif à la fonction pour continuer à parcourir la liste à partir du nouveau début
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    
    // On réinitialise le pointeur 'cur' au début de la liste
    cur = *begin_list;
    // On fait un appel récursif à la fonction pour continuer à parcourir la liste à partir du nœud suivant
    ft_list_remove_if(&cur->next, data_ref, cmp);
}
