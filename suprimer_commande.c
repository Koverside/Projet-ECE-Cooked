#include "Header.h"


void supprimer_commande(Command *a_detruire) {

    // Mettre à jour les pointeurs next et previous
    if ((a_detruire->previous != NULL)&&(a_detruire->next == NULL)) {       //DERNIER
        a_detruire->previous->next = NULL;
        file_commande.fin = a_detruire->previous;
    }if((a_detruire->next != NULL)&&(a_detruire->previous == NULL)){        //PREMIER
        a_detruire->next->previous = NULL;
        file_commande.debut = a_detruire->next;
    }if((a_detruire->next != NULL)&&(a_detruire->previous != NULL)) {       //MILIEU
        a_detruire->next->previous = a_detruire->previous;
        a_detruire->previous->next = a_detruire->next;
    }if((a_detruire->next == NULL)&&(a_detruire->previous == NULL)){        //SEUL
        file_commande.debut = NULL;
        file_commande.fin = NULL;
    }
    // Libérer la mémoire allouée pour l'élément à supprimer
    free(a_detruire);
}

