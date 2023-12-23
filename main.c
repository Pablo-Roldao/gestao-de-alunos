#include <stdio.h>
#include "gestao_alunos.h"

int main() {
    turma minhaTurma;
    inicializarTurma(&minhaTurma);

    printf("---------SISTEMA DE GESTÃO DE ALUNOS---------\n\n");

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirAluno(&minhaTurma);
                break;
            case 4:
                listarAlunos(&minhaTurma);
                break;
            case 6:
                removerAluno(&minhaTurma);
                break;
            case 7:
                procurarAluno(&minhaTurma);
                break;
            case 8:
                printf("\nTamanho da turma: %d\n\n", tamanhoTurma(&minhaTurma));
                break;
            case -1:
                printf("\nEncerrando o sistema.\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n\n");
        }
    } while (opcao != -1);

    liberarMemoria(&minhaTurma);

    return 0;
}
