#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define MAX 2 // aqui precisa adequar para a quantidade que podera ter

// DECLARAÇÃO DAS STRUCTS

typedef struct {
	int qtd_Cadastro;
}Qtd_Cadastro;

typedef struct Disciplina {
	char nome_Disc [50];
	char prontuario[50];
	float Prova_Pratica, Projeto, Lista_Exercicio, Media;
};
typedef struct{
	int ativo;
	char prontuario[50];
	char nome[50];
	char data_nasc[50];
	char email_inst[50];
	struct Disciplina disc;
} cad_Alunos;

cad_Alunos Alunos[MAX];
Qtd_Cadastro Qtd_Cad;

// FIM DA DECLARAÇÃO DAS STRUCTS


// DECLARAÇÃO DAS FUNÇÕES

void salvar_em_Arquivos();
void ler_arquivo_Struct();
void ler_de_Arquivos();
void alunos_Aprovados();
void alunos_Reprovados();
void alunos_Inativos();
void remover_Aluno();
void alterar_Alunos();
void cadastrar_Alunos();
void listar_Aluno();
void listar_Alunos();
void sub_menu_Alunos();
void menu();

// FIM DA DECLARAÇÃO DAS FUNÇÕES

// FUNÇÕES DE ARQUIVOS

void salvar_em_Arquivos(cad_Alunos *Alunos, Qtd_Cadastro *Qtd_Cad){ // Pronta

	int len_Alunos = Qtd_Cad->qtd_Cadastro;
	//printf("%d", len_Alunos);
	FILE *arquivo;

	arquivo = fopen("CADASTRO ALUNOS.txt", "w");
	if (arquivo == NULL)
	{
		printf("\nNÃO FOI POSSÍVEL ABRIR E SALVAR OS DADOS NO ARQUIVO!");
		getchar();
		exit(0);
	}else
	{
		//fprintf(arquivo, "%d\n", Qtd_Cad->qtd_Cadastro);
		for(int i = 0; i < len_Alunos; i++)
		{
			// escreve cada elemento do vetor no arquivo
			fprintf(arquivo, "%d %s %s %s %s %s %.2f %.2f %.2f %.2f\n", Alunos[i].ativo, Alunos[i].prontuario, Alunos[i].nome, Alunos[i].data_nasc, Alunos[i].email_inst, Alunos[i].disc.nome_Disc, Alunos[i].disc.Prova_Pratica, Alunos[i].disc.Projeto, Alunos[i].disc.Lista_Exercicio, Alunos[i].disc.Media);
		}
		fclose(arquivo); // aborta o programa
		printf("\nARQUIVO GRAVADO COM SUCESSO!\n");
	}
	sleep(2);	
}

void ler_arquivo_Struct(cad_Alunos *Alunos, Qtd_Cadastro *Qtd_Cad){
	
	FILE *arquivo;
	arquivo = fopen("CADASTRO ALUNOS.txt", "r+");

	int quant =0;

	if (arquivo == NULL)
	{
		printf("\nNÃO FOI POSSÍVEL ABRIR O ARQUIVO E SALVAR OS DADOS NA STRUCT!");
		getchar();
		exit(0);
	}else
	{
		//fscanf(arquivo, "%d\n", &quant);
		while(fscanf(arquivo, "%d" "%s" "%s" "%s" "%s" "%s" "%f" "%f" "%f" "%f", &Alunos[quant].ativo, Alunos[quant].prontuario, Alunos[quant].nome, Alunos[quant].data_nasc, Alunos[quant].email_inst, Alunos[quant].disc.nome_Disc, &Alunos[quant].disc.Prova_Pratica, &Alunos[quant].disc.Projeto, &Alunos[quant].disc.Lista_Exercicio, &Alunos[quant].disc.Media)!= EOF){
			quant +=1;
		}
		fclose(arquivo);
	}	
}

// FIM DE ARQUIVOS


// FUNÇÕES RELATORIOS

