#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

typedef struct{
    int pront;
    char nome[50];
    char data_nasc[50];
    char email_inst[50];
    float notas[3];
    int ativo;
}Alunos;
Alunos aluno[MAX];

void menu();
void cadastrar_Alunos();
void remover_Aluno();
void reprovados();
void pesquisa();
void listar_Alunos();

int main(){
    menu();
    return 0;
}

void menu(){ //pronto
    int op;

    do
    {
        system("cls");
        printf("Selecione uma Opcao!");
        printf("\n\t1-Alunos");
        printf("\n\t2-Relatorios");
        printf("\n\t0-Sair\n\n");
        scanf("%d", &op);
        getchar();

        switch (op){
            case 1:
                sub_menu_Alunos();
                break;
            /*case 2:
                sub_menu_Relatorios();
                break;*/
            case 0:
                printf("\nSAINDO!\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
        }
        getchar();
    } while (op!=0);
}

void sub_menu_Alunos(){
    int op;
    do
    {
        system("cls");
        printf("Selecione uma Opcao!");
        printf("\n\t1-Listar Todos os Alunos");
        printf("\n\t2-Listar um Aluno");
        printf("\n\t3-Cadastar Aluno"); // nao pode ter dois alunos com o mesmo prontuario
        printf("\n\t4-Alterar Aluno");
        printf("\n\t5-Excluir Aluno"); // Excluir aluno / cancelar matricula
        printf("\n\t0-Sair\n\n");
        scanf("%d", &op);
        getchar();

        switch (op){
            case 1:
                listar_Alunos();
                break;
            /*case 2:
                listar_Aluno();
                break;*/
            case 3:
                cadastrar_Alunos();
                break;
            /*case 4:
                alterar_Aluno();
                break;*/
            case 5:
                remover_Aluno();
                break;
            case 0:
                // Sai do Sub Menu Alunos
                printf("\nSaindo do Menu Alunos!\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
        }
        getchar();
    } while (op!=0);
}

void cadastrar_Alunos(){
    
    int pront;
    char nome[50];
    char data_nasc[50];
    char email_inst[50];
    float notas[3];
    int op;
    do
    {
        system("cls");
        printf("\nDigite o Prontuario do Aluno: \n");
        scanf("%d%*c", &pront);
        printf("\nDigite o Nome do Aluno: \n");
        fgets(nome,sizeof(nome),stdin);
        printf("\nDigite a Data de Nascimeto do Aluno: \n");
        fgets(data_nasc,sizeof(data_nasc),stdin);
        printf("\nDigite o Email Institucional do Aluno: \n");
        fgets(email_inst,sizeof(email_inst),stdin);

        //Notas

        /*printf("\nPreenchendo as Notas do Aluno!\n");
        printf("\nINFORME PRIMEIRO O PRONTUARIO DO MESMO!!\n");
        system("pause");

        //printf("\nDigite o Prontuario do Aluno: \n");
        //scanf("%f%*c", &notas[0]);*/
        printf("\nDigite a Nota da Prova Pratica: \n");
        scanf("%f", &notas[0]);
        printf("\nDigite a Nota da Projeto: \n");
        scanf("%f", &notas[1]);
        printf("\nDigite a Nota da Lista de Exercicios: \n");
        scanf("%f", &notas[2]);

        // armazenando na struct

        for(int i=0; i<MAX; i++)
        {
            if(aluno[i].ativo==0)
            {
                aluno[i].pront = pront;
                strcpy(aluno[i].nome,nome);
                strcpy(aluno[i].data_nasc,data_nasc);
                strcpy(aluno[i].email_inst,email_inst);
                //aluno[i].notas[0] = notas[0];                    
                aluno[i].notas[0] = notas[0];
                aluno[i].notas[1] = notas[1];
                aluno[i].notas[2] = notas[2];
                aluno[i].ativo=1;
                break;
            }
        }
        printf("\n\t1 - Continuar\n\t0 - Sair\n");
        scanf("%d", &op);
        if(op==0){
            printf("\nSAINDO!!\n");
        }
    }while(op!=0);
    getchar();
}

void listar_Alunos(){

    system("cls");
    printf("\nLISTA DE ALUNOS\n");
    
    for (int i = 0; i < MAX; i++)
    {
        if (aluno[i].ativo==1)
        {
            printf("-----------------\n");
            printf("Prontuario: %d\n",aluno[i].pront);
            printf("Nome: %s",aluno[i].nome);
            printf("Data de Nascimento: %s",aluno[i].data_nasc);
            printf("Email Institucional: %s\n",aluno[i].email_inst);
            printf("-----------------\n");
            printf("As Notas do Aluno foram:");
            printf("\n-----------------\n");
            printf("Prova Pratica: %0.2f\n", aluno[i].notas[0]);
            printf("Projeto: %0.2f\n", aluno[i].notas[1]);
            printf("Lista de Exercicios: %0.2f\n", aluno[i].notas[2]);
            printf("-----------------\n");
        }
        
    }
    system("pause");
}

void listar_Aluno(){

}

void remover_Aluno(){
    int pront;
    listar_Alunos();
    printf("\nDigite o Prontuario do aluno a ser excluido: \n");
    scanf("%d%*c", &pront);
    for (int i = 0; i < MAX; i++)
    {
        if (aluno[i].pront == pront)
        {
            aluno[pront].ativo=0;
        }
        else
        printf("\nAluno nao encontrado!!\n");
    }
    printf("\nAluno Excluido com Suscesso\n");
    getchar();
}