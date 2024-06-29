#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main() {

    srand( (unsigned)time(NULL) );

    int vetor1[10];
    int vetor2[10];

    for(int i = 0; i < 10;i++) {
        vetor1[i] = rand() % 201 - 100;
        vetor2[i] = rand() % 201 - 100;
    }

    for(int i = 0; i < 10; i++) {
        cout << vetor1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 10; i++) {
        cout << vetor2[i] << " ";
    }
    cout << endl;
    int menorDiferenca = 100, posicaoVetor1, posicaoVetor2;
    for(int i = 0; i < 10;i++) {
        for(int j = 0; j < 10; j++) {
            if(abs(vetor1[i] - vetor2[j]) < menorDiferenca) {
                menorDiferenca = abs(vetor1[i] - vetor2[j]);
                posicaoVetor1 = i;
                posicaoVetor2 = j;
            }
        }
    }

    cout << "A menor diferença é " << menorDiferenca << endl;
    cout << "São os valores " << vetor1[posicaoVetor1] << " "<< vetor2[posicaoVetor2] << endl;

    return 0;
}