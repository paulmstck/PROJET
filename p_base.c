#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "p_base.h"

int aleatoire_entre_a_et_b(int a_inclus, int b_exclu)
{
    int i = rand() % (b_exclu - a_inclus) + a_inclus;
    return i;
}

void identite_tableau(int *ceci, int nb_elements)
{
    for (int i = 0; i < nb_elements; i++)
    {
        ceci[i] = i;
    }
}

void echanger_tableau(int *ceci, int position_1, int position_2)
{
    int temp = ceci[position_1];
    ceci[position_1] = ceci[position_2];
    ceci[position_2] = temp;
}

void croiser_tableau(int *tab, int nb_elements)
{
    int debut = 0;
    int fin = nb_elements - 1;

    while (debut < fin)
    {
        echanger_tableau(tab, debut, fin);
        debut++;
        fin--;
    }
}

void copier_tableau(int* tab, int* dans, int nb_elements){
    for (int i = 0; i < nb_elements; i++)
    {
        dans[i] = tab[i];
    }
}

void copier_croisement_tableau(int *tab, int *dans, int nb_elements)
{
    int debut = 0;
    int fin = nb_elements - 1;

    while (debut < fin)
    {
        dans[debut] = tab[fin];
        dans[fin] = tab[debut];
        debut++;
        fin--;
    }
}

int est_inferieur_strict_tableau(int *ceci, int *cela, int nb_elements)
{
    for (int i = 0; i < nb_elements; i++)
    {
        if (ceci[i] < cela[i])
        {
            return 1;
        }
        else if (ceci[i] > cela[i])
        {
            return 0;
        }
    }
    return 0;
}