void alunos_Aprovados(cad_Alunos *Alunos ) { // Pronto

	int rep=0;

	if(Alunos->ativo!=NULL) {

		system("cls");
		printf("\n\t---ALUNOS APROVADOS---\n");

		for(int i=0; i<MAX; i++) {

			if((Alunos[i].ativo==1)&&(Alunos[i].disc.Media>=7)) {

				printf("\n----------------------------------------------");
				printf("\n\tDisciplina: %s", Alunos[i].disc.nome_Disc);
				printf("\n\tProntuario: %s", Alunos[i].prontuario);
				printf("\n\tNome: %s", Alunos[i].nome);
				printf("\n\tData de Nascimento: %s", Alunos[i].data_nasc);
				printf("\n\tEmail Institucional: %s", Alunos[i].email_inst);
				printf("\n----------------------------------------------");
				printf("\n\n\tAs Notas Obitidas do Aluno %s ", Alunos[i].nome);
				printf("\n----------------------------------------------");
				printf("\n\tProva Pratica: %.2f", Alunos[i].disc.Prova_Pratica);
				printf("\n\tProjeto: %.2f", Alunos[i].disc.Projeto);
				printf("\n\tLista de Exercicios: %.2f", Alunos[i].disc.Lista_Exercicio);
				printf("\n----------------------------------------------");
				printf("\n\tA Media foi: %.2f", Alunos[i].disc.Media);
				printf("\n----------------------------------------------\n\n");

			} else {
				rep +=1;
			}
		}

		if (rep == MAX) {
			system("cls");
			printf("\n\t---NAO HA ALUNOS APROVADOS!---\n\n");
		}


	} else {
		system("cls");
		printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
	}

	system("pause");
}

void alunos_Reprovados(cad_Alunos *Alunos) { // Pronto

	int rep=0, i;

	if(Alunos->ativo!=NULL) {

		system("cls");
		printf("\n\t---ALUNOS REPROVADOS---\n");

		for(i=0; i<MAX; i++) {

			if((Alunos[i].ativo==1)&&(Alunos[i].disc.Media<7)) {

				printf("\n----------------------------------------------");
				printf("\n\tDisciplina: %s", Alunos[i].disc.nome_Disc);
				printf("\n\tProntuario: %s", Alunos[i].prontuario);
				printf("\n\tNome: %s", Alunos[i].nome);
				printf("\n\tData de Nascimento: %s", Alunos[i].data_nasc);
				printf("\n\tEmail Institucional: %s", Alunos[i].email_inst);
				printf("\n----------------------------------------------");
				printf("\n\n\tAs Notas Obitidas do Aluno %s ", Alunos[i].nome);
				printf("\n----------------------------------------------");
				printf("\n\tProva Pratica: %.2f", Alunos[i].disc.Prova_Pratica);
				printf("\n\tProjeto: %.2f", Alunos[i].disc.Projeto);
				printf("\n\tLista de Exercicios: %.2f", Alunos[i].disc.Lista_Exercicio);
				printf("\n----------------------------------------------");
				printf("\n\tA Media foi: %.2f", Alunos[i].disc.Media);
				printf("\n----------------------------------------------\n\n");

			} else {
				rep +=1;
			}
		}

		if (rep == MAX) {
			system("cls");
			printf("\n\t---NAO HA ALUNOS REPROVADOS!---\n\n");
		}


	} else {
		system("cls");
		printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
	}

	system("pause");
}

void alunos_Inativos(cad_Alunos *Alunos) { //Pronto


	int ina=0, i;
	if(Alunos->ativo!=NULL) {

		system("cls");
		printf("\n\t---LISTA DE ALUNOS INATIVOS/EXCLUIDOS---\n\n");
		for (i = 0; i < MAX; i++) {

			if(Alunos[i].ativo==2) {
				printf("\n----------------------------------------------");
				printf("\n\tDisciplina %s", Alunos[i].disc.nome_Disc);
				printf("\n\tProntuario: %s", Alunos[i].prontuario);
				printf("\n\tNome: %s", Alunos[i].nome);
				printf("\n\tData de Nascimento: %s", Alunos[i].data_nasc);
				printf("\n\tEmail Institucional: %s", Alunos[i].email_inst);
				printf("\n----------------------------------------------");
				printf("\n\n\tAs Notas Obitidas do Aluno %s ", Alunos[i].nome);
				printf("\n----------------------------------------------");
				printf("\n\tProva Pratica: %.2f", Alunos[i].disc.Prova_Pratica);
				printf("\n\tProjeto: %.2f", Alunos[i].disc.Projeto);
				printf("\n\tLista de Exercicios: %.2f", Alunos[i].disc.Lista_Exercicio);
				printf("\n----------------------------------------------");
				printf("\n\tA Media foi: %.2f", Alunos[i].disc.Media);
				printf("\n----------------------------------------------\n\n");
			} else {
				ina += 1;
			}

		}

		if (ina == MAX) {
			system("cls");
			printf("\n\t---NAO HA ALUNOS EXCLUIDOS/INATIVOS!---\n\n");
		}

	} else {
		system("cls");
		printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
	}
	system("pause");
}

