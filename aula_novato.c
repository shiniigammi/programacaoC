#include <stdio.h>
#include <stdlib.h>

void solucionadorDeProblemas() {
    char resposta;

    printf("\n===============================\n");
    printf("  SOLUCIONADOR DE PROBLEMAS\n");
    printf("===============================\n");

    printf("\nA bagaça funciona? (s/n): ");
    scanf(" %c", &resposta);

    if (resposta == 's' || resposta == 'S') {
        printf("\n>>> Nem mexa.\n");
        printf(">>> SEM PROBLEMAS.\n");
    } else {
        printf("\nVoce que fodeu com o treco? (s/n): ");
        scanf(" %c", &resposta);

        if (resposta == 's' || resposta == 'S') {
            printf("\n>>> Seu imbecil!\n");
            printf("Alguem sabe que foi voce? (s/n): ");
            scanf(" %c", &resposta);

            if (resposta == 's' || resposta == 'S') {
                printf("\n>>> SE FODEU!\n");
                printf("Da pra jogar a culpa em alguem? (s/n): ");
                scanf(" %c", &resposta);

                if (resposta == 's' || resposta == 'S') {
                    printf("\n>>> SEM PROBLEMAS.\n");
                } else {
                    printf("\n>>> SE FODEU MESMO.\n");
                }
            } else {
                printf("\n>>> ESCONDA.\n");
                printf(">>> SEM PROBLEMAS.\n");
            }
        } else {
            printf("\nAlguem pode te culpar? (s/n): ");
            scanf(" %c", &resposta);

            if (resposta == 's' || resposta == 'S') {
                printf("\n>>> SE FODEU!\n");
                printf("Da pra jogar a culpa em alguem? (s/n): ");
                scanf(" %c", &resposta);

                if (resposta == 's' || resposta == 'S') {
                    printf("\n>>> SEM PROBLEMAS.\n");
                } else {
                    printf("\n>>> SE FODEU MESMO.\n");
                }
            } else {
                printf("\n>>> ENTAO FODA-SE!\n");
                printf(">>> SEM PROBLEMAS.\n");
            }
        }
    }

    printf("\n===============================\n");
}

int main() {
    int opcao;

    do {
        printf("\n===============================\n");
        printf("        MENU PRINCIPAL\n");
        printf("===============================\n");
        printf("1 - Rodar solucionador de problemas\n");
        printf("0 - Sair\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                solucionadorDeProblemas();
                break;
            case 0:
                printf("\nSaindo... Valeu!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}