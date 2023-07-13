// Inclusion du fichier d'en-tête approprié et des bibliothèques standard
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Fonction pour échanger les valeurs de deux nœuds dans une liste
void	swap_values(t_list *a, t_list *b)
{
	int tmp;

	// tmp garde la valeur de a pour ne pas la perdre lors de l'affectation
	tmp = a->data;
	a->data = b->data; // la valeur de a devient celle de b
	b->data = tmp; // la valeur de b prend la valeur originale de a (actuellement stockée dans tmp)
}

// Fonction pour trier une liste en utilisant une fonction de comparaison passée en paramètre
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swapped = 1; // variable pour savoir si un échange a eu lieu
	t_list *cur = lst; // pointeur vers le début de la liste

	// Continue à passer à travers la liste jusqu'à ce qu'il n'y ait plus d'échanges
	while (swapped == 1)
	{
		swapped = 0; // part du principe qu'il n'y aura pas d'échange
		// parcourt la liste
		while (cur != 0 && cur->next != 0)
		{
			// si les deux éléments ne sont pas dans le bon ordre (selon la fonction de comparaison)
			if (cmp(cur->data, cur->next->data) == 0)
			{
				swap_values(cur, cur->next); // échange les deux éléments
				swapped = 1; // marque qu'un échange a eu lieu
			}
			cur = cur->next; // passe à l'élément suivant dans la liste
		}
		cur = lst; // revient au début de la liste pour la prochaine itération
	}
	return (lst); // renvoie la liste triée
}
