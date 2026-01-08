#include <iostream>
using namespace std;

int main() {
    char A1 = '1', A2 = '2', A3 = '3';
    char B1 = '4', B2 = '5', B3 = '6';
    char C1 = '7', C2 = '8', C3 = '9';
    char opc = ' ';
    char jogador = ' ';
    bool jogadaValida;


    cout << "BEM VINDO AO NOSSO JOGO DA VELHA \n\n\n";

    do {
    	//tabuleiro
        cout << "  " << A1 << "   |   " << A2 << "   |   " << A3 << endl;
        cout << "-----------------------" << endl;
        cout << "  " << B1 << "   |   " << B2 << "   |   " << B3 << endl;
        cout << "-----------------------" << endl;
        cout << "  " << C1 << "   |   " << C2 << "   |   " << C3 << endl;
        cout << "-----------------------" << endl << endl;
        
        //condicao de vitoria
        if ((A1 == A2 && A2 == A3 && A1 != '1') ||
            (B1 == B2 && B2 == B3 && B1 != '4') ||
            (C1 == C2 && C2 == C3 && C1 != '7') ||
            (A1 == B1 && B1 == C1 && A1 != '1') ||
            (A2 == B2 && B2 == C2 && A2 != '2') ||
            (A3 == B3 && B3 == C3 && A3 != '3') ||
            (A1 == B2 && B2 == C3 && A1 != '1') ||
            (A3 == B2 && B2 == C1 && A3 != '3')) {
            cout << "JOGADOR " << jogador << " VENCEU!" << endl;
            break;
        }

		//condicao de velha
        if (A1 != '1' && A2 != '2' && A3 != '3' &&
            B1 != '4' && B2 != '5' && B3 != '6' &&
            C1 != '7' && C2 != '8' && C3 != '9') {
            cout << "DEU VELHA!" << endl;
            break;
        }
        
        //mudar de jogador
        jogador = (jogador == 'X') ? '0' : 'X';
		
		//verificador de jogada valida
        jogadaValida = false;

        while (!jogadaValida) {
            cout << "JOGADOR " << (jogador == 'X' ? "UM (X)" : "DOIS(0)") << " DIGITE A POSICAO DESEJADA: " << endl << endl;
            cin >> opc;
            cout << endl;
		
			//posicao colocada no tabuleiro
            switch (opc) {
                case '1': if (A1 == '1') { A1 = jogador; jogadaValida = true; } else { cout << "Posicao ja ocupada. Tente novamente." << endl; } break;
                case '2': if (A2 == '2') { A2 = jogador; jogadaValida = true; } else { cout << "Posicao ja ocupada. Tente novamente." << endl; } break;
                case '3': if (A3 == '3') { A3 = jogador; jogadaValida = true; } else { cout << "Posicao ja ocupada. Tente novamente." << endl; } break;
                case '4': if (B1 == '4') { B1 = jogador; jogadaValida = true; } else { cout << "Posicao ja ocupada. Tente novamente." << endl; } break;
                case '5': if (B2 == '5') { B2 = jogador; jogadaValida = true; } else { cout << "Posicao ja ocupada. Tente novamente." << endl; } break;
                case '6': if (B3 == '6') { B3 = jogador; jogadaValida = true; } else { cout << "Posicao ja ocupada. Tente novamente." << endl; } break;
                case '7': if (C1 == '7') { C1 = jogador; jogadaValida = true; } else { cout << "Posicao ja ocupada. Tente novamente." << endl; } break;
                case '8': if (C2 == '8') { C2 = jogador; jogadaValida = true; } else { cout << "Posicao ja ocupada. Tente novamente." << endl; } break;
                case '9': if (C3 == '9') { C3 = jogador; jogadaValida = true; } else { cout << "Posicao ja ocupada. Tente novamente." << endl; } break;
                case 's': cout << "Saida do programa. Adeus!"  << endl; return 0; //saida do programa
                case 'S': cout << "Saida do programa. Adeus!" << endl; return 0;
                default: cout << "Opcao invalida. Tente novamente." << endl; break;
            }
        }

    } while (opc != 'S' && opc != 's');
    
    return 0;
}