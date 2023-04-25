#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "p_base.h"

int aleatoire_entre_a_et_b(int a_inclus, int b_exclu) {
  int i = rand() % (b_exclu - a_inclus) + a_inclus;
  return i;
}

void identite_tableau(int* ceci, int nb_elements){
    for(int i = 0; i < nb_elements; i++){
        ceci[i] = i;
    }
}

void echanger_tableau(int* ceci, int position_1, int position_2){
    int temp = ceci[position_1];
    ceci[position_1] = ceci[position_2];
    ceci[position_2] = temp;
}

void croiser_tableau(int* tab, int nb_elements){
    
}