#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ExibirOpcoesMenu();
void RegistrarUsuario();
char VerificarSenha(char *a);
int op;
char senha [20];
char usuario [20];

int main() {
    ExibirOpcoesMenu();
    
    return 0;
}

//void ExibirLogo() {}

void ExibirOpcoesMenu() 
{
	//ExibirLogo();
	printf("MENU");
	printf("\nDigite 1 para REGISTRAR O USUARIO");
	printf("\nDigite 2 para REMOVER UM USUARIO");
	printf("\nDigite 3 para EXIBIR OS USUARIOS REGISTRADOS");
	printf("\nDigite a opcao escolhida: ");
	scanf("%d",&op);
	
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
		default:
			printf("Opcao invalida");
	}
	
}

void RegistrarUsuario() {
    char cont;
    char op = 's'; // inicializa op para entrar no loop

    system("cls");
    printf("CADASTRO");
    
    while (op == 's') {
        do 
        {
            printf("\nPreste atencao. Atente-se aos requisitos a baixo para criar uma senha segura! ");
            printf("\nA) 8 a 12 caracteres");
            printf("\nB) Pelo menos uma letra maiuscula");
            printf("\nC) Pelo menos um numero");
            printf("\nD) Pelo menos um caracter especial");
            
            printf("\nDeseja continuar? (S/N): ");
            scanf(" %c", &cont);
            cont = tolower(cont);
        } while (cont != 's' && cont != 'n');
        
        if (cont == 's') 
        {
            printf("\nUsuario: ");
            scanf("%s", usuario);
            
            // laço de repetição para solicitar que o usuário informe novamente a senha, até que ela atenda aos requisitos.
            do 
            {
                printf("Senha: ");
                scanf("%s", senha);
                
                // verificar se a senha não satisfaz as regras. Ou seja, se o return da função não for 1
                if (!VerificarSenha(senha)) 
                {
                    printf("Senha invalida. Releia as orientacoes para criar uma senha segura e tente novamente!\n");
                }
            } while (!VerificarSenha(senha));
            
            printf("Cadastro realizado com sucesso!\n");
            printf("Deseja realizar um novo cadastro? (S/N): ");
            scanf(" %c", &op);
            op = tolower(op);    
        }
    }
    
    printf("Digite alguma tecla para voltar ao menu: ");
    getchar();
    getchar();
    system("cls");
    ExibirOpcoesMenu();
}

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



