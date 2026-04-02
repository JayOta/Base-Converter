#include <cmath>
#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

string OldInversedNumber(int number) {
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

vector<int> inversedNumber(vector<int> array) {
    int left = 0; // Só "0" pois servirá como (ponteiro do array/índice)
    int right = array.size() - 1; // Só "array.size() - 1" pois servirá como (ponteiro do array/índice)
    while(left < right){ // Enquanto ponteiro da esquerda for menor que ponteiro da direita 
        char temp = array[left]; // var temporária = ponteiro da esquerda
        array[left] = array[right]; // ponteiro da esquerda = ponteiro da direita
        array[right] = temp; // ponteiro da direita igual a "var temporária" => (ponteiro da esquerda)

        left++; // Ponteiro da esquerda avança uma posição
        right--; // Ponteiro da direita volta uma posição
    }
    return array;
    }
    

vector<int> inversedNumber(int number) {
    string string_number = to_string(number);
    vector<char> array = {};
    int number_size = string_number.length();
    for(int i = 0; i < number_size; i++){
        array.push_back(string_number[i]);
    }


        int left = 0; // Só "0" pois servirá como (ponteiro do array/índice)
        int right = array.size() - 1; // Só "array.size() - 1" pois servirá como (ponteiro do array/índice)
        while(left < right){ // Enquanto ponteiro da esquerda for menor que ponteiro da direita 
            char temp = array[left]; // var temporária = ponteiro da esquerda
            array[left] = array[right]; // ponteiro da esquerda = ponteiro da direita
            array[right] = temp; // ponteiro da direita igual a "var temporária" => (ponteiro da esquerda)

            left++; // Ponteiro da esquerda avança uma posição
            right--; // Ponteiro da direita volta uma posição
        }

        vector<int> numbers = {};
        for(char number : array){
            numbers.push_back(number - '0'); // (number - '0') => "Tira a diferença entre o valor ASCII e o número real" 
        }
    
    return numbers;
    }






    void convertToDecimal(int number){
    cout << "Convertendo para Decimal..\n";
    string number_string = to_string(number); // Converte o número para string
    int number_counter = number_string.length(); // Contador de tamanho do número original
    vector<int> inversed_number = inversedNumber(number); // Transforma o número em um array de int
    vector<int> final_sum = {}; // Criado para fazer as somas finais
    int current_number = 0;
    for(int i = 0; i < number_counter; i++){
        current_number = inversed_number[i] * ((int)pow(2, i)); // Pega o número original da direita e multiplica por ("dois"(formato binárop) elevado a sua posição)
        final_sum.push_back(current_number); // Adiciona esse resultado ao array da soma final
    }
    string visual_numbers = "";
    vector<int> final_sum_inverted = inversedNumber(final_sum);
    int array_size = static_cast<int>(final_sum_inverted.size());
    for(int j = 0; j < array_size; j++){
        cout << "Números a serem somados: ";
        cout << "[";
        for(int k = 0; k <= j; k++){ // (j = 0, k = 0) -> [0]; (j = 1, k = 0..1) -> [0,1]..  
            if(k == j){ // Se o elemento atingir a (posição final) => "j" ->  
                cout << final_sum_inverted[k]; // Imprime apenas o elemento
            } else { // Caso (haja mais elementos após ele) => "k < j"
                cout << final_sum_inverted[k] << ","; // Imprime o elemento com uma vírgula a frente
            }
        }
        cout << "]\n\n"; // Fecha os colchetes e quebra uma linha e pula outra
    }
    
    int decimal_number = 0; // Número decimal final
    for(int number : final_sum) { // Para cada número do array da soma final ->
        decimal_number += number; // Soma ele com o valor do Número Decimal Final
    }

    cout << "Número Binário convertido em: " << decimal_number; // Imprime o Número Convertido para Decimal

    // Pegar o Tamanho do número binário
    // Contar a quantidade de posições(da direita para esquerda (começando do zero))
    // Pegar o primeiro dígito da direita ->
    // Multiplicar o dígito por (dois elevado a sua posição)
    // Fazer isto com todos os dígitos
    // Fazer a soma entre as multiplicações entre estes números
    // Printar o Número Decimal Final
}

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

void convertToOctal(){
	cout << "Converting to Octal";    
}

struct Options {
    string type;
    vector<string> value;
    vector<string> initials_letters;

    void setInitialLetters(vector<char> value){
        this.initials_letters = value;    
}
    vector<string> getInitialLetters() {
            if(initials_letters){
                return initials_letters;
        }   else {
                return "Falta de inicialização de variável: initials_letters";   
        }
    }
};

bool verifyInput(bool input){
    bool correct_answer;
    for(char letter : getInitialLetters()) {
        if(input != letter){
            correct_answer = false;
        } else {
            correct_answer = true;
        }
    }
    return correct_answer;
}

int main() {
    float input;
    char a;
    unordered_map<string, string> options;
    options["Binario" || "binario"] = 'B', 'b';
    options["Decimal" || "decimal"] = 'D', 'd';
    options["Octal" || "octal"] = 'O', 'o';
    
    // Criar uma forma de pegar só os option.value;
    // setInitialLetters({'B', 'b', 'D', 'd', 'O', 'o'}); // Fazer com que pegue da options.value
    cout << "Bem vindo ao Conversor entre Binários e Decimais!\n\n";
    cout << "Escolha o tipo de Entrada: ";

    for(int i = 0; i < options.size() - 1; i++){ // "Binario", "Decimal", "Octal"
        for(int j = 0; j < options[i].size() - 1; j++){ // "Binario['B','b']", "Decimal['D', 'd']"..
            if(i == options.size() - 1){ // Se for a última palavra (ex: 'Octal') ->
                cout << "'" << options[i][j] << "'" << "(" << options[i] << "): "; // Imprime: ('O'(Octal):)
            }
            else if(j == 0){ // Pega as letras maiúsculas => array[0] => 'B', 'D', 'O'
                cout << "'" << options[i][j] << "'" << "(" << options[i] << "), "; // Imprime: 'B'(Binario), 'D'(Decimal),
            }
        }
    }
    // cout << "Escolha o tipo de Entrada: 'B'(binario), 'D'(decimal),'O'(Octal): "; 
    cin >> a;
    bool verified = verifyInput(a);
    if(!verified){
        while(!verified){
            cout << "Escolha apenas entre: 'B'(binario) ou 'D'(decimal): ";
            cin >> a;
            verified = verifyInput(a);
            if(verified){
                break;
            }
        }
    } else{
        if(a == 'B' || a == 'b'){
        cout << "Digite a entrada (em Binário): ";
        cin >> input;
        convertToDecimal(input);
    }
    else if(a == 'D' || a == 'd') {
        cout << "Digite a entrada (em Decimal): ";
        cin >> input;
        convertToBinary(input);
    }
    else if(a == 'O' || a == 'o') {
        cout << "Digite a entrada (em Decimal): ";
        cin >> input;
        convertToBinary(input);
    }        
     }

//     if(a != 'B' && a != 'b' && a != 'D' && a != 'd'){
//     while(a != 'B' && a != 'b' && a != 'D' && a != 'd'){
//         cout << "Escolha apenas entre: 'B'(binario) ou 'D'(decimal): ";
//         cin >> a;
//         if(a == 'B' || a == 'b' || a == 'D' || a == 'd'){
//             break;
//         }
//     }
// } else {
//     if(a == 'B' || a == 'b'){
//         cout << "Digite a entrada (em Binário): ";
//         cin >> input;
//         convertToDecimal(input);
//     }
//     else if(a == 'D' || a == 'd') {
//         cout << "Digite a entrada (em Decimal): ";
//         cin >> input;
//         convertToBinary(input);
//     }
//     else if(a == 'O' || a == 'o') {
//         cout << "Digite a entrada (em Decimal): ";
//         cin >> input;
//         convertToBinary(input);
//     }
//    }
    return 0;
}
