//bibliotecas utilizadas para a construção do programa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.c>
#include <windows.h>

//funções utilizadas
void ExibirOpcoesMenu();
void ArmazenarUsuarios();
void ArquivarUsuarios();
void RegistrarUsuario();
char VerificarSenha(char *a);
void RemoverUsuario();
void CriptografarUsuarios(const char* a, const char* b); 
void ExibirDadosDescriptografados();
void EditarUsuario();
void ExibirUsuarios(); 	
void OpcaoExtra();

//variáveis,vetores, e matrizes GLOBAIS utilizadas
int erro = 0;
int corOriginal = 7;
int op;           
int tot;          
char criptoUsuario[21]; 
char criptoSenha[21]; 
char nomes[50][21];    
char senhas[50][21];
//--------------------------------- (funções separadas pela linha cinza tracejada para facilitar a visualização
int main() {	
	ArmazenarUsuarios();
	do {
		ExibirOpcoesMenu();
	} while (op != 6);
    ArquivarUsuarios();
}
//---------------------------------
void ExibirOpcoesMenu() 
{
	system("cls");
	textcolor(3);
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n                                                       __  ___ ______ _   __ __  __ \n");
	printf("                                                      /  |/  // ____// | / // / / / \n");
	printf("                                                     / /|_/ // __/  /  |/ // / / /  \n");
	printf("                                                    / /  / // /___ / /|  // /_/ /   \n");
	printf("                                                   /_/  /_//_____//_/ |_/ |____/    \n");
	
	textcolor(14);
	
	printf("\n                                       ______ ______ ____ _   __ ______ ____ _____  ___     __  \n");
	printf("                                      / __  // __  //  _// | / // ____//  _// __  //   |   / /  \n");
	printf("                                     / /_/ // /_/ / / / /  |/ // /     / / / /_/ // /| |  / /   \n");
	printf("                                    / ____// _, _/_/ / / /|  // /___ _/ / / ____// ___ | / /___ \n");
	printf("                                   /_/    /_/ |_|/___//_/ |_/|_____//___//_/    /_/  |_|/_____/ \n");
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");

	textcolor(corOriginal);
    printf("                                            Digite ");
    textcolor(9); 
    printf("(1)");
    textcolor(corOriginal); 
    printf(" para ");
    textcolor(14);
    printf("REGISTRAR O USUARIO\n");

    textcolor(corOriginal);
    printf("                                            Digite ");
    textcolor(9);
    printf("(2)");
    textcolor(corOriginal); 
    printf(" para ");
    textcolor(14); 
    printf("REMOVER UM USUARIO\n");
    
    textcolor(corOriginal);
    printf("                                            Digite ");
    textcolor(9); 
    printf("(3)");
    textcolor(corOriginal); 
    printf(" para ");
    textcolor(14); 
    printf("EDITAR UM USUARIO\n");
    
    textcolor(corOriginal);
    printf("                                            Digite ");
    textcolor(9); 
    printf("(4)");
    textcolor(corOriginal); 
    printf(" para ");
    textcolor(14); 
    printf("EXIBIR OS USUARIOS REGISTRADOS\n");
    
    textcolor(corOriginal);
    printf("                                            Digite ");
    textcolor(9); 
    printf("(5)");
    textcolor(corOriginal); 
    printf(" para ");
    textcolor(14); 
    printf("EXTRA\n");
    
    textcolor(corOriginal);
    printf("                                            Digite ");
    textcolor(9); 
    printf("(6)");
    textcolor(corOriginal); 
    printf(" para ");
    textcolor(14); 
    printf("SAIR/SALVAR\n");
    
    textcolor(14);
    printf("                                            OPCAO DESEJADA: ");
    textcolor(9);
    scanf("%d", &op);
    getchar(); 
          	
	switch (op) 
	{
		case 1:
			RegistrarUsuario();
			break;
		case 2:
			RemoverUsuario();
			break;
		case 3:
			EditarUsuario();
			break;
		case 4:
			ExibirUsuarios();
			break;
		case 5:
			OpcaoExtra();
		break;
		case 6:
			return;
			break;
		default:
			textcolor(4);
			printf("\nOpcao invalida. Tente novamente!");
	}	
}
//---------------------------------
void ArmazenarUsuarios(){
	char linha[20];
	FILE *arquivo = fopen("usuarios.txt", "r");
	tot = 0;
	
	fseek(arquivo, 0, SEEK_END);  
    if (ftell(arquivo) == 0) return;
	fseek(arquivo, 0, SEEK_SET);
	
	while(!feof(arquivo)){
		fgets(nomes[tot], 100, arquivo);
		nomes[tot][strcspn(nomes[tot], "\n")] = '\0';
		fgets(senhas[tot], 100, arquivo);
		senhas[tot][strcspn(senhas[tot], "\n")] = '\0';
		tot++;
	}
	fclose(arquivo);
}
//---------------------------------
void ArquivarUsuarios(){
	FILE *arquivo = fopen("usuarios.txt", "w"); //Modo de escrita "w". Como aprendemos com o professor Ferlini, o parâmetro "w" abre o aquivo para gravar. Será "truncado", caso o arquivo já existir
	for(int x = 0; x < tot; x++){
		if(x == 0) fprintf(arquivo, "%s\n%s", nomes[0], senhas[0]);
		else fprintf(arquivo, "\n%s\n%s", nomes[x], senhas[x]);
	}
	fclose(arquivo);
}
//---------------------------------
void LerSenha(char *senha, int maxLength) {
    int i = 0;
    char ch;

    while (i < maxLength - 1) { 
        ch = getch(); 
        if (ch == '\r') { 
            break; 
        } else if (ch == '\b') { 
            if (i > 0) {
                i--; 
                printf("\b \b"); 
            }
        } else {
            senha[i++] = ch; 
            printf("*"); 
        }
    }
    senha[i] = '\0'; 
}
//---------------------------------
void RegistrarUsuario() {
    char senha[15];
    char senhaVer[20];
    char usuario[20];
    int senhaValida = 0;
    FILE *arquivo;
    char novoRegistro;

     do {
        system("cls");
        textcolor(3);
        printf("-----------------------------------------------------------------------------------------------------------------------"); 
        printf("\n				     ____   ______ ______ ____ _____ ______ ____   ____ \n");
        printf("				    / __ | / ____// ____//  _// ___//_  __// __ | / __ |\n");
        printf("				   / /_/ // __/  / / __  / /  |__ |  / /  / /_/ // / / /\n");
        
        textcolor(14);
        
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
        gotoxy(50, 16);
        printf("Nome: ");
        gotoxy(50, 17);
        printf("Senha: ");
        do {
            gotoxy(56, 16);
            printf("                                                              ");
            textcolor(corOriginal);
            gotoxy(56, 16);
            gets(usuario);
        } while (strlen(usuario) == 0 || strlen(usuario) >= 20);

        do {
            gotoxy(57, 17);
            printf("                ");
            gotoxy(57, 17);
            textcolor(corOriginal);
            LerSenha(senha, sizeof(senha));

            if (VerificarSenha(senha) == 0) {
                gotoxy(50, 19);
                printf("                                                                ");
                gotoxy(32, 19);
                textcolor(4);
                printf("Atente-se aos requisitos estabelecidos e tente novamente!");
                senhaValida = 0;
            } else {
                senhaValida = 1;

                gotoxy(32, 19);
                printf("                                                                ");

                gotoxy(50, 18);
                textcolor(14);
                printf("Repita senha: ");
            }
        } while (senhaValida == 0);

        gotoxy(64, 18);

        do {
            printf("                                                                        ");
            gotoxy(64, 18);
            textcolor(corOriginal);
            LerSenha(senhaVer, sizeof(senhaVer));

            if (strcmp(senhaVer, senha) != 0) {
                gotoxy(34, 20);
                printf("                                                                    ");
                gotoxy(34, 20);
                textcolor(4);
                printf("       As senhas nao coincidem, tente novamente.");
                gotoxy(64, 18);
            }
        } while (strcmp(senhaVer, senha) != 0);

		gotoxy(34, 20);
		printf("                                                                    ");    
        CriptografarUsuarios(usuario, senha);
        textcolor(10);
        gotoxy(50, 18); 
		textcolor(corOriginal);
        printf("\n\n                                                   Usuario ");
        textcolor(10);
        printf("Registrado! ");
        textcolor(3);
        textcolor(10);
        sleep(2);
        textcolor(corOriginal);
        textcolor(14);
        printf("\n\n                                           Deseja registrar outro usuario? ");
        textcolor(corOriginal);
        printf("(");
        textcolor(10);
        printf("S");
        textcolor(corOriginal);
        printf("/");
        textcolor(4);
        printf("N");
        textcolor(corOriginal);
        printf("): ");
        novoRegistro = getchar();
        getchar();
    } while (novoRegistro == 's' || novoRegistro == 'S');
}
//---------------------------------
void RemoverUsuario() {
    int index;

	system("cls");
	textcolor(3);
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n 				           ______ ______ __  ___ ____  _    __ ______ ____  \n");
	printf(" 				          / __  // ____//  |/  // __ || |  / // ____// __ | \n");
	printf(" 				         / /_/ // __/  / /|_/ // / / /| | / // __/  / /_/ / \n");
	printf(" 				        / _, _// /___ / /  / // /_/ / | |/ // /___ / _, _/  \n");
	printf(" 				       /_/ |_|/_____//_/  /_/ |____/  |___//_____///_/ |_|   \n");
		
	textcolor(14);
	
	printf("                                         __  __ ____   __  __ ___     ____   ____ ____  _____ \n");
    printf("                                        / / / //___/  / / / //   |   / __ \\ /  _// __ \\/ ___/ \n");
    printf("                                       / / / / \\__ \\ / / / // /| |  / /_/ / / / / / / /\\__ \\ \n");
    printf("                                      / /_/ / ___/ // /_/ // ___ | / _  _/_/ / / /_/ /___/ / \n");
    printf("                                      \\____/ /____/ \\____//_/  |_|/_/ |_|/___/ \\____//____/ \n");
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
		
    if (tot == 0) {
        textcolor(4);
        printf("Nao ");
		textcolor(corOriginal);
		printf("ha usuarios registrados para remover!\n");
        getchar();
		return;
    }

    textcolor(3);
    printf("\n                                                       Usuarios ");
    textcolor(14);
    printf("Registrados:");
    
    printf("\n");
    
    for (int i = 0; i < tot; i++) {
    	textcolor(8);
        printf("\n                                                           (%d) " ,i+1); 
        for(int x = 0; x < strlen(nomes[i]); x++){
        	textcolor(corOriginal);
        	printf("%c", nomes[i][x] - 5);
		}
    }
    
    printf("\n");
    
    textcolor(corOriginal);
    printf("\n                                            Digite o ");
	textcolor(8);
	printf("numero ");
	textcolor(8);
	textcolor(corOriginal);
	printf("do usuario que deseja ");
	textcolor(4);
	printf("remover: ");
	textcolor(corOriginal);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > tot) {
        textcolor(corOriginal);
        printf("Opcao ");
		textcolor(4);
		printf("invalida. ");
		textcolor(corOriginal);
		printf("Tente novamente.\n");
        return;
    }
    
    index--; 
    
    for (int i = index; i < tot - 1; i++) {
        strcpy(nomes[i], nomes[i + 1]);
        strcpy(senhas[i], senhas[i + 1]);
    }

    tot--; 

    textcolor(10);
    printf("\n                                                    Usuario removido com sucesso!\n");
    textcolor(corOriginal);
    
    printf("\n");
    printf("                                       Digite" );
	textcolor(12);
	printf(" [alguma tecla] ");
	textcolor(corOriginal);
	printf("para voltar ao ");
	textcolor(12);
	printf("Menu Principal! ");
    getchar();
}
//---------------------------------
char VerificarSenha(char *a) {
    int comprimento;
    int temMaiuscula = 0, temNumero = 0, temEspecial = 0;

    comprimento = strlen(a);

    if (comprimento < 8 || comprimento > 12) 
    {
        return 0; //já não se enquadra na regra mais simples. Então já retorna zero.
    }			
	
    for (int i = 0; i < comprimento; i++)
    {
        if (isupper(a[i])) temMaiuscula = 1;
        if (isdigit(a[i])) temNumero = 1;
        if (ispunct(a[i])) temEspecial = 1;	
    }
		
    if (temMaiuscula == 1 && temNumero == 1 && temEspecial == 1) {
        return 1; 
    } else {
        erro++;
        return 0;
    }
}
//---------------------------------
void EditarUsuario() {
    int index;
    char novaSenha[15], senhaConfirmacao[15];
    
    system("cls");
    textcolor(3);
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\n                                                  ______ ______ ____ ______ ___     ______ \n");
    printf("                                                 / ____// __  //  _//_  __//   |   / __  / \n");
    printf("                                                / __/  / / / / / /   / /  / /| |  / /_/ / \n");
    printf("                                               / /___ / /_/ /_/ /   / /  / ___ | / _, _/   \n");
    printf("                                              /_____//_____//___/  /_/  /_/  |_|/_/ |_|    \n");
    
    textcolor(14);
    
    printf("                                         __  __ ____   __  __ ___     ____   ____ ____  _____ \n");
    printf("                                        / / / //___/  / / / //   |   / __ \\ /  _// __ \\/ ___/ \n");
    printf("                                       / / / / \\__ \\ / / / // /| |  / /_/ / / / / / / /\\__ \\ \n");
    printf("                                      / /_/ / ___/ // /_/ // ___ | / _  _/_/ / / /_/ /___/ / \n");
    printf("                                      \\____/ /____/ \\____//_/  |_|/_/ |_|/___/ \\____//____/ \n");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    
    if (tot == 0) {
        textcolor(4);
        printf("\n\n                                          Nao ");
        textcolor(corOriginal);
        printf("ha usuarios registrados para editar!\n");
        getchar();
        return;
    }
	textcolor(3); 
    printf("\n                                                        Usuarios ");
    textcolor(14);
    printf("Registrados:");
    
    printf("\n");
    
    for (int i = 0; i < tot; i++) {
    	textcolor(8);
        printf("\n                                                            (%d) ", i + 1);
        textcolor(corOriginal); 
        for (int x = 0; x < strlen(nomes[i]); x++) {
            printf("%c", nomes[i][x] - 5); 
        }
        
    }
	printf("\n");
	
    textcolor(corOriginal);
    printf("\n                                          Digite o numero do usuario que deseja ");
    textcolor(4);
    printf("editar: ");
    textcolor(corOriginal);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > tot) {
        textcolor(corOriginal);
        printf("Opcao ");
        textcolor(4);
        printf("invalida.");
        textcolor(corOriginal);
        printf(" Tente novamente.\n");
        return;
    }

    index--; 

    textcolor(corOriginal);
    printf("\n");
    printf("                                                  A) 8 a 12 caracteres\n");
    printf("                                                  B) Pelo menos uma letra maiuscula\n");
    printf("                                                  C) Pelo menos um numero\n");
    printf("                                                  D) Pelo menos um caracter especial\n");

    int senhaValida = 0; 
    
    while (!senhaValida) {  
        printf("\n                                                  Digite a nova senha: ");
        LerSenha(novaSenha, sizeof(novaSenha));

        if (VerificarSenha(novaSenha) == 0) {
            printf("\n                                    A senha ");
            textcolor(4);
            printf("nao ");
            textcolor(corOriginal);
            printf("atende aos requisitos. Tente novamente.");
        } else {
            senhaValida = 1; 
        }
    }
    
    int senhasIguais = 0;
    
    while (!senhasIguais) {
        printf("\n                                                  Confirme a nova senha: ");
        LerSenha(senhaConfirmacao, sizeof(senhaConfirmacao));

        if (strcmp(novaSenha, senhaConfirmacao) != 0) {
            printf("\n\n                                             As senhas ");
            textcolor(4);
            printf("nao ");
            textcolor(corOriginal);
            printf("coincidem. Tente novamente.\n");
        } else {
            senhasIguais = 1; 
        }
    }
	    
    for(int i = 0; i < strlen(novaSenha); i++){
    	novaSenha[i] = novaSenha[i] + 5;
	}
    strcpy(senhas[index], novaSenha); 

    strcpy(senhas[index], novaSenha);            
    printf("\n\n                                                   Senha alterada com ");
    textcolor(10);
    printf("sucesso!\n");
    printf("\n");
    textcolor(corOriginal);
    printf("                                      Digite");
    textcolor(12);
    printf(" [alguma tecla] ");
    textcolor(corOriginal);
    printf("para voltar ao ");
    textcolor(12);
    printf("Menu Principal!\n\n");
    getchar();
}
//---------------------------------
void CriptografarUsuarios(const char* a, const char* b) {
    char criptoNome[21]; 
    char criptoSenha[21]; 
    int lengthNome = strlen(a);
    int lengthSenha = strlen(b);

    for (int i = 0; i < lengthNome; i++) {
        criptoNome[i] = a[i] + 5; 
    }
    criptoNome[lengthNome] = '\0'; 

    for (int i = 0; i < lengthSenha; i++) {
        criptoSenha[i] = b[i] + 5; 
    }
    criptoSenha[lengthSenha] = '\0'; 
    
    strcpy(nomes[tot], criptoNome);
    strcpy(senhas[tot], criptoSenha);
    tot++;  
}
//---------------------------------
void ExibirUsuarios() {
	
    system("cls");
    textcolor(3);
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("                                         __  __ ____   __  __ ___     ____   ____ ____  _____ \n");
    printf("                                        / / / //___/  / / / //   |   / __ \\ /  _// __ \\/ ___/ \n");
    printf("                                       / / / / \\__ \\ / / / // /| |  / /_/ / / / / / / /\\__ \\ \n");
    printf("                                      / /_/ / ___/ // /_/ // ___ | / _  _/_/ / / /_/ /___/ / \n");
    printf("                                     \\____/ /____/ \\____//_/  |_|/_/ |_|/___/ \\____//_____/ \n");

    textcolor(14);
    
    printf("                              ____   ______ ______ ____ _____ ______ ____   ___     ____   ____  _____ \n");
    printf("                             / __ \\ / ____// ____//  _// ___//_  __// __ \\ /   |   / __ \\ / __ \\/ ___/ \n");
    printf("                            / /_/ // __/  / / __  / /  \\__ \\  / /  / /_/ // /| |  / / / // / / /\\__ \\  \n");
    printf("                           / _, _// /___ / /_/ /_/ /  ___/ / / /  / _, _// ___ | / /_/ // /_/ /___/ / \n");
    printf("                          /_/ |_|/_____/ \\____//___/ /____/ /_/  /_/ |_|/_/  |_|/_____/ \\____//____/ \n");
    printf("\n");
    textcolor(14);
    printf("-----------------------------------------------------------------------------------------------------------------------\n");

    int count = 0;

	for(int i = 0; i < tot; i++){
    	textcolor(corOriginal);
		printf("\n                                               Usuario: ");
		for(int x = 0; x < strlen(nomes[i]); x++){
			textcolor(8);
			printf("%c", nomes[i][x] - 5);
		}
		textcolor(corOriginal);
		printf(" | Senha: ");
		for(int x = 0; x < strlen(senhas[i]); x++){
			textcolor(8);
			printf("%c", senhas[i][x] - 5);
		}
	}

    if (tot == 0) {
    	textcolor(4);
        printf("\n\n                                                   Nenhum ");
        textcolor(corOriginal);
		printf("usuario registrado! \n");
    }
    
 	textcolor(corOriginal);
    printf("\n\n\n                                     Pressione");
    textcolor(12);
    printf(" [ENTER] ");
    textcolor(corOriginal);
    printf("para ver os ");
	textcolor(12);
	printf("dados criptografados! ");
    getchar();
    system("cls");
    ExibirDadosDescriptografados();
    printf("\n\n\n");
    printf("                                       Digite" );
	textcolor(12);
}
//---------------------------------
void ExibirDadosDescriptografados() {
	
    textcolor(3);
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("                                         __  __ ____   __  __ ___     ____   ____ ____  _____ \n");
    printf("                                        / / / //___/  / / / //   |   / __ \\ /  _// __ \\/ ___/ \n");
    printf("                                       / / / / \\__ \\ / / / // /| |  / /_/ / / / / / / /\\__ \\ \n");
    printf("                                      / /_/ / ___/ // /_/ // ___ | / _  _/_/ / / /_/ /___/ / \n");
    printf("                                      \\____/ /____/ \\____//_/ |_ |/_/ |_|/___/ \\____//____/ \n");

    textcolor(14);
    
    printf("                ______ ____   ____ ____  ______ ____   ______ ____   ___     ______ ___     ____   ____  _____ \n");
    printf("               / ____// __ \\ /  _// __ \\/_  __// __ \\ / ____// __ \\ /   |   / ____//   |   / __ \\ / __ \\/ ___/ \n");
    printf("              / /    / /_/ / / / / /_/ / / /  / / / // / __ / /_/ // /| |  / /_   / /| |  / / / // / / /\\__ \\ \n");
    printf("             / /___ / _, _/_/ / / ____/ / /  / /_/ // /_/ // _, _// ___ | / __/  / ___ | / /_/ // /_/ /___/ / \n");
    printf("             \\____//_/ |_|/___//_/     /_/   \\____/ \\____//_/ |_|/_/  |_|/_/    /_/  |_|/_____/ \\____//____/ \n");

	printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    
    if (tot == 0) {
        textcolor(4);
        printf("\n\n                                                 Nao ");
        textcolor(corOriginal);
        printf("ha usuarios registrados!\n\n");
    }
    
	for(int i = 0; i < tot; i++){
		textcolor(corOriginal);
	    printf("\n                                               usuario: ");
	    textcolor(10);
	    printf("%s", nomes[i]);
	    textcolor(corOriginal);
	    printf(" | senha: ");
	    textcolor(10);
	    printf("%s", senhas[i]);
	}
    
    textcolor(corOriginal);
    printf("\n\n\n");
    printf("                                       Digite" );
	textcolor(12);
	printf(" [alguma tecla] ");
	textcolor(corOriginal);
	printf("para voltar ao ");
	textcolor(12);
	printf("Menu Principal! ");
    getchar(); 
}
//---------------------------------
void OpcaoExtra() {
	char texto[]= " Com a implementacao do projeto, espera-se a melhoria significativa na protecao e estabilidade do sistema corporativo!";
	char texto2[]= "                    De uma visitinha em nossos perfis para conhecer melhor sobre os nossos trabalhos! ";
	char texto3[]= "                                       Vitor Hugo Assis Da Silva ->";
	char texto4[]= " linkedin.com/vitorhassis";
	char texto5[]= "                                       Guilherme Paschoal Luvizutto ->";
	char texto6[]= " www.linkedin.com/guilherme-luvizutto";
	char texto7[]= "                                       Otavio ->";
	char texto8[]= " linkedin.com/perfilotavio"; 
	char texto9[]= "                   Ficamos extremamentes gratos pela sua participacao em nossa AEP. Ate a proxima! =)";
	
	system("cls");
	textcolor(3);
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                 ______  ____  ______  __     ______\n");
    printf("                                                / __  // __  // ____/ /  |   / __  / \n");
    printf("                                               / / / // /_/ // /    / /| |  / / / / \n");
    printf("                                              / /_/ // ____// /___ / ___ | / /_/ / \n");
    printf("                                             /_____//_/    /_____//_/  |_|/_____/  \n");
  
    textcolor(14);
    
    printf("                                                  ______ _  __ ______ _____  ___ \n");
    printf("                                                 / ____/| |/ //_  __// __  //   | \n");
    printf("                                                / __/   |   /  / /  / /_/ // /| | \n");
    printf("                                               / /___  /   |  / /  / _, _// ___ | \n");
    printf("                                              /_____/ /_/|_| /_/  /_/ |_|/_/  |_| \n");

	printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
	
	printf("\n");
	
	for (int i = 0; i < strlen(texto); i++) {
		textcolor(10);
        printf("%c", texto[i]);
        fflush(stdout);
        usleep(20000); 
    }
    
    printf("\n\n");
    
	for (int i = 0; i < strlen(texto2); i++) {
		textcolor(corOriginal);
        printf("%c", texto2[i]);
        fflush(stdout);
        usleep(15000);;
    }
    
    printf("\n\n");
    
    for (int i = 0; i < strlen(texto3); i++) {
		textcolor(12);
        printf("%c", texto3[i]);
        fflush(stdout);
        usleep(15000);; 
    }
    
    for (int i = 0; i < strlen(texto4); i++) {
		textcolor(8);
        printf("%c", texto4[i]);
        fflush(stdout);
        usleep(15000);;  
    }
    
    printf("\n");
    
    for (int i = 0; i < strlen(texto5); i++) {
		textcolor(12);
        printf("%c", texto5[i]);
        fflush(stdout);
        usleep(15000);;
    }
    
    for (int i = 0; i < strlen(texto6); i++) {
		textcolor(8);
        printf("%c", texto6[i]);
        fflush(stdout);
        usleep(15000);; 
    }
    
    printf("\n");
    
    for (int i = 0; i < strlen(texto7); i++) {
		textcolor(12);
        printf("%c", texto7[i]);
        fflush(stdout); 
        usleep(15000);;  
    }
    
    for (int i = 0; i < strlen(texto8); i++) {
		textcolor(8);
        printf("%c", texto8[i]);
        fflush(stdout);  
        usleep(15000);; 
    }
    
    printf("\n\n");
    
    for (int i = 0; i < strlen(texto9); i++) {
		textcolor(corOriginal);
        printf("%c", texto9[i]);
        fflush(stdout);  
        usleep(15000);; 
    }	
}
