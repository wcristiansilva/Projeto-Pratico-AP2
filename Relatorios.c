/* MODULO DE RELATORIOS */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Projeto_Pratico.c"


/*
void alunos_Reprovados(){
    for(int i=0; i<10; i++) {
        if(func[i].idade<=30) {
            printf(" \n O nome do funcionário é: ");
            printf(" \n A idade do funcionário é: ");
            printf(" \n O salário do funcionário é: ");
            printf(" \n ------------------------------------------------------------------------");
            } else {
                posicao = -1;
            }
    }
    
    if(posicao = -1){
        printf("\n Não há registros com esta configuração!");
    }
}
*/
void alunos_Aprovados(){

    float Media;
    
    printf("\t---ALUNOS APROVADOS---\n");
    for(int i=0; i<MAX; i++) {

        Media = Alunos[i].disc.Prova_Pratica + Alunos[i].disc.Projeto + Alunos[i].disc.Lista_Exercicio;
        Media = Media/3;

        if(Alunos[i].ativo==1){
            if(Media>=7.0) {
                //printf("\t---ALUNOS APROVADOS---\n");
                printf("\n---------------------------");
                printf("\nProntuario: %s", Alunos[i].prontuario);
                printf("\nNome: %s", Alunos[i].nome);
                printf("\nData de Nascimento: %s", Alunos[i].data_nasc);
                printf("\nEmail Institucional: %s", Alunos[i].email_inst);
                printf("\n---------------------------");
                printf("\nAs Notas do Aluno %s foram:", Alunos[i].nome);
                printf("\n---------------------------");
                printf("\nProva Pratica: %.2f", Alunos[i].disc.Prova_Pratica);
                printf("\nProjeto: %.2f", Alunos[i].disc.Projeto);
                printf("\nLista de Exercicios: %.2f", Alunos[i].disc.Lista_Exercicio);
                printf("\nA sua Media foi %.2f", Media);
                printf("\n---------------------------\n\n");
            } else {
                posicao = -1;
            }
        }
    }
 
    if(posicao = -1){
        printf("\n Não há registros com esta configuração!");
    }
}
/*
void alunos_Desativados(){}
*/