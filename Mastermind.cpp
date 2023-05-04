/*
  Alunos: Israel Shalom Orel Carvalho, Leonardo Borges Lopes, Lucas Barcia López Hellmann e Matheus Henrique Tomelin Mafra
*/
#include <iostream>
#include <ctime>
#include <locale.h>
using namespace std;
int main() {
    setlocale(LC_ALL, "Portuguese");
    int attempts , guess1, guess2, guess3, guess4; //tentativas e palpites
    int correct_position = 0, correct_digit = 0;
    srand(time(NULL)); // Configurando o gerador de números aleatórios com base no tempo atual

    bool quit = false;
    while (!quit) {
        int option; //opção para menu
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "                      Mastermind" << endl;
        cout << "                  Escolha uma opcão: " << endl << endl;
        cout << "                     1 - Jogar" << endl;
        cout << "                     2 - Sobre" << endl;
        cout << "                     3 - Sair" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cin >> option;

        switch (option) {
            case 1:
                system("clear");
                int pass1, pass2, pass3, pass4;// Gera a senha aleatória de 4 digitos
                do{
                    pass1=rand()%6+1;pass2=rand()%6+1;pass3=rand()%6+1;pass4=rand()%6+1;
                }while (pass1 == pass2 || pass2 == pass3 || pass3 == pass4 || pass1 == pass3 || pass1 == pass4 || pass2 == pass4);
                //cout<< pass1 << pass2 << pass3 << pass4 << endl; //Use isto para testar
                attempts = 10; // Número de tentativas
                while (attempts > 0) { // Lendo a tentativa do jogador
                    cout << "Digite a sua tentativa (4 numeros entre 1 e 6) ou digite 0 para sair: ";
                    cin >> guess1;
                    if (guess1 == 0) { //Se for 0 volta para o menu
                        attempts = 1;
                        system("clear");
                        break;
                    }
                    cin >> guess2>>guess3>>guess4;
                    if (guess1 == pass1) { // Verificando se o primeiro número está na posição correta
                        correct_position++;
                    } else if (guess1 == pass2 || guess1 == pass3 || guess1 == pass4) { // Verificando se o primeiro número está correto mas na posição errada
                        correct_digit++;
                    }
                    if (guess2 == pass2) { // Verificando se o segundo número está na posição correta
                        correct_position++;
                    } else if (guess2 == pass1 || guess2 == pass3 || guess2 == pass4) { // Verificando se o segundo número está correto mas na posição errada
                        correct_digit++;
                    }
                    if (guess3 == pass3) { // Verificando se o terceiro número está na posição correta
                        correct_position++;
                    } else if (guess3 == pass1 || guess3 == pass2 || guess3 == pass4) { // Verificando se o terceiro número está correto mas na posição errada
                        correct_digit++;
                    }
                    if (guess4 == pass4) { // Verificando se o quarto número está na posição correta
                        correct_position++;
                    } else if (guess4 == pass1 || guess4 == pass2 || guess4 == pass3) { // Verificando se o quarto número está correto mas na posição errada
                        correct_digit++;
                    }
                    cout << endl << "Você acertou " << correct_position << " numero(s) na posição correta." << endl; // Exibindo o resultado da tentativa
                    cout << "Você acertou " << correct_digit << " numero(s) corretos, mas na posição errada." << endl;
                    if (correct_position == 4) { //Verificando se o jogador vençeu
                        system("clear");
                        cout << endl << "Parabéns, você venceu! A senha correta era" << endl;
                        cout << pass1 << pass2 << pass3 << pass4 << "." << endl; //Mostrando a senha correta
                        system("read 0 -p");
                        system("clear");
                        break;
                    } else { //Jogador não terminou o jogo
                        attempts--;
                        cout << "Voce tem " << attempts << " tentativas restantes." << endl;
                        if (attempts <= 0) { //Verificando se o jogador gastou todas as tentativas
                            cout << "Voce perdeu! A senha correta era ";
                            cout << pass1 << pass2 << pass3 << pass4 << "." << endl; //Mostrando a senha correta
                            system("read 0 -p");
                            system("clear");
                            break;
                        }
                    }
                    correct_position = 0; correct_digit = 0;
                }
                break;
            case 2:
                system("clear");
                cout << "Equipe de desenvolvimento: Israel Shalom, Leonardo Borges, Lucas Barcia e Matheus Mafra" << endl;
                cout << "Mês/ano: Abril/2023" << endl;
                cout << "Professor: Rael Balottin" << endl;
                cout << "Disciplina: Algorítios e Programação" << endl;
                system("read 0 -p");
                system("clear");
                break;
            case 3:
                system("clear");
                cout  << endl << "Obrigado por jogar! Até a proxima." << endl;
                quit = true;
                break;
            default:
                system("clear");
                cout  << endl << "Opção invalida. Tente novamente." << endl;
                system("read 0 -p");
                system("clear");
                break;
        }
    }
    return 0;
}
