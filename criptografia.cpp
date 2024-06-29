#include <iostream>
#include <string>


using namespace std;

int valorAscii(string mensagem) {
    int valorAscii = 0;
    int pesos[] = {128,64,32,16,8,4,2,1};

    for(int i = 0; i < mensagem.length(); i++) {
        if(mensagem[i] == '1'){
            valorAscii+= pesos[i];
        }
    }
    return valorAscii; 
}

string decodificar(string mensagemSecreta) {
    string sequenciaBits = "";

    for(int i = 0; i < mensagemSecreta.length(); i+=8) {
       string aux =  mensagemSecreta.substr(i,8);
       if(aux[6] == '1'){
            aux[6] = '0';
       }
       else {
            aux[6] = '1';
       }
       if(aux[7] == '1'){
            aux[7] = '0';
       }
       else {
            aux[7] = '1';
       }
       aux = aux.substr(4,4) + aux.substr(0,4);
       sequenciaBits+=aux;
    }
    string mensagemDecodificada = "";
    for(int i = 0; i < sequenciaBits.length();i+=8) {
        char caractere = valorAscii(sequenciaBits.substr(i,8));
        mensagemDecodificada+= caractere;
    }
    return mensagemDecodificada;
}

int main() {

    string mensagemSecreta = "10010110111101110101011000000001000101110010011001010111000000010001011101110110010101110011011011110111110101110101011100000011";
    
    cout << decodificar(mensagemSecreta) << endl;
    return 0;
    
}