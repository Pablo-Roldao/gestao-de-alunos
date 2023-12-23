#ifndef GESTAO_ALUNOS_H
#define GESTAO_ALUNOS_H

typedef struct {
    int matricula;
    float notas[7];
    char nome[50];
    int codTurma;
    int faltas[7];
} aluno;

typedef struct {
    aluno *alunos;
    int qtdAlunos;
    int capacidade;
} turma;

void inicializarTurma(turma *t);
void exibirMenu();
void inserirAluno(turma *t);
void listarAlunos(turma *t);
void removerAluno(turma *t);
void procurarAluno(turma *t);
int tamanhoTurma(turma *t);
void liberarMemoria(turma *t);

#endif
