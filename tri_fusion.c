#include<stdio.h>
#include<stdlib.h>

/* ------------------------------------------------------------------------------------------ */
/*  Fonctions permettant de fusionner deux sous tableaux non vides triés dans l'ordre         */
/*  croissant en un seul tableau trié par odre croissant. Les paramètres sont : un tableaux   */
/*  contenant les deux sous tableaux triés, l'indice de début du deuxième sous tableau (m),   */
/*  ainsi que l'indice de fin du deuxième sous tableau (n).                                   */
/* ------------------------------------------------------------------------------------------ */

void fusionner(int *tab, int m, int n){
  int *tab_temp = (int*) malloc((n+1)*sizeof(int));
  int i = 0;
  int j = m;
  int k = 0;

  while((i < m) && (j < n + 1)){
    if(tab[i] <= tab[j]){
      tab_temp[k] = tab[i];
      i++;
    }
    else{
      tab_temp[k] = tab[j];
      j++;
    }
    k++;
  }
  if(i >= m){
    while(j < n + 1){
      tab_temp[k] = tab[j];
      j++;
      k++;
    }
  }
  else{
    while(i < m){
      tab_temp[k] = tab[i];
      i++;
      k++;
    }
  }
  for(i = 0; i < n + 1; i++){
    tab[i] = tab_temp[i];
  }
  free(tab_temp);
}

/* ------------------------------------------------------------------------------------------ */
/*  Fonctions permettant de trier un tableau d'entier de manière récursive dans l'ordre       */
/*  croissant. Les paramètres sont : un tableaux, l'indice de début du tableau (d), et        */
/*  l'indice de fin du tableau (f).                                                           */
/* ------------------------------------------------------------------------------------------ */

void triFusion(int *tab, int d, int f){

  int m = (d+f)/2 + 1;

  if(d < f){
    triFusion(tab, d, m - 1);
    triFusion(tab, m, f);
    fusionner(tab + d, m - d, f - d);
  }
}