// FIM DE RELATORIOS


// FUNÇÕES GERAIS

void remover_Aluno(cad_Alunos *Alunos) { // Pronto

	char pront[50];
	int pos, i;

	system("cls");
	if(Alunos->ativo!=NULL) {

		/*printf("\n\t---LISTA DE ALUNOS---\n\n");
		listar_Alunos(Alunos);*/

		printf("\nDigite o Prontuario do Aluno a ser Excluido: \n");
		gets(pront);

		for (i = 0; i < MAX; i++) {
			if (strcmp(pront, Alunos[i].prontuario)==0) {
				pos = i;
				break;
			} else {
				pos = -1;
			}
		}
		if (pos == -1) {
			system("cls");
			printf("\n\t---Aluno nao Encontrado!---\n");
		} else {
			/*
			ALUNO->ATIVO = 1 -- ALUNO ATIVO
			ALUNO->ATIVO = 2 -- ALUNO EXCLUIDO/INATIVO
			*/
			system("cls");
			Alunos[pos].ativo=2;
			printf("\n\t---Aluno Excluido com Suscesso!---\n");
		}
	} else {
		system("cls");
		printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
	}

	system("pause");
}

void alterar_Alunos(cad_Alunos *Alunos) { // Pronto

	char pront[50];
	int pos, i;
	float Soma;

	system("cls");
	if(Alunos->ativo!=NULL) {

		printf("\n\t---LISTA DE ALUNOS---\n\n");
		//listar_Alunos(Alunos);

		printf("\nDigite o Prontuario do Aluno a ser Atualizado:\n");
		gets(pront);

		for (i = 0; i < MAX; i++) {
			if (strcmp(pront, Alunos[i].prontuario)==0) {
				pos = i;
				break;
			} else {
				pos = -1;
			}
		}
		if (pos == -1) {
			system("cls");
			printf("\n\t---Aluno nao Encontrado ou Prontuario incorreto!---\n");
		} else {
			int op;
			system("cls");
			printf("\n\t---ESCOLHA O DADO A SER ATUALIZADO---\n\n");
			printf("\n\t1-Nome\n\t2-Data de Nascimento\n\t3-Email\n\t4-Nota Prova Pratica\n\t5-Nota Projeto\n\t6-Nota Lista de Exercicio\n\t7-Ativar Matricula do Aluno\n\t8-Desativar Matricula do Aluno\n");

			printf("\nDigite a Opcao Desejada!\n");
			scanf("%d", &op);
			setbuf(stdin,NULL);

			switch (op) {
				case 1:
					system("cls");
					printf("\nDigite o nome do Aluno a ser Alterado:\n");
					fgets(Alunos[pos].nome, sizeof(Alunos[pos].nome), stdin);
					setbuf(stdin,NULL);
					break;
				case 2:
					system("cls");
					printf("\nDigite a Data de Nascimento do Aluno a ser Alterado:\n");
					fgets(Alunos[pos].data_nasc, sizeof(Alunos[pos].data_nasc), stdin);
					setbuf(stdin,NULL);
					break;
				case 3:
					system("cls");
					printf("\nDigite o Email do Aluno a ser Alterado:\n");
					fgets(Alunos[pos].email_inst, sizeof(Alunos[pos].email_inst), stdin);
					setbuf(stdin,NULL);
					break;
				case 4:
					system("cls");
					printf("\nDigite a nota da Prova Pratica a ser Alterado:\n");
					scanf("%f", &Alunos[pos].disc.Prova_Pratica);
					setbuf(stdin,NULL);
					break;
				case 5:
					system("cls");
					printf("\nDigite a nota do Projeto a ser Alterado:\n");
					scanf("%f", &Alunos[pos].disc.Projeto);
					setbuf(stdin,NULL);
					break;
				case 6:
					system("cls");
					printf("\nDigite a nota da Lista de Exercicio a ser Alterado:\n");
					scanf("%f", &Alunos[pos].disc.Lista_Exercicio);
					setbuf(stdin,NULL);
					break;
				case 7:
					system("cls");
					Alunos[pos].ativo=1;
					printf("\nO Aluno %s foi reativado na instituicao!", Alunos[pos].nome);
					break;
				/*case 8:
					system("cls");
					Alunos[pos].ativo=2;
					printf("\nO Aluno %s foi desativado na instituicao!", Alunos[pos].nome);
					break;*/
				default:
					system("cls");
					printf("\n\t---!OPCAO INVALIDA!---\n");
					break;
			}

			Soma = Alunos[pos].disc.Prova_Pratica + Alunos[pos].disc.Projeto + Alunos[pos].disc.Lista_Exercicio;
			Alunos[pos].disc.Media = Soma/3;

			printf("\n\t---Aluno Alterado com Suscesso!---\n");
		}
	} else {
		system("cls");
		printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
	}

	system("pause");
}

