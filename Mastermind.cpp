/*
  Aluno: Matheus Henrique Tomelin Mafra 
*/
#include <iostream>
#include <ctime>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    int attempts;
    // Configurando o gerador de números aleatórios com base no tempo atual
    srand(time(NULL));

    bool quit = false;
    while (!quit) {
        int option;
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << "                  JOGO DA MEMÓRIA" << endl;
        cout << "                 Escolha uma opcão: " << endl;
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
                
                system("clear");
                
                int password[4]; // Gerando a senha aleatória
                for (int i = 0; i < 4; i++) {
                    int digit;
                    do {
                        digit = rand() % 6 + 1;
                    } while (i > 0 && digit == password[i-1]);
                    password[i] = digit;
                    cout << password[i];
                }

                attempts = 10; // Jogando o jogo
                while (attempts > 0) {
                    // Lendo a tentativa do jogador
                    int guess[4];
                    cout << "Digite a sua tentativa (4 numeros entre 1 e 6) ou digite 0 para sair: ";
                    for (int i = 0; i < 4; i++) {
                        cin >> guess[i];
                        if (guess[0] == 0) {
                            attempts = 1; //attempts vira 0 para reniciar
                            break;
                        }
                        
                    }

                    // Verificando a tentativa
                    int correct_position = 0, correct_digit = 0;
                    for (int i = 0; i < 4; i++) {
                        if (guess[i] == password[i]) {
                            correct_position++;
                        } else {
                            for (int j = 0; j < 4; j++) {
                                if (guess[i] == password[j]) {
                                    correct_digit++;
                                    break;
                                }
                            }
                        }
                    }
                    
                    cout << endl; // Exibindo o resultado da tentativa
                    cout << "Voce acertou " << correct_position << " numero(s) na posicao correta." << endl;
                    cout << "Voce acertou " << correct_digit << " numero(s) corretos, mas na posicao errada.";
                    cout << endl;

                    // Verificando se o jogo acabou
                    if (correct_position == 4) {
                        cout << endl;
                        cout << "Parabens, voce venceu!" << endl;
                    } else {
                        attempts--;
                        cout << "Voce tem " << attempts << " tentativas restantes." << endl;
                        if (attempts < 0) {
                            cout << "Voce perdeu! A senha correta era ";
                            for (int i = 0; i < 4; i++) {
                                cout << password[i];
                            }
                            cout << "." << endl;
                            break;
                        }
                    }
                }
                break;
            case 2:
                system("clear");
                cout << endl;
                cout << "Equipe de desenvolvimento: Matheus Mafra" << endl;
                cout << "Mes/ano: Abril/2023" << endl;
                cout << endl;
                break;
            case 3:
                system("clear");
                cout << endl;
                cout << "Obrigado por jogar! Ate a proxima." << endl;
                quit = true;
                break;
            default:
                system("clear");
                cout << endl;
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}
