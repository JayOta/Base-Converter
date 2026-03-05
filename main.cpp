#include <cmath>
#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


void convertToBinary(int number){
    int rest;
    vector<int> restArray;
    vector<string> resultArray;
    for(int i = 0; number > 1; i++){

        float rest = number % 2;
        number = number / 2;
        restArray.push_back(rest);
    }
    
    restArray.push_back(number); // number == 1
    cout << "\n";
    cout << "Saída (em Binário): ";
    reverse(restArray.begin(), restArray.end());
    for(int num : restArray){
        cout << num << "";
    }
}
void convertToDecimal(int number){
    cout << "Converting to Decimal..\n";
}

int main() {
    float input;
    char a;
    cout << "Bem vindo ao Conversor entre Binários e Decimais!\n\n";
    cout << "Escolha o tipo de Entrada: 'B'(binario) ou 'D'(decimal): ";
    cin >> a;
    if(a != 'B' || a != 'b' || a != 'D' || a != 'd'){
    while(a != 'B' || a != 'b' && a != 'D' || a != 'd'){
        if(a == 'B' || a == 'b' || a == 'D' || a == 'd'){
            break;
        }
        cout << "Escolha apenas entre: 'B'(binario) ou 'D'(decimal): ";
        cin >> a;
    }
}
    if(toupper(a) == 'B'){
        cout << "Digite a entrada (em Decimal): ";
        cin >> input;
        convertToBinary(input);
    }
    else if(toupper(a) == 'D') {
        cout << "Digite a entrada (em Binario): ";
        cin >> input;
        convertToDecimal(input);
   }
    return 0;
}
