#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>

void ExibirOpcoesMenu();
void RegistrarUsuario();
char VerificarSenha(char *a);
int op;
char senha [20];
char usuario [20];

void textcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    ExibirOpcoesMenu();
    
    return 0;
}
//----------------------------------
void ExibirOpcoesMenu() 
{
 int corOriginal = 7;
	
	printf("\n\n\n\n\n\n");
	textcolor(14); //cor amarelo para o menu
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
			printf("Opcao invalida");
	}
	
}
//---------------------------------
void RegistrarUsuario() {
    char cont;
    char op = 's'; // inicializa op para entrar no loop
    int corOriginal = 7; //7 é branco
    
	
    system("cls");
    textcolor(4);
    printf("(ESQ) Para voltar ao menu\n");
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
    

            printf("                         Atente-se aos requisitos necessarios para criar uma");
			
			textcolor(10);
			printf(" senha segura!\n");
			textcolor(corOriginal);
			printf("\n");
            printf("                                        A) 8 a 12 caracteres\n");
            printf("                                        B) Pelo menos uma letra maiuscula\n");
            printf("                                        C) Pelo menos um numero\n");
            printf("                                        D) Pelo menos um caracter especial\n");
            Sleep(4000);
            printf("                                        Vamos continuar!\n");
            Sleep(4000);
 	
			textcolor(14);
            printf("                                        Usuario:");
            textcolor(corOriginal);
            scanf("%s", usuario);
    
            // laço de repetição para solicitar que o usuário informe novamente a senha, até que ela atenda aos requisitos.
            do 
            {
            	textcolor(14);
                printf("                                         Senha:");
                textcolor(corOriginal);
                scanf("%s", senha);
                
                 printf("\n");
                // verificar se a senha não satisfaz as regras. Ou seja, se o return da função não for 1
                if (!VerificarSenha(senha)) 
                {
                	textcolor(4);
                    printf("                       Senha invalida. Releia as orientacoes para criar uma senha segura e tente novamente!\n");
                    printf("\n");
                }
            } while (!VerificarSenha(senha));
            
            printf("Cadastro realizado com sucesso!\n");
            printf("Deseja realizar um novo cadastro? (S/N): ");
            scanf(" %c", &op);
            op = tolower(op);    
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
		if (isupper(senha[i])) temMaiuscula = 1;
		if (isdigit(senha[i])) temNumero = 1;
		if (ispunct(senha[i])) temEspecial = 1;	
	}
	
	 return temMaiuscula && temNumero && temEspecial; 
	 // a função irá retornar 1 se todas as condições forem atendidas/satisfeitas!
}




