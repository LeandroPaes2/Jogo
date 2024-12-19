#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define TF 20


struct TpElemento
{
	char simbolo, vivo;
	int x, y, cor, pontos;
};

struct TpJogador
{
	char Nome[20];
	int pontuacao;
};

void moldura(int CI, int LI, int CF, int LF, int CorTxt, int CorFundo)
{
	int i;
	textcolor(CorTxt);
	textbackground(CorFundo);
	
	gotoxy(CI,LI); printf("%c", 201);
	gotoxy(CI,LF); printf("%c", 200);
	gotoxy(CF,LI); printf("%c", 187);
	gotoxy(CF,LF); printf("%c", 188);
	
	for(i = CI+1; i < CF; i++)
	{
		gotoxy(i, LI); printf("%c",205);
		gotoxy(i, LF); printf("%c", 205);
	}
	for(i = LI+1; i < LF; i++)
	{
		gotoxy(CI, i); printf("%c",186);
		gotoxy(CF, i); printf("%c", 186);
	}
	
	textcolor(7);
	textbackground(0);
}

void Ele(void)
{
	textcolor(1);
	gotoxy(5,20);
	printf("%c",3);
	
	textcolor(2);
	gotoxy(7,15);
	printf("%c",4);
	
	textcolor(3);
	gotoxy(10,22);
	printf("%c",5);
	
	textcolor(4);
	gotoxy(21,10);
	printf("%c",5);
	
	textcolor(5);
	gotoxy(4,9);
	printf("%c",6);
	
	textcolor(6);
	gotoxy(15,16);
	printf("%c",4);
	
	textcolor(7);
	gotoxy(11,7);
	printf("%c",3);
	
	textcolor(8);
	gotoxy(17,19);
	printf("%c",5);
	
	
	textcolor(1);
	gotoxy(70,20);
	printf("%c",3);
	
	textcolor(2);
	gotoxy(74,15);
	printf("%c",4);
	
	textcolor(3);
	gotoxy(65,22);
	printf("%c",4);
	
	textcolor(4);
	gotoxy(60,10);
	printf("%c",6);
	
	textcolor(5);
	gotoxy(64,9);
	printf("%c",3);
	
	textcolor(6);
	gotoxy(59,16);
	printf("%c",6);
	
	textcolor(7);
	gotoxy(75,7);
	printf("%c",4);
	
	textcolor(8);
	gotoxy(76,19);
	printf("%c",5);
}

void TelaPrincipal(void)
{
	clrscr();
	moldura(1,1,80,25,0,7);
	moldura(2,2,79,4,1,4);
	gotoxy(30,3);
	printf("# # # T i r i n h o # # #");
	moldura(2,5,25,24,4,1);
	moldura(55,5,79,24,4,1);
	Ele();
	textcolor(7);
	
}

int BuscaNome(TpJogador Jog[TF], int TL, char NomeJog[20])
{
	int a = 0;
	while(a < TL && stricmp(Jog[a].Nome, NomeJog) != 0)
		a++;
	if(a < TL)
		return a;
	else
		return -1;
}

void Alterar(TpJogador Jog[TF], int TL)
{
	char AuxJog[20];
	int pos, a;
	clrscr();
	moldura(1,1,80,15,1,4);
	gotoxy(34,2);
	printf("* * Alterar * *");
	gotoxy(3,4);
	printf("Nome para alterar: ");
	gets(AuxJog);
	
	while(TL < TF && strcmp(AuxJog,"\0") > 0)
	{
		pos = BuscaNome(Jog,TL,AuxJog);
		if(pos == -1)
		{
			gotoxy(3,5);
			printf("Jogador nao cadastrado!!!");
		}
			
		else
		{
			gotoxy(3,6);
			printf("Encontrado: ");
			gotoxy(3,7);
			printf("Jogador: %s", Jog[pos].Nome);
			gotoxy(3,8);
			printf("Pontuacao: %d", Jog[pos].pontuacao);
			gotoxy(3,9);
			printf("Confirma a alteracao(S/N)?");
			if(toupper(getche()) == 'S')
			{
				gotoxy(3,10);
				printf("Novo nome: ");
				fflush(stdin);
				gets(Jog[pos].Nome);
				gotoxy(3,11);
				printf("Jogador Alterado");
			}
		}
		getch();
		clrscr();
		moldura(1,1,80,15,1,4);
		gotoxy(34,2);
		printf("* * Alterar * *");
		gotoxy(3,4);
		printf("Nome para alterar: ");
		gets(AuxJog);
	}
}