void cadastrar_Alunos(cad_Alunos *Alunos, Qtd_Cadastro *Qtd_Cad) { // Pronto
	
	int op, i=0, j, pos=0;
	float Soma;
	char pront[50];

	for(int c; c < MAX; c++) // for usado para verificar se já ha cadastros no sistemas para não haver sobreposição
	{
		if(Alunos[c].ativo!=NULL){
			i++; // aqui na hr que for add outro aluno ele add por cima do que esta no mesmo indice tipo ind 1 para ind 1
		}
	}
	
	/*for(int c; c < MAX; c++) // for usado para verificar se já ha cadastros no sistemas para não haver sobreposição
	{
		if(Alunos[c].ativo!=NULL){
			i += 1; // aqui na hr que for add outro aluno ele add por cima do que esta no mesmo indice tipo ind 1 para ind 1
		}
	}*/
	
	do {

		system("cls");
		printf("Digite o Prontuario do Aluno:\n");
		gets(pront);
		setbuf(stdin,NULL);

		for(j = 0; j<MAX; j++) {
			if(strcmp(pront, Alunos[j].prontuario)==0) {
				printf("\n!Prontuario ja Cadastrado!\n");
				sleep(1);
				pos = -1;
				break;
			}
		}

		

		if(!pos) {

			//setbuf(stdin,NULL);
			strcpy(Alunos[i].prontuario, pront);
			strcpy(Alunos[i].disc.prontuario, pront);

			printf("Digite o Nome do Aluno:\n");
			fgets(Alunos[i].nome, sizeof(Alunos[i].nome), stdin);
			//scanf("%50[^\n]%*c", Alunos[i].nome);
			setbuf(stdin,NULL);
			printf("Digite a Data de Nascimeto do Aluno:\n");
			//scanf("%50[^\n]%*c", Alunos[i].data_nasc);
			fgets(Alunos[i].data_nasc, sizeof(Alunos[i].data_nasc), stdin);
			setbuf(stdin,NULL);
			printf("Digite o Email Institucional do Aluno:\n");
			//scanf("%50[^\n]%*c", Alunos[i].email_inst);
			fgets(Alunos[i].email_inst, sizeof(Alunos[i].email_inst), stdin);
			setbuf(stdin,NULL);

			//Notas

			system("cls");
			printf("\nPreenchendo as Notas do Aluno!\n");
			sleep(1);

			strcpy(Alunos[i].disc.nome_Disc, "AP2");

			system("cls");
			printf("Digite a Nota da Prova Pratica:\n");
			scanf("%f", &Alunos[i].disc.Prova_Pratica);
			setbuf(stdin,NULL);
			printf("Digite a Nota da Projeto:\n");
			setbuf(stdin,NULL);
			scanf("%f", &Alunos[i].disc.Projeto);
			setbuf(stdin,NULL);
			printf("Digite a Nota da Lista de Exercicios:\n");
			scanf("%f", &Alunos[i].disc.Lista_Exercicio);
			setbuf(stdin,NULL);
			Alunos[i].ativo=1; // 1 para ALUNO ATIVO e 2 para INATIVO/EXCLUIDO

			Soma = Alunos[i].disc.Prova_Pratica + Alunos[i].disc.Projeto + Alunos[i].disc.Lista_Exercicio;
			Alunos[i].disc.Media = Soma/3;
			
			i++;
			Qtd_Cad->qtd_Cadastro = i;

		}


		pos=0;

		system("cls");
		printf("\n\tDeseja Adicionar mais Alunos?");
		printf("\n\t1 - Continuar\n\t0 - Voltar\n");
		scanf("%d", &op);
		setbuf(stdin,NULL);
		// colocar um if para testar o final de adições de alunos basedo no MAX
		if (op == 1) {
			if (i >= MAX) {
				system("cls");
				printf("\nLimite de cadastros atingido!!\n");
				op = 0;
				sleep(1);
				break;
			}
		}

		if(op==0) {
			system("cls");
			printf("\nVOLTANDO AO MENU ALUNOS!!\n");
			sleep(1);
		}

	} while(op!=0);
	
}

