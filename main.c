#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *valeurs;
    int taille;
} tableau;

tableau t;

int alea(int m)
{
    return rand() % (m + 1);
}

void remplir(int m)
{
    int i = 0;
    while (i < t.taille)
    {
        t.valeurs[i++] = alea(m);
    }
}

void bulle(int k)
{
    int i = 0;
    for (i = 0; i <= k; i++)
    {
        if (t.valeurs[i + 1] > t.valeurs[i])
        { // echange de t[i] et t[i+1]
            int tmp = t.valeurs[i + 1];
            t.valeurs[i + 1] = t.valeurs[i];
            t.valeurs[i] = tmp;
        }
    }
}

void trier()
{
    int i = 0;
    for (i = t.taille - 1; i >= 0; i--)
    {
        bulle(i);
    }
}

void affiche()
{
    int i;
    for (i = 0; i < t.taille; i++)
    {
        printf("%d\t", t.valeurs[i]);
    }
    printf("\n");
}

tableau t; // tableau d'entiers avec sa taille

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("usage : main <nb elems> <max val>\n");
        return 1;
    }

    t.taille = atoi(argv[1]); // lecture du 1er argument
    int m = atoi(argv[2]);    // lecture du 2eme argument

    t.valeurs = 0;                                     // initialisation du pointeur
    t.valeurs = (int *)malloc(t.taille * sizeof(int)); // allocation du tableau

    remplir(m); // remplissage aléatoire du tableau

    printf("tableau non trié :\n");
    affiche();

    trier();

    printf("tableau trié :\n");
    affiche();

    return 0;
}
