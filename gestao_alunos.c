#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestao_alunos.h"

void inicializarTurma(turma *t) {
    t->alunos = (aluno *)malloc(10 * sizeof(aluno));
    t->qtdAlunos = 0;
    t->capacidade = 10;
}

void exibirMenu() {
    printf(" 1. Inserir aluno;\n");
    printf(" 4. Listar alunos;\n");
    printf(" 6. Remover aluno;\n");
    printf(" 7. Procurar aluno;\n");
    printf(" 8. Tamanho da turma;\n");
    printf("-1. Sair.\n\n");
    printf("Escolha uma opção: ");
}

void inserirAluno(turma *t) {
    if (t->qtdAlunos == t->capacidade) {
        t->capacidade += 10;
        t->alunos = realloc(t->alunos, t->capacidade * sizeof(aluno));

        if (t->alunos == NULL) {
            printf("\nERRO ao realocar memória.\n");
            exit(EXIT_FAILURE);
        }
    }

    aluno novoAluno;

    printf("\nMatrícula: ");
    scanf("%d", &novoAluno.matricula);

    for (int i = 0; i < t->qtdAlunos; i++) {
        if (t->alunos[i].matricula == novoAluno.matricula) {
            printf("\nERRO: Matrícula já existente.\n\n");
            return;
        }
    }

    printf("Nome: ");
    scanf("%s", &novoAluno.nome);

    printf("Código da Turma: ");
    scanf("%d", &novoAluno.codTurma);

    printf("Notas em 7 disciplinas:\n");
    for (int i = 0; i < 7; i++) {
        printf("\tDisciplina %d: ", i + 1);
        scanf("%f", &novoAluno.notas[i]);
        while (novoAluno.notas[i] < 0 || novoAluno.notas[i] > 10) {
            printf("Nota inválida, insira novamente.\n");
            printf("\tDisciplina %d: ", i + 1);
            scanf("%f", &novoAluno.notas[i]);
        }
    }

    printf("Faltas em 7 disciplinas:\n");
    for (int i = 0; i < 7; i++) {
        printf("\tDisciplina %d: ", i + 1);
        scanf("%d", &novoAluno.faltas[i]);
        while (novoAluno.faltas[i] < 0) {
            printf("Quantidade de faltas inválida, insira novamente.\n");
            printf("\tDisciplina %d: ", i + 1);
            scanf("%d", &novoAluno.faltas[i]);
        }
    }

    t->alunos[t->qtdAlunos++] = novoAluno;

    printf("\nAluno inserido com sucesso!\n\n");
}

void listarAlunos(turma *t) {
    if (t->qtdAlunos == 0) {
        printf("\nNenhum aluno cadastrado.\n\n");
        return;
    }

    printf("\nLista de Alunos:\n\n");

    for (int i = 0; i < t->qtdAlunos; i++) {
        printf("-----------ALUNO(A) %d-----------\n", (i + 1));
        printf("Matrícula: %d\n", t->alunos[i].matricula);
        printf("Nome: %s\n", t->alunos[i].nome);
        printf("Código da turma: %d\n", t->alunos[i].codTurma);

        printf("Notas em 7 disciplinas:\n");
        for (int j = 0; j < 7; j++) {
            printf("\tDisciplina %d: %.2f\n", j + 1, t->alunos[i].notas[j]);
        }

        printf("Faltas em 7 disciplinas:\n");
        for (int j = 0; j < 7; j++) {
            printf("\tDisciplina %d: %d\n", j + 1, t->alunos[i].faltas[j]);
        }

        printf("\n\n");
    }
}


void removerAluno(turma *t) {
    int matriculaRemover;
    
    printf("\nDigite a matrícula do aluno a ser removido: ");
    scanf("%d", &matriculaRemover);

    int posicaoRemover = -1;
    
    for (int i = 0; i < t->qtdAlunos; i++) {
        if (t->alunos[i].matricula == matriculaRemover) {
            posicaoRemover = i;
            break;
        }
    }

    if (posicaoRemover == -1) {
        printf("\nAluno com matrícula %d não encontrado.\n\n", matriculaRemover);
        return;
    }

    for (int i = posicaoRemover; i < t->qtdAlunos - 1; i++) {
        t->alunos[i] = t->alunos[i + 1];
    }

    t->qtdAlunos--;

    printf("\nAluno removido com sucesso!\n\n");
}

void procurarAluno(turma *t) {
    int matriculaProcurar;
    
    printf("\nDigite a matrícula do aluno a ser procurado: ");
    scanf("%d", &matriculaProcurar);

    int posicaoEncontrar = -1;

    for (int i = 0; i < t->qtdAlunos; i++) {
        if (t->alunos[i].matricula == matriculaProcurar) {
            posicaoEncontrar = i;
            break;
        }
    }

    if (posicaoEncontrar != -1) {
        printf("\n----------ALUNO ENCONTRADO----------\n");
        printf("Matrícula: %d\n", t->alunos[posicaoEncontrar].matricula);
        printf("Nome: %s\n", t->alunos[posicaoEncontrar].nome);
        printf("Código da Turma: %d\n", t->alunos[posicaoEncontrar].codTurma);

        printf("Notas em 7 disciplinas:\n");
        for (int j = 0; j < 7; j++) {
            printf("\tDisciplina %d: %.2f\n", j + 1, t->alunos[posicaoEncontrar].notas[j]);
        }

        printf("Faltas em 7 disciplinas:\n");
        for (int j = 0; j < 7; j++) {
            printf("\tDisciplina %d: %d\n", j + 1, t->alunos[posicaoEncontrar].faltas[j]);
        }
        printf("\n");
    } else {
        printf("\nAluno com matrícula %d não encontrado.\n\n", matriculaProcurar);
    }
}

int tamanhoTurma(turma *t) {
    return t->qtdAlunos;
}

void liberarMemoria(turma *t) {
    free(t->alunos);
}