void Excluir(TpJogador Jog[TF], int &TL)
{
	char AuxJog[20];
	int pos, a;
	clrscr();
	moldura(1,1,80,15,4,1);
	gotoxy(34,2);	
	printf("* * Excluir * *");
	gotoxy(3,4);
	printf("Nome a Excluir: ");
	fflush(stdin);
	gets(AuxJog);
	while(TL < TF && strcmp(AuxJog,"\0") > 0)
	{
		pos = BuscaNome(Jog,TL,AuxJog);
		if(pos == -1)
		{
			gotoxy(3,5);
			printf("Jogador nao cadastrado!!!");
		}
			
		else
		{
			gotoxy(3,6);
			printf("Encontrado: ");
			gotoxy(3,7);
			printf("Jogador: %s", Jog[pos].Nome);
			gotoxy(3,8);
			printf("Pontuacao: %d", Jog[pos].pontuacao);
			gotoxy(3,9);
			printf("Confirma Exclusao(S/N)?");
			
			if(toupper(getche()) == 'S')
			{
				for(a = pos ; a < TL-1;a++)
				{
					Jog[a] = Jog[a+1];
				}
				TL--;
				gotoxy(3,10);
				printf("Jogador Excluido");
			}
		}
		getch();
		clrscr();
		moldura(1,1,80,15,4,1);
		gotoxy(34,2);	
		printf("* * Excluir * *");
		gotoxy(3,4);
		printf("Nome a Excluir: ");
		fflush(stdin);
		gets(AuxJog);
	}
}


void Ranking(TpJogador Jog[TF], int TL)
{
	TpJogador RegJog;
	int a,b,i, l = 4, z = 5;
	clrscr();
	moldura(1,1,80,25,1,4);
	gotoxy(28,2);
	printf("* * Ordenar pelo Nome * *");
	if(TL == 0)
	{
		gotoxy(3,4);
		printf("Nao ah jogadores!");
	}
	else
	{
		for(a = 0; a < TL - 1; a++)
		{
			for(b = a+1; b < TL; b++)
			{
				if(Jog[a].pontuacao < Jog[b].pontuacao)
				{
					RegJog = Jog[a];
					Jog[a] = Jog[b];
					Jog[b] = RegJog;
				}
			}
		}
		for(i = 0; i < TL; i++)
		{
				
			if(i <= 2)
			{
				if(i == 0){
					
					textcolor(6);
					gotoxy(45,8);
					printf("%dº Jogador: %s", i+1, Jog[i].Nome);
					gotoxy(45,9);
					printf("Pontuacao: %d", Jog[i].pontuacao);
					gotoxy(45,10);
					printf("___________");
					gotoxy(45,11);
					printf("|         |");
					gotoxy(45,12);
					printf("|         |");
				}
				if(i == 1)
				{
					textcolor(12);
					gotoxy(58,11);
					printf("%dº Jogador: %s", i+1, Jog[i].Nome);
					gotoxy(58,12);
					printf("Pontuacao: %d", Jog[i].pontuacao);
					gotoxy(58,13);
					printf("___________");
					gotoxy(58,14);
					printf("|         |");
					gotoxy(58,15);
					printf("|         |");
				}
				if(i == 2)
				{
					textcolor(9);
					gotoxy(31,13);
					printf("%dº Jogador: %s", i+1, Jog[i].Nome);
					gotoxy(31,14);
					printf("Pontuacao: %d", Jog[i].pontuacao);
					gotoxy(31,15);
					printf("___________");
					gotoxy(31,16);
					printf("|         |");
					gotoxy(31,17);
					printf("|         |");
				}
			}
			else
			{
				textcolor(7);
				gotoxy(3,l);
				printf("%dº Jogador: %s", i+1, Jog[i].Nome);
				gotoxy(3,z);
				printf("Pontuacao: %d", Jog[i].pontuacao);
				l += 3;
				z += 3;	
			}
			textcolor(7);
			
		}
	}
	getch();
}


void RelJogador(TpJogador Jog[TF], int Qtde)
{
	TpJogador RegJog;
	int a,b,i, l = 4, z = 5;
	clrscr();
	moldura(1,1,80,25,1,4);
	gotoxy(28,2);
	printf("* * Relatorio de jogadores * *");
	if(Qtde == 0)
	{
		gotoxy(3,4);
		printf("Nao ah jogadores!");
	}
	else
	{
		for(i = 0; i < Qtde; i++)
		{
			gotoxy(3,l);
			printf("Jogador: %s", Jog[i].Nome);
			gotoxy(3,z);
			printf("Pontuacao: %d", Jog[i].pontuacao);
			l += 3;
			z += 3;
		}
	}
	getch();
}

void CadJogador(TpJogador Tabjog[TF], int &TL)
{
	char AuxNome[20];
	int pos;
	clrscr();
	moldura(1,1,80,15,1,4);
	gotoxy(25,2);
	printf("* * Cadastro de Jogadores * *");
	gotoxy(3,4);
	printf("Nome: ");
	fflush(stdin);
	gets(AuxNome);
	
	while(TL < TF && strcmp(AuxNome,"\0") > 0)
	{
		
		pos = BuscaNome(Tabjog,TL,AuxNome);
		if(pos == -1)
		{
			strcpy(Tabjog[TL].Nome, AuxNome);
			Tabjog[TL].pontuacao = 0;
			
			
			TL++;
		}
		else
		{
			gotoxy(3,6);
			printf("Nome ja cadastrado");
			getch();
		}
			
		clrscr();
		moldura(1,1,80,15,1,4);
		gotoxy(25,2);
		printf("* * Cadastro de Jogadores * *");
		gotoxy(3,4);
		printf("Nome: ");
		fflush(stdin);
		gets(AuxNome);
		
	}	
}

