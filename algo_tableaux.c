#include<stdio.h>
#include<stdlib.h>

/* ---------------------------------------------------------------------------------------- */
/* Fonctions permettant d'afficher de manière récursive dans l'ordre des indices croissants */
/*      un tableau. Le parametre tab est un tableau d'entier, n est la taille du tableau    */
/* ---------------------------------------------------------------------------------------- */

void affiche(int* tab, int n){
  if(n != 0){
    printf("%d\t", tab[0]);
    affiche(tab + 1, n - 1);
  }
}

/* ---------------------------------------------------------------------------------------- */
/* Fonctions permettant de rechercher de manière récursive l'élément val dans le tableau    */
/*  d'entier tab. Cette fonction retourne l'indice de l'élément si celui-ci est dans le     */
/*                                  tableau, -1 sinon                                       */
/* ---------------------------------------------------------------------------------------- */

int recherche(int* tab, int n, int val){
  if(n != 0){
    if(tab[n - 1] == val){
      return n - 1;
    }
    if(tab[n - 1] < val){
      return -1;
    }
    return recherche(tab, n - 1, val);
  }
  return -1;
}

/* ---------------------------------------------------------------------------------------- */
/*    Fonctions permettant d'afficher de manière récursive (utilisant la dichotomie)        */
/*                    dans l'ordre des indices croissants un tableau.                       */
/*          Le parametre tab est un tableau d'entier, n est la taille du tableau            */
/* ---------------------------------------------------------------------------------------- */

int rechercheDico(int *tab, int val, int d, int f){

  printf("d:%d   f:%d\n", d, f);

  int i = (f+d)/2;

  if(d > f)
    return -1;

  if(val == tab[i])
    return i;
  if(val > tab[i])
    return rechercheDico(tab, val, i + 1, f);

  return rechercheDico(tab, val, d, i - 1);

}
