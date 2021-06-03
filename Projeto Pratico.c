#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

typedef struct{
    int pront;
    char nome[50];
    char data_nasc[50];
    char email_inst[50];
    float notas[4];
    int ativo;
}Alunos;
Alunos aluno[MAX];

void menu();
void cadastrar_Alunos();
void remover();
void reprovados();
void pesquisa();

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
            /*case 1:
                listar_Alunos();
                break;
            case 2:
                listar_Aluno();
                break;*/
            case 3:
                cadastrar_Alunos();
                break;
            /*case 4:
                alterar_Aluno();
                break;
            case 5:
                excluir_Aluno();
                break;*/
            case 0:
                // Sai do Sub Menu Alunos
                printf("\nSaindo do Menu Alunos!\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
        }
    } while (op!=0);
}

void cadastrar_Alunos(){
    system("cls");
    int pront;
    char nome[50];
    char data_nasc[50];
    char email_inst[50];
    float notas[4];
    int op;
    do
    {
        printf("\nDigite o Prontuario do Aluno: \n");
        scanf("%d%*c", &pront);
        printf("\nDigite o Nome do Aluno: \n");
        fgets(nome,sizeof(nome),stdin);
        printf("\nDigite a Data de Nascimeto do Aluno: \n");
        fgets(data_nasc,sizeof(data_nasc),stdin);
        printf("\nDigite o Email Institucional do Aluno: \n");
        fgets(email_inst,sizeof(email_inst),stdin);

        for(int p = 0; p < MAX; p++){
            if(aluno[p].ativo==1){
                aluno[p].pront = pront;
                strcpy(aluno[p].nome,nome);
                strcpy(aluno[p].data_nasc,data_nasc);
                strcpy(aluno[p].email_inst,email_inst);
                break;
            }
        }

        //Notas

        printf("\nPreenchendo as Notas do Aluno!\n");
        printf("\nINFORME PRIMEIRO O PRONTUARIO DO MESMO!!\n");
        system("pause");

        printf("\nDigite o Prontuario do Aluno: \n");
        scanf("%f%*c", &notas[0]);
        printf("\nDigite a Nota da Prova Pratica: \n");
        scanf("%f%*c", &notas[1]);
        printf("\nDigite a Nota da Projeto: \n");
        scanf("%f%*c", &notas[2]);
        printf("\nDigite a Nota da Lista de Exercicios: \n");
        scanf("%f%*c", &notas[3]);

        for(int i=0;i<MAX;i++){
                for(int n=0;n<4;n++){
                    if(aluno[i].ativo==1){
                        aluno[i].notas[n] = notas[n];
                        aluno[i].notas[n] = notas[n];
                        aluno[i].notas[n] = notas[n];
                        aluno[i].notas[n] = notas[n];
                        break;
                    }
                }
        }
        printf("\n\t1 - Continuar\n\t0 - Sair\n");
        scanf("%d", &op);
        if(op==0){
            printf("\nSAINDO!!\n");
        }
    }while(op!=0);
}
