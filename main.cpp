#include <cmath>
#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string reverseElements(int number) {
    string string_number = to_string(number); // transforma em string
    vector<char> array = {}; // cria o array
    int number_size = string_number.length(); // pega o tamanho do número original  
    for(int i = 0 ; i < number_size; i++){
        array.push_back(string_number[i]); // coloca cada número no array de chat
    }

    string numbers = "";
    for(int j = 0; j < array.size(); j++){
            numbers += array[array.size() - (1 + j)];
    }
    return numbers;
}
// int left = array[0]; // esquerda = posição 0
//     int right = array[array.size() - 1]; // direita = posição final
//     for(int j = 0; j < array.size(); j++){ // itera
//         if(array[left] < array[right]){ // enquanto a esquerda for menor que a direita
//             int temp = array[left]; // variavel temporaria
//             array[left] = array[right]; // esquerda = direita
//             array[right] = temp; // direita = esquerda(variavel temporaria)

//             left = array[j];
//             right = array[array.size() - (1 + j)];
//         }

// }
//     string numbers = "";
//     for (int number : array){
//         numbers += number;
//     }

//     return numbers;

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
    string number_string = to_string(number);
    int number_counter = number_string.length();
    for(int i = 0; i < number_counter; i++){

    }

    // Pegar o Tamanho do número binário
    // Contar a quantidade de posições(da direita para esquerda (começando do zero))
    // Pegar o primeiro dígito da direita ->
    // Multiplicar o dígito por (dois elevado a sua posição)
    // Fazer isto com todos os dígitos
    // Fazer a soma entre as multiplicações entre estes números
    // Printar o Número Decimal Final
}
void convertToOctal(){
	cout << "Converting to Octal";    
}

int main() {
    float input;
    char a;
    int numbers;
    cout << "Teste: ";
    cin >> numbers;
    cout << reverseElements(numbers);
//     cout << "Bem vindo ao Conversor entre Binários e Decimais!\n\n";
//     cout << "Escolha o tipo de Entrada: 'B'(binario) ou 'D'(decimal): ";
//     cin >> a;
//     if(a != 'B' || a != 'b' || a != 'D' || a != 'd'){
//     while(a != 'B' || a != 'b' && a != 'D' || a != 'd'){
//         if(a == 'B' || a == 'b' || a == 'D' || a == 'd'){
//             break;
//         }
//         cout << "Escolha apenas entre: 'B'(binario) ou 'D'(decimal): ";
//         cin >> a;
//     }
// }
//     if(toupper(a) == 'B'){
//         cout << "Digite a entrada (em Decimal): ";
//         cin >> input;
//         convertToBinary(input);
//     }
//     else if(toupper(a) == 'D') {
//         cout << "Digite a entrada (em Binario): ";
//         cin >> input;
//         convertToDecimal(input);
//    }
    return 0;
}
