#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.c>
#include <windows.h>

void ExibirOpcoesMenu();
void RegistrarUsuario();
char VerificarSenha(char *a);
int op;
int erro=0;

int main() {	
    ExibirOpcoesMenu();
    return 0;
}
//----------------------------------
void ExibirOpcoesMenu() 
{
 int corOriginal = 7;
	
	textcolor(14);
	printf("\n\n\n");
	printf("\n                                                __  ___ ______ _   __ __  __\n");
	printf("                                               /  |/  // ____// | / // / / /\n");
	printf("                                              / /|_/ // __/  /  |/ // / / / \n");
	printf("                                             / /  / // /___ / /|  // /_/ /  \n");
	printf("                                            /_/  /_//_____//_/ |_/ |____/   \n");
	printf("\n\n\n\n");


	textcolor(corOriginal);
    printf("                                        Digite ");
    textcolor(9); 
    printf("(1)");
    
    textcolor(corOriginal); 
    printf(" para ");
    
    textcolor(14);
    printf("REGISTRAR O USUARIO:\n");

    textcolor(corOriginal);
    printf("                                        Digite ");
    textcolor(9);
    printf("(2)");
    
    textcolor(corOriginal); 
    printf(" para ");
    
    textcolor(14); 
    printf("REMOVER UM USUARIO:\n");
    
    textcolor(corOriginal);
    printf("                                        Digite ");
    textcolor(9); 
    printf("(3)");
    
    textcolor(corOriginal); 
    printf(" para ");
    
    textcolor(14); 
    printf("EXIBIR OS USUARIOS REGISTRADOS:\n");

    textcolor(corOriginal);
    printf("                                        Digite ");
    textcolor(9); 
    printf("(4)");
    
    textcolor(corOriginal); 
    printf(" para ");
    
    textcolor(13); 
    printf("EXTRA:\n");
    
    textcolor(corOriginal);
    printf("                                        OPCAO ESCOLHIDA: ");
    scanf("%d", &op);
    getchar(); // Captura nova linha
          	
	switch (op) 
	{
		case 1:
			RegistrarUsuario();
			break;
		case 2:
			//RemoverUsuario();
			break;
		case 3:
			//ExibirUsuarios();
			break;
		case 4:
			//OpcaoExtra();
			break;
		default:
			textcolor(4);
			printf("\nOpcao invalida.Tente novamente!");
	}
	
}
//---------------------------------
void RegistrarUsuario() {
	char senha [15];
	char senhaVer [20];
	char usuario [20];
    char cont;
    char op = 's'; // inicializa op para entrar no loop
    int corOriginal = 7; //7 é branco
    int x;
    
	
    system("cls");

    textcolor(3);
	printf("-----------------------------------------------------------------------------------------------------------------------"); 
    printf("\n				     ____   ______ ______ ____ _____ ______ ____   ____ \n");
    printf("				    / __ | / ____// ____//  _// ___//_  __// __ | / __ |\n");
    printf("				   / /_/ // __/  / / __  / /  |__ |  / /  / /_/ // / / /\n");
    printf("				  / _  _// /___ / /_/ /_/ /  ___/ / / /  / _  _// /_/ / \n");
    printf("				 /_/ |_|/_____/ |____//___/ /____/ /_/  /_/ |_| |____/  \n");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    
    
    textcolor(corOriginal);
    

            printf("\n                         Atente-se aos requisitos necessarios para criar uma");
			
			textcolor(10);
			printf(" senha segura!\n");
			textcolor(corOriginal);
			printf("\n");
            printf("                                              A) 8 a 12 caracteres\n");
            printf("                                              B) Pelo menos uma letra maiuscula\n");
            printf("                                              C) Pelo menos um numero\n");
            printf("                                              D) Pelo menos um caracter especial\n");

            
			textcolor(14);
			gotoxy(50,16);
			printf("Nome: ");
			gotoxy(50,17);
			printf("Senha: ");
			gotoxy(50,18);
			printf("Repita Senha: ");
			do{
				gotoxy(56,16);
		    	printf("                                                              "); 
		    	textcolor(corOriginal);
		    	gotoxy(56,16);
				gets(usuario);
			} while (strlen(usuario) == 0 || strlen(usuario) >= 20);
			
			do{ 
		       gotoxy(57,17);
		       textcolor(corOriginal);
		       printf("                "); 
		       gotoxy(57,17);
		       gets(senha);
		       if(VerificarSenha(senha) == 0){ 
					gotoxy(50,18);
					printf("                                                                ");
					gotoxy(32,18);
					textcolor(4);
		    		printf("Atente-se aos requisitos estabelecidos e tente novamente!");
		    		gotoxy(48,19); 
		    		textcolor(14);
		    		printf("Repita senha: ");
			   }
    } while (VerificarSenha(senha) == 0);
    
	    if(erro == 0) { 
			do {
	    		gotoxy(65,18);
	    		printf("                                                                ");
	    		gotoxy(65,18);
	    		gets(senhaVer);
	    	} while (strcmp(senhaVer,senha) != 0);
	    } else { 
	    	do {
	    		gotoxy(65,19);
	    		printf("                                                                ");
	    		gotoxy(65,19);
	    		gets(senhaVer);
	    	} while (strcmp(senhaVer,senha) != 0);
		}
}

//-----------------------------------
char VerificarSenha(char *a) {
int comprimento;
int temMaiuscula,temNumero,temEspecial = 0;
int i;

comprimento = strlen(a);

	if (comprimento <8 || comprimento > 12) 
	{
		return 0; //já não se enquadra na regra mais simples. Então já retorna zero.
	}			
	
	//vamos percorrer a senha, para ver se ela se encaixa na proposta das regras que determinamos.
	for (int i =0; i<comprimento; i++)
	{
		if (isupper(a[i])) temMaiuscula = 1;
		if (isdigit(a[i])) temNumero = 1;
		if (ispunct(a[i])) temEspecial = 1;	
	}
		
	 // a função irá retornar 1 se todas as condições forem atendidas/satisfeitas!
	 if (temMaiuscula == 1  && temNumero == 1 && temEspecial == 1) {
		return 1; 
	 } else {
			erro++;
			return 0;
		}
	 
}
//--------------------------------------





