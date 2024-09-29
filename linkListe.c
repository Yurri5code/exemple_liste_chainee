#include <stdio.h>
#include <stdlib.h>

// Définition de la structure pour un élément de la liste
typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

// Définition de la structure de contrôle pour la liste
typedef struct {
    Element* tete;
} Liste;

// Fonction pour initialiser une nouvelle liste
Liste* initialiser() {
    Liste* liste = (Liste*)malloc(sizeof(Liste));
    liste->tete = NULL;
    return liste;
}

// Fonction pour ajouter un élément au début de la liste
void ajouterDebut(Liste* liste, int valeur) {
    Element* nouvelElement = (Element*)malloc(sizeof(Element));
    nouvelElement->valeur = valeur;
    nouvelElement->suivant = liste->tete;
    liste->tete = nouvelElement;
}

// Fonction pour afficher les éléments de la liste
void afficherListe(Liste* liste) {
    Element* actuel = liste->tete;
    while (actuel != NULL) {
        printf("%d -> ", actuel->valeur);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

// Fonction pour libérer la mémoire allouée à la liste
void libererListe(Liste* liste) {
    Element* actuel = liste->tete;
    Element* suivant;
    while (actuel != NULL) {
        suivant = actuel->suivant;
        free(actuel);
        actuel = suivant;
    }
    free(liste);
}

int main() {
    Liste* maListe = initialiser();
    ajouterDebut(maListe, 10);
    ajouterDebut(maListe, 20);
    ajouterDebut(maListe, 30);

    afficherListe(maListe);

    libererListe(maListe);
    return 0;
}
