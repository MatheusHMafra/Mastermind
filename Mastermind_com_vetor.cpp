/*
  Alunos: Israel Shalom Orel Carvalho, Leonardo Borges Lopes, Lucas Barcia López Hellmann e Matheus Henrique Tomelin Mafra
*/
#include <iostream>
#include <ctime>
#include <locale.h>
#include <windows.h>
using namespace std;
int main() {
    setlocale(LC_ALL, "Portuguese");
    int attempts; //tentativas
    srand(time(NULL)); // Configurando o gerador de números aleatórios com base no tempo atual

    bool quit = false;
    while (!quit) {
        int option; //opção para menu
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << "                      Mastermind" << endl;
        cout << "                  Escolha uma opcão: " << endl;
        cout << endl;
        cout << "                     1 - Jogar" << endl;
        cout << "              2 - Informações do Jogo" << endl;
        cout << "                      3 - Sair" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cin >> option;

        switch (option) {
            case 1:
                //system("clear");
                system("cls");
                int password[4]; // Gera a senha aleatória de 4 digitos
                for (int i = 0; i < 4; i++) {
                    int digit;
                    do {
                        digit = rand() % 6 + 1; //Senha apenas pode ser de 1 até 6
                    } while (i > 0 && digit == password[i-1]);
                    password[i] = digit; //Armazena senha
                    cout << password[i] << endl; //Use isto para testar
                }
                attempts = 10; // Número de tentativas
                while (attempts > 0) { // Lendo a tentativa do jogador
                    int guess[4];
                    cout << "Digite a sua tentativa (4 numeros entre 1 e 6) ou digite 0 para sair: ";
                    for (int i = 0; i < 4; i++) {
                        cin >> guess[i];
                        if (guess[0] == 0) { //Se for 0 volta para o menu
                            attempts = 1;
                            break;
                        }
                    }
                    int correct_position = 0, correct_digit = 0; // Verificando a tentativa
                    for (int i = 0; i < 4; i++) {
                        if (guess[i] == password[i]) { // Verificando quantos numeros estão na posição correta
                            correct_position++;
                        } else {
                            for (int j = 0; j < 4; j++) {
                                if (guess[i] == password[j]) { // Verificando quantos numeros estão corretos
                                    correct_digit++;
                                    break;
                                }
                            }
                        }
                    }
                    cout << endl; // Exibindo o resultado da tentativa
                    cout << "Você acertou " << correct_position << " numero(s) na posição correta." << endl;
                    cout << "Você acertou " << correct_digit << " numero(s) corretos, mas na posição errada.";
                    cout << endl;
                    if (correct_position == 4) { //Verificando se o jogador vençeu
                        cout << endl;
                        cout << "Parabéns, você venceu!" << endl;
                    } else { //Jogador não terminou o jogo
                        attempts--;
                        cout << "Voce tem " << attempts << " tentativas restantes." << endl;
                        if (attempts < 0) { //Verificando se o jogador gastou todas as tentativas
                            cout << "Voce perdeu! A senha correta era ";
                            for (int i = 0; i < 4; i++) { //Mostrando a senha correta
                                cout << password[i];
                            }
                            cout << "." << endl;
                            break;
                        }
                    }
                }
                break;
            case 2:
                //system("clear")
                system("cls");
                cout << endl << "Equipe de desenvolvimento: Matheus Mafra" << endl;
                cout << "Mês/ano: Abril/2023" << endl << endl;
                break;
            case 3:
                //system("clear")
                system("cls");
                cout << endl;
                cout << "Obrigado por jogar! Até a proxima." << endl;
                quit = true;
                break;
            default:
                //system("clear")
                system("cls");
                cout << endl;
                cout << "Opção invalida. Tente novamente." << endl;
                break;
        }
    }
    return 0;
}
