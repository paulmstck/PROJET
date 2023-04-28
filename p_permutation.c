#include <stdlib.h>
#include <stdio.h>
#include "p_permutation.h"

static int taille_permutation = 0;

t_boolean initialiser_p_permutation(int taille){
    if (taille_permutation == 0 && taille > 0){
        taille_permutation = taille;
        return TRUE;
    }
    else{
        return FALSE;
    }
}

t_boolean est_p_permutation_initialise() {
    return (taille_permutation != 0);
}

t_boolean donner_taille_permutation(int* taille)
{
    if (est_p_permutation_initialise() && taille != NULL){
        *taille = taille_permutation;
        return TRUE;
    }
    else{
        return FALSE;
    }
}

t_boolean initialiser_permutation(t_permutation* ceci) {
    if (est_p_permutation_initialise()) {
        *ceci = (t_permutation)malloc(taille_permutation * sizeof(int));
        for (int i = 0; i < taille_permutation; i++) {
            (*ceci)[i] = i;
        }
        return TRUE;
    } else {
        return FALSE;
    }
}

t_boolean finaliser_permutation(t_permutation* ceci) {
    if (est_p_permutation_initialise() && *ceci != NULL) {
        free(*ceci);
        *ceci = NULL;
        return TRUE;
    } else {
        return FALSE;
    }
}

t_boolean identite_permutation(t_permutation ceci) {
    if (est_p_permutation_initialise()) {
        for (int i = 0; i < taille_permutation; i++) {
            ceci[i] = i;
        }
        return TRUE;
    } else {
        return FALSE;
    }
}

t_boolean copier_permutation(t_permutation ceci, t_permutation cela) {
    if (est_p_permutation_initialise()) {
        for (int i = 0; i < taille_permutation; i++) {
            cela[i] = ceci[i];
        }
        return TRUE;
    } else {
        return FALSE;
    }
}

t_boolean debugger_permutation(t_permutation ceci) {
    if (est_p_permutation_initialise()) {
        printf("[ ");
        for (int i = 0; i < taille_permutation; i++) {
            printf("%d ", ceci[i]);
        }
        printf("]\n");
        return TRUE;
    } else {
        return FALSE;
    }
}

t_boolean est_indice_valide(int position) {
    if (est_p_permutation_initialise()) {
        return (position >= 0 && position < taille_permutation);
    } else {
        return FALSE;
    }
}

t_boolean melanger_permutation(t_permutation ceci) {
    if (est_p_permutation_initialise()) {
        for (int i = taille_permutation - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = ceci[i];
            ceci[i] = ceci[j];
            ceci[j] = temp;
        }
        return TRUE;
    } else {
        return FALSE;
    }
}

t_boolean reciproque_permutation(t_permutation ceci, t_permutation cela) {
    if (est_p_permutation_initialise()) {
        for (int i = 0; i < taille_permutation; i++) {
            cela[ceci[i]] = i;
        }
        return TRUE;
    } else {
        return FALSE;
    }
}

t_boolean est_permutation_valide(t_permutation ceci){
    if (est_p_permutation_initialise()) {
        int* tableau = (int*)malloc(taille_permutation * sizeof(int));
        for (int i = 0; i < taille_permutation; i++) {
            tableau[i] = 0;
        }
        for (int i = 0; i < taille_permutation; i++) {
            if (ceci[i] < 0 || ceci[i] >= taille_permutation) {
                free(tableau);
                return FALSE;
            } else {
                tableau[ceci[i]]++;
            }
        }
        for (int i = 0; i < taille_permutation; i++) {
            if (tableau[i] != 1) {
                free(tableau);
                return FALSE;
            }
        }
        free(tableau);
        return TRUE;
    } else {
        return FALSE;
    }
}

t_boolean est_inferieur_strict(t_permutation ceci, t_permutation cela){
    if (est_p_permutation_initialise()) {
        for (int i = 0; i < taille_permutation; i++) {
            if (ceci[i] >= cela[i]) {
                return FALSE;
            }
        }
        return TRUE;
    } else {
        return FALSE;
    }
}

t_boolean est_point_fixe_permutation(t_permutation ceci, int position){
    if (est_p_permutation_initialise() && est_indice_valide(position)) {
        return (ceci[position] == position);
    } else {
        return FALSE;
    }
}

int nb_point_fixe(t_permutation ceci){
    if (est_p_permutation_initialise()) {
        int nb = 0;
        for (int i = 0; i < taille_permutation; i++) {
            if (est_point_fixe_permutation(ceci, i)) {
                nb++;
            }
        }
        return nb;
    } else {
        return -1;
    }
}

t_boolean suivante_permutation(t_permutation ceci){
    if (est_p_permutation_initialise()) {
        int i = taille_permutation - 2;
        while (i >= 0 && ceci[i] > ceci[i + 1]) {
            i--;
        }
        if (i < 0) {
            return FALSE;
        } else {
            int j = taille_permutation - 1;
            while (ceci[i] > ceci[j]) {
                j--;
            }
            int temp = ceci[i];
            ceci[i] = ceci[j];
            ceci[j] = temp;
            int k = i + 1;
            int l = taille_permutation - 1;
            while (k < l) {
                temp = ceci[k];
                ceci[k] = ceci[l];
                ceci[l] = temp;
                k++;
                l--;
            }
            return TRUE;
        }
    } else {
        return FALSE;
    }
}

t_boolean copier_suivante_permutation(t_permutation ceci, t_permutation cela){
    if (est_p_permutation_initialise()) {
        copier_permutation(ceci, cela);
        return suivante_permutation(cela);
    } else {
        return FALSE;
    }
}

t_boolean code_point_fixe_permutation(t_permutation ceci, int point_fixe, t_permutation cela){
    if (est_p_permutation_initialise() && est_indice_valide(point_fixe)) {
        if (est_point_fixe_permutation(ceci, point_fixe)) {
            for (int i = 0; i < taille_permutation; i++) {
                cela[i] = ceci[i];
            }
            cela[point_fixe] = ceci[point_fixe + 1];
            cela[point_fixe + 1] = ceci[point_fixe];
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        return FALSE;
    }
}

t_boolean decode_point_fixe_permutation(t_permutation ceci, t_permutation cela, int* point_fixe){
    if (est_p_permutation_initialise()) {
        for (int i = 0; i < taille_permutation; i++) {
            cela[i] = ceci[i];
        }
        int i = 0;
        while (i < taille_permutation - 1 && cela[i] < cela[i + 1]) {
            i++;
        }
        if (i == taille_permutation - 1) {
            return FALSE;
        } else {
            *point_fixe = i;
            int temp = cela[i];
            cela[i] = cela[i + 1];
            cela[i + 1] = temp;
            return TRUE;
        }
    } else {
        return FALSE;
    }
}