void listar_Aluno(cad_Alunos *Alunos) { // Pronto

	char pront[50];
	int pos, i;

	system("cls");
	if(Alunos->ativo!=NULL) {

		printf("\nDigite o Prontuario do aluno a ser Pesquisado:\n");
		gets(pront);
		setbuf(stdin,NULL);

		for(i = 0; i<MAX; i++) {
			if(strcmp(pront, Alunos[i].prontuario)==0) {
				system("cls");
				printf("\n\t---Aluno encontrado!---\n");
				pos = i;
				sleep(1);
				break;
			} else {
				pos = -1;
			}
		}

		if(pos == -1) {
			system("cls");
			printf("\n\t---Aluno nao encontrado!---\n\n");
		} else {
			//system("cls");
			//printf("\nAperte ENTER para mostrar o aluno:\n\n");
			//getchar();

			system("cls");
			printf("\n\tRegistro do Aluno Encontrado:");
			printf("\n----------------------------------------------");
			printf("\n\tDisciplina: %s", Alunos[pos].disc.nome_Disc);
			printf("\n\tProntuario: %s", Alunos[pos].prontuario);
			printf("\n\tNome: %s", Alunos[pos].nome);
			printf("\n\tData de Nascimento: %s", Alunos[pos].data_nasc);
			printf("\n\tEmail Institucional: %s", Alunos[pos].email_inst);
			printf("\n----------------------------------------------");
			printf("\n\n\tAs Notas Obitidas do Aluno %s ", Alunos[pos].nome);
			printf("\n\n----------------------------------------------");
			printf("\n\tProva Pratica: %.2f", Alunos[pos].disc.Prova_Pratica);
			printf("\n\tProjeto: %.2f", Alunos[pos].disc.Projeto);
			printf("\n\tLista de Exercicios: %.2f", Alunos[pos].disc.Lista_Exercicio);
			printf("\n----------------------------------------------");
			printf("\n\tA Media foi: %.2f", Alunos[i].disc.Media);
			printf("\n----------------------------------------------\n\n");
		}
	} else {
		system("cls");
		printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
	}

	system("pause");
}

