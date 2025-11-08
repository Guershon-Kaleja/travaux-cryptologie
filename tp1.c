#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char message[200], chiffre[200], dechiffre[200];
    int i, j, k, len, lignes, colonnes;

    printf("=== Chiffrement par Transposition ===\n\n");

    printf("Entrez le message: ");
    fgets(message, sizeof(message), stdin);
    len = strlen(message);
    if (message[len-1] == '\n') message[len-1] = '\0';
    len = strlen(message);

    colonnes = (int) sqrt(len);
    if (colonnes == 0) colonnes = 1;
    lignes = len / colonnes;
    if (len % colonnes != 0) lignes++;

    k = 0;
    for (j = 0; j < colonnes; j++)
        for (i = 0; i < lignes; i++)
            if (i*colonnes+j < len)
                chiffre[k++] = message[i*colonnes+j];
    chiffre[k] = '\0';

    printf("\nMessage chiffre: %s\n", chiffre);

    k = 0;
    for (i = 0; i < lignes; i++)
        for (j = 0; j < colonnes; j++)
            if (i*colonnes+j < len)
                dechiffre[i*colonnes+j] = chiffre[k++];
    dechiffre[len] = '\0';

    printf("Message dechiffre: %s\n", dechiffre);

    return 0;
}
