Nom de l'assignation : ft_list_remove_if
Fichiers attendus : ft_list_remove_if.c
Fonctions autorisées : free
--------------------------------------------------------------------------------

Écrivez une fonction appelée ft_list_remove_if qui supprime de la
liste passée tout élément dont les données sont "équivalentes" aux données de référence.

Il sera déclaré comme suit :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp prend deux void* et renvoie 0 lorsque les deux paramètres sont égaux.

Vous devez utiliser le fichier ft_list.h, qui contiendra :

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
