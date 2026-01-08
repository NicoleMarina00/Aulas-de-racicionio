#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Dimensões do tabuleiro e quantidade de minas
const int LINHAS = 8;
const int COLUNAS = 8;
const int NUM_MINAS = 10;

// Célula
struct Celula {
    bool temMina = false;
    bool revelada = false;
    int minasVizinhas = 0;
};

using Tabuleiro = vector<vector<Celula>>;

// Verifica se as coordenadas
bool dentroDoTabuleiro(int x, int y) {
    return x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS;
}

// Inicializa o tabuleiro vazio
void inicializarTabuleiro(Tabuleiro& tabuleiro) {
    tabuleiro = Tabuleiro(LINHAS, vector<Celula>(COLUNAS));
}

// Coloca minas aleatórias
void colocarMinas(Tabuleiro& tabuleiro) {
    int colocadas = 0;
    while (colocadas < NUM_MINAS) {
        int x = rand() % LINHAS;
        int y = rand() % COLUNAS;
        if (!tabuleiro[x][y].temMina) {
            tabuleiro[x][y].temMina = true;
            colocadas++;
        }
    }
}

// Conta minas vizinhas
void calcularMinasVizinhas(Tabuleiro& tabuleiro) {
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            if (tabuleiro[i][j].temMina) continue;

            int count = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int ni = i + dx;
                    int nj = j + dy;
                    if ((dx != 0 || dy != 0) && dentroDoTabuleiro(ni, nj) && tabuleiro[ni][nj].temMina)
                        count++;
                }
            }
            tabuleiro[i][j].minasVizinhas = count;
        }
    }
}

void revelarCelula(Tabuleiro& tabuleiro, int x, int y) {
    if (!dentroDoTabuleiro(x, y) || tabuleiro[x][y].revelada)
        return;

    tabuleiro[x][y].revelada = true;

    if (tabuleiro[x][y].minasVizinhas == 0 && !tabuleiro[x][y].temMina) {
        for (int dx = -1; dx <= 1; ++dx)
            for (int dy = -1; dy <= 1; ++dy)
                if (dx != 0 || dy != 0)
                    revelarCelula(tabuleiro, x + dx, y + dy);
    }
}

// Tabuleiro na tela
void imprimirTabuleiro(const Tabuleiro& tabuleiro, bool mostrarMinas = false) {
    cout << "   ";
    for (int j = 0; j < COLUNAS; ++j) cout << j << " ";
    cout << "\n";

    for (int i = 0; i < LINHAS; ++i) {
        cout << i << " ";
        if (i < 10) cout << " ";
        for (int j = 0; j < COLUNAS; ++j) {
            if (tabuleiro[i][j].revelada) {
                cout << tabuleiro[i][j].minasVizinhas << " ";
            } else if (mostrarMinas && tabuleiro[i][j].temMina) {
                cout << "* ";
            } else {
                cout << "X ";
            }
        }
        cout << "\n";
    }
}

// Verifica se o jogador venceu
bool verificarVitoria(const Tabuleiro& tabuleiro) {
    for (int i = 0; i < LINHAS; ++i)
        for (int j = 0; j < COLUNAS; ++j)
            if (!tabuleiro[i][j].revelada && !tabuleiro[i][j].temMina)
                return false;
    return true;
}

// Jogada do jogador
bool processarJogada(Tabuleiro& tabuleiro, int x, int y) {
    if (!dentroDoTabuleiro(x, y)) {
        cout << " Coordenadas inválidas. Tente novamente.\n";
        return false;
    }

    if (tabuleiro[x][y].temMina) {
        imprimirTabuleiro(tabuleiro, true);
        cout << "\n Você acertou uma mina! Game Over!\n";
        return true;
    }

    revelarCelula(tabuleiro, x, y);

    if (verificarVitoria(tabuleiro)) {
        imprimirTabuleiro(tabuleiro);
        cout << "\n Parabéns! Você venceu o jogo!\n";
        return true;
    }

    return false;
}

// Função principal do jogo
int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios

    Tabuleiro tabuleiro;
    inicializarTabuleiro(tabuleiro);
    colocarMinas(tabuleiro);
    calcularMinasVizinhas(tabuleiro);

    bool fimDeJogo = false;

    while (!fimDeJogo) {
        imprimirTabuleiro(tabuleiro);
        int x, y;
        cout << "\nDigite as coordenadas (linha e coluna): ";
        cin >> x >> y;

        fimDeJogo = processarJogada(tabuleiro, x, y);
    }

    return 0;
}