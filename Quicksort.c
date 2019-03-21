#include<stdio.h>
#include<stdlib.h>

/* ---------------------------------------------------------------------------------------- */
/*    Fonctions permettant d'échanger deux valeurs d'un tableau. Les paramètres sont des    */
/*                  pointeurs sur chacune des deux valeurs du tableau.                      */
/* ---------------------------------------------------------------------------------------- */

void echanger(int *i, int *j){
  int temp = *i;
  *i = *j;
  *j = temp;
}

/* ---------------------------------------------------------------------------------------- */
/*    Fonctions permettant de partitionner un tableau d'entier en 3 parties :               */
/*      - un pivot q correspondant à un indice                                              */
/*      - une partie de l'indice p à q-1 ou toutes les valeurs sont inférieurs à tab[q]     */
/*      - une partie de l'indice q+1 à r ou toutes les valeurs sont supérieurs à tab[q]     */
/*                                                                                          */
/* p est l'indice du début du tableau à partionner et r l'indice de fin de ce même tableau  */
/* ---------------------------------------------------------------------------------------- */

int partitionner(int *tab, int p, int r){
  int pivot = p;
  int i = p;
  int j = r;

  while(i < j){
    while((tab[i] <= tab[pivot]) && (i < r)){
      i++;
    }
    while(tab[j] > tab[pivot]){
      j--;
    }
    if(i < j)
      echanger(tab + i, tab + j);
  }
  echanger(tab + pivot, tab +j);
  return j;
}

/* ---------------------------------------------------------------------------------------- */
/*   Fonctions permettant de trier un tableau de manière recursive. Les paramètres p et r   */
/*                  sont les indices de début et de fin du tableau t à trier                */
/* ---------------------------------------------------------------------------------------- */

void Quicksort(int *t, int p, int r){
  int pivot;
  printf("p:%d,q:%d\n",p,r );
  if(p < r){
    pivot = partitionner(t, p, r);    // Le pivot est trié, il reste à trier les sous tableaux t[p:q-1] et t[q+1:r]
    Quicksort(t, p, pivot - 1);
    Quicksort(t, pivot + 1, r);
  }
}
