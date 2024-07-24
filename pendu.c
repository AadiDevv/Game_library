#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pendu.h"
#define POINT_DE_VIE 10

void pendu()
{
    printf("\t\n\n------ LE PENDU ------\n\n");
    // Variables
    char mot_secret[] = "DETERMINATION";
    int taille_ms = strlen(mot_secret), rejouer;
    char saisie_ut[taille_ms + 1];
    char mot_trouver[taille_ms + 1];
    int pv, lt_trv;

    // Instructions
    printf("Instructions => Le mot ne comporte pas d'espace, et est en MAJUSCULE\n");

    // Boucle de jeu
    do
    {
        // Initialisation
        for (int i = 0; i < taille_ms; i++)
            mot_trouver[i] = '-';
        mot_trouver[taille_ms] = '\0';
        pv = POINT_DE_VIE;

        printf("Trouver le mot %s\n", mot_trouver);

        // Début du jeu
        do
        {
            // Saisie utilisateur
            printf("\nProposez une lettre ou un mot > ");
            fgets(saisie_ut, sizeof(saisie_ut), stdin);
            saisie_ut[strcspn(saisie_ut, "\n")] = '\0';  // Retirer le \n

            // Nombre de lettres trouvées
            lt_trv = 0;

            // Taille de la saisie
            int taille_saisie = strlen(saisie_ut);

            // Si une lettre est saisie
            if (taille_saisie == 1)
            {
                char saisie_lettre = saisie_ut[0];
                for (int i = 0; i < taille_ms; i++)
                {
                    if (saisie_lettre == mot_secret[i])
                    {
                        mot_trouver[i] = saisie_lettre;
                        lt_trv++;
                    }
                }

                if (strcmp(mot_secret, mot_trouver) == 0)
                {
                    printf("%s | Bravo ! Vous avez trouve le mot\n", mot_secret);
                    break;
                }

                if (lt_trv != 0)
                {
                    printf("%s | Oui! La lettre %c est presente | pv : %d\n", mot_trouver, saisie_lettre, pv);
                }
                else
                {
                    pv--;
                    printf("%s | Dommage ! La lettre %c n'est pas presente | pv : %d\n", mot_trouver, saisie_lettre, pv);
                }
            }

            // Si un mot est saisi
            if (taille_saisie > 1)
            {
                if (strcmp(saisie_ut, mot_secret) == 0)
                {
                    printf("%s | Bravo ! Le mot a ete trouve | pv : %d\n", mot_secret, pv);
                    break;
                }
                else
                {
                    pv--;
                    printf("Dommage %s n'est pas le mot | pv : %d\n", saisie_ut, pv);
                }
            }

        } while (pv != 0);

        if (pv == 0)
        {
            printf("pv %d | Vous avez perdu!\n", pv);
        }

        do
        {
            printf("\nRejouer ? Oui(1) Non(2) ");
            scanf("%d", &rejouer);
            while (getchar() != '\n'); // Vider le buffer d'entrée
            if (rejouer != 1 && rejouer != 2)
                printf("Je n'ai pas compris votre saisie\n");
        } while (rejouer != 1 && rejouer != 2);

    } while (rejouer == 1);

    printf("A bientôt...");
}