void listar_Alunos(cad_Alunos *Alunos) { //pronto

	system("cls");
	if(Alunos->ativo!=NULL) {

		printf("\n\t---LISTA DE ALUNOS---\n\n");
		for (int i = 0; i < MAX; i++) {
			if (Alunos[i].ativo==1)
			{

				printf("\n----------------------------------------------");
				printf("\n\tDisciplina: %s", Alunos[i].disc.nome_Disc);
				printf("\n\tProntuario: %s", Alunos[i].prontuario);
				printf("\n\tNome: %s", Alunos[i].nome);
				printf("\n\tData de Nascimento: %s", Alunos[i].data_nasc);
				printf("\n\tEmail Institucional: %s", Alunos[i].email_inst);
				printf("\n----------------------------------------------");
				printf("\n\n\tAs Notas Obitidas do Aluno %s ", Alunos[i].nome);
				printf("\n----------------------------------------------");
				printf("\n\tProva Pratica: %.2f", Alunos[i].disc.Prova_Pratica);
				printf("\n\tProjeto: %.2f", Alunos[i].disc.Projeto);
				printf("\n\tLista de Exercicios: %.2f", Alunos[i].disc.Lista_Exercicio);
				printf("\n----------------------------------------------");
				printf("\n\tA Media foi: %.2f", Alunos[i].disc.Media);
				printf("\n----------------------------------------------\n\n");

			}
		}
	} else {
		system("cls");
		printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
	}
	system("pause");
}

void sub_menu_Alunos() { //Pronto
	int op;

	do {
		system("cls");
		printf("Selecione uma Opcao!");
		printf("\n\t1-Listar Todos os Alunos");
		printf("\n\t2-Listar um Aluno");
		printf("\n\t3-Cadastar Aluno"); // nao pode ter dois alunos com o mesmo prontuario
		printf("\n\t4-Alterar Aluno");
		printf("\n\t5-Excluir Aluno"); // Excluir aluno / cancelar matricula
		printf("\n\t0-Sair\n\n");
		scanf("%d", &op);
		setbuf(stdin,NULL);

		switch (op) {
			case 1:
				listar_Alunos(Alunos);
				break;
			case 2:
				listar_Aluno(Alunos);
				break;
			case 3:
				cadastrar_Alunos(Alunos, &Qtd_Cad);
				break;
			case 4:
				alterar_Alunos(Alunos);
				break;
			case 5:
				remover_Aluno(Alunos);
				break;
			case 0:
				// Sai do Sub Menu Alunos
				system("cls");
				printf("\n\nSaindo do Menu Alunos!\n");
				sleep(1);
				break;
			default:
				system("cls");
				printf("\n\n!Opcao invalida!\n\n");
				sleep(1);
		}

	} while (op!=0);
}

void sub_menu_Relatorios() { // Pronto

	int op;

	do {
		system("cls");
		setbuf(stdin,NULL);
		printf("\n\t\tSelecione uma Opcao!\n");
		printf("\n\t1-Listar Todos os Alunos Aprovados:");
		printf("\n\t2-Listar Todos os Alunos Reprovados:");
		printf("\n\t3-Mostrar Todos os Alunos Excluidos/Inativos:");
		printf("\n\t0-Voltar:\n\n");
		scanf("%d", &op);
		setbuf(stdin,NULL);

		switch (op) {

			case 1:
				alunos_Aprovados(Alunos);
				break;
			case 2:
				alunos_Reprovados(Alunos);
				break;
			case 3:
				alunos_Inativos(Alunos);
				break;
			case 0:
				// Sai do Sub Menu Alunos
				system("cls");
				printf("\n\nSaindo do Menu Relatorios!\n");
				sleep(1);
				break;
			default:
				system("cls");
				printf("\n\n!Opcao invalida!\n\n");
				sleep(1);
		}

	} while (op!=0);
}

void menu() { //Pronto
	int op;

	ler_arquivo_Struct(Alunos, &Qtd_Cad);

	do {
		system("cls");
		printf("\tSelecione uma Opcao!");
		printf("\n\t1-Alunos");
		printf("\n\t2-Relatorios");
		printf("\n\t0-Sair\n\n");
		scanf("%d", &op);
		setbuf(stdin,NULL);

		switch (op) {
			case 1:
				sub_menu_Alunos();
				break;
			case 2:
				sub_menu_Relatorios();
				break;
			case 0:
				system("cls");
				salvar_em_Arquivos(Alunos, &Qtd_Cad);
				system("cls");
				printf("\nSAINDO!\n");
				sleep(1);
				exit(1);
				break;
			default:
				system("cls");
				printf("\n---Opcao invalida!---\n\n");
				sleep(1);
		}

	} while (op!=0);
}

int main() { //Pronto
	setlocale(LC_ALL, "Portuguese");

	
	menu();
	return 0;
}

// FIM DAS FUNÇÕES GERAIS