char Menu(void)
{

	TelaPrincipal();

	gotoxy(34,6); printf("* * MENU * *");
	gotoxy(30,8); printf("[A] Cadastrar Jogadores");
	gotoxy(30,9); printf("[B] Exibir Jogadores");
	gotoxy(30,10); printf("[C] Ranking");
	gotoxy(30,11); printf("[D] Excluir jogadores");
	gotoxy(30,12); printf("[E] Alterar nome");
	gotoxy(30,13); printf("[F] Jogar");
	gotoxy(30,14); printf("[ESC] Sair");
	gotoxy(30,16); printf("Opcao: ");
	return toupper(getche());
	
}

void MostrarElementos(TpElemento Elementos[TF])
{
	int i;
	for(i = 0; i < TF; i++)
	{
		textcolor(Elementos[i].cor);
		gotoxy(Elementos[i].x,Elementos[i].y);
		printf("%c",Elementos[i].simbolo);
	}
	textcolor(7);
}

void GerarElementos(TpElemento Elementos[TF])
{
	int i;
	for(i = 0; i < TF; i++)
	{
		Elementos[i].simbolo = rand() % 4+3; //3..6
		Elementos[i].vivo = 'S';
		Elementos[i].x = rand() % 69+2; // 1..79
		Elementos[i].y = rand() %15+3;	//1..24
		Elementos[i].cor = rand()%14+2; //0 (BLACK) .. 15 (White)
		Elementos[i].pontos = (rand() % 3+1) *10;	// 10 - 20 - 30
	}
	gotoxy(3,5);
	printf("Tabela de Elementos Gerada!");
	getch();
	clrscr();
}

void Jogar(TpJogador Jog[TF], int TL)
{
	TpElemento TabElem[TF];
	//time_t armazena os valores relacionados a data e hora em uma única variável
	time_t inicio,agora; // declaração variáveis no time_t para armazenar os tempos
	//time() pega data e horario
	inicio = time(NULL); // a variavel inicio pega o tempo atual
	char AuxJog[20], Jogador = 2, tecla;
	int col = 40, pos, posJ, i,pontos=0;
	float tempo = 0;
	clrscr();
	moldura(1,1,80,25,0,7);
	gotoxy(34,2);
	printf("* * Jogar * *");
	gotoxy(3,4);
	printf("Nome do Jogador: ");
	fflush(stdin);
	gets(AuxJog);
	posJ=BuscaNome(Jog,TL,AuxJog);
	if(posJ == -1)
	{
		gotoxy(3,5);
		printf("Joagador nao Cadastrado!");	
	}
	else
	{
		
		GerarElementos(TabElem);
		MostrarElementos(TabElem);
		do
		{
			moldura(1,21,17,23,0,7);
			moldura(1,1,70,20,0,7);
			gotoxy(2,22);
			printf("Pontuacao: %d",pontos);
			agora = time(NULL); // a variavel agora pega o tempo atualizado
			textcolor(6);
			gotoxy(col,19);
			printf("%c", Jogador);
			textcolor(7);
			tecla = getch();
			gotoxy(col,19);
			printf(" ", Jogador);
			switch(toupper(tecla))
			{
				case 'A': if(col> 2)col--;
					break;	
				case 'D': if(col < 79)col++;
					break;
		
				case 32: //Espaço --> Atirar
						int lin=18;
						while(lin > 1)
						{
							
							gotoxy(col,lin);
							printf("*");
							Sleep(20);
							gotoxy(col,lin);
							printf(" ");
							
							for(i = 0; i < TF; i++)
							{
								if(col == TabElem[i].x && lin == TabElem[i].y && TabElem[i].vivo == 'S')
								{
									pontos+=TabElem[i].pontos;
									
									TabElem[i].vivo = 'N';
									gotoxy(2,22);
									printf("Pontuacao: %d",pontos);
									lin = 0;
								}
							}
							
							lin--;
						}
						break;
			}
			tempo = difftime(agora, inicio); // difftime(final,inicio) essa função pega a diferença do tempo do inicio e do agora
		}while(tecla != 27 && tempo < 30);
		
		if(pontos > Jog[posJ].pontuacao)
			Jog[posJ].pontuacao = pontos;	
		
		pontos = 0;
		
		gotoxy(30,12);
		printf("* * * FIM DE JOGO * * *");
		Sleep(4000);
	}
	getch();
	
}
void Executar(void)
{
	TpJogador TabJ[TF];
	int TLJ = 0;
	char op;
	TelaPrincipal();
	do
	{
		
		op = Menu();
		switch(op)
		{
			case 'A': CadJogador(TabJ,TLJ);
				break;
				
			case 'B': RelJogador(TabJ,TLJ);
				break;
				
			case 'C': Ranking(TabJ,TLJ);
				break;
				
			case 'D': Excluir(TabJ,TLJ);
				break;		
				
			case 'E': Alterar(TabJ,TLJ);
				break;	
				
			case 'F': Jogar(TabJ,TLJ);
				break;
		}
	}while(op != 27);
}

int main(void)
{
	srand(time(0));
	Executar();
	
	return 0;
}

