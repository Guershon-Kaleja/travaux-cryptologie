#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char message[200];
    char mat[20][20];
    int i, j, k = 0, lignes, colonnes;

    printf("=== Chiffrement par transposition ===\n");
    printf("Entrez le message à chiffrer : ");
    fgets(message, sizeof(message), stdin);

    int len = strlen(message);
    if (message[len - 1] == '\n')
        message[len - 1] = '\0';

    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] == ' ')
            message[i] = '@';
    }

    colonnes = (int) sqrt(strlen(message)); 
    if (colonnes == 0) colonnes = 1;       
    lignes = strlen(message) / colonnes;
    if (strlen(message) % colonnes != 0)
        lignes++;

    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            if (k < strlen(message))
                mat[i][j] = message[k++];
            else
                mat[i][j] = '#'; 
        }
    }

    printf("\nTexte chiffré : ");
    for (j = 0; j < colonnes; j++) {
        for (i = 0; i < lignes; i++) {
            printf("%c", mat[i][j]);
        }
    }

    printf("\n");
    return 0;
}
