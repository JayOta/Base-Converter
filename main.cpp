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

vector<int> inversedNumberVecInt(vector<int> array) {
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
    
vector<char> inversedNumberStr(string number) {
    // string string_number = to_string(number);
    vector<char> array = {};
    int number_size = number.length();
    for(int i = 0; i < number_size; i++){
        array.push_back(number[i]);
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

        vector<char> numbers = {};
        for(char number : array){
            numbers.push_back(number - '0'); // (number - '0') => "Tira a diferença entre o valor ASCII e o número real" 
        }
    
    return numbers;
    }

void getGroups(vector<vector<char>> groups){
    int j = 0; // "j" -> conta a quantidade de grupos
    for(const auto& group : groups) {
        int i = 0; // "i" -> conta os numeros printados num grupo
        cout << "group " << j + 1 << ": ["; // group ?: [
        for(char number : group) { // para cada numero no group
            if(i == group.size() - 1){ // se a contagem chegar no ultimo numero ->
                cout << number; // printa apenas o ultimo numero
            } else {
                cout << number << ","; // se a contagem nao estiver no ultimo numero, printa ele com virgula
                i++; // soma um na contagem de numeros
            }
        }
        cout << "]\n"; // fecha a representacao visual do grupo
        j++; // soma um na contagem de grupos
    }
}

vector<vector<char>> divideIntoGroups(string numbers, int groupSize) {
    vector<vector<char>> groups;
    vector<char> group;
    for(size_t i = 0; i < numbers.size(); i++){ // 0 1 0 1 0 1 0 1 0 1
            group.push_back(numbers[i]); // 1 => 9
            if (group.size() == groupSize){
                    groups.push_back(group); // groups = {{0,1,0}, {1,0,1}, {0,1,0} }
                    group.clear();
                }
    }
    // O que eu faco quando sobra 1 ou 2 numeros? "group = {1}" || "group = {1,0}"
    // Se o group tiver algo, adiciona ele ao groups
    if(group.size() > 0) {
        groups.push_back(group);
    }
    
    // getGroups(group, groups); // mostra cada group de um vetor de vetores
    return groups;
}

vector<int> stringToVecInt(string string_numbers) {
    vector<int> vec_int_numbers;

    for(size_t i = 0; i < string_numbers.size(); i++){
        vec_int_numbers.push_back(string_numbers[i] - '0');
    }
    
    return vec_int_numbers;
}

string vecIntToString(vector<int> array) {
    string string_numbers = "";

    for(size_t i = 0; i < array.size(); i++){
        char digito = array[i] + '0';

        string_numbers += digito;
    }

    return string_numbers;
}

void decimalToOctal(string number){
	cout << "Converting to Octal..";
}

void octalToDecimal(string number){
    cout << "Convertendo para Decimal..\n";
    // string number_string = to_string(number); // Converte o número para string
    int number_counter = number.length(); // Contador de tamanho do número original
    vector<int> inversed_number = inversedNumberVecInt(stringToVecInt(number)); // Transforma o número em um array de int
    vector<int> final_sum = {}; // Criado para fazer as somas finais
    int current_number = 0;
    for(int i = 0; i < number_counter; i++){
        current_number = inversed_number[i] * ((int)pow(8, i)); // Pega o número original da direita e multiplica por ("dois"(formato binárop) elevado a sua posição)
        final_sum.push_back(current_number); // Adiciona esse resultado ao array da soma final
    }
    string visual_numbers = "";
    vector<int> final_sum_inverted = inversedNumberVecInt(final_sum);
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

    cout << "Número Octal convertido em: " << decimal_number << "\n"; // Imprime o Número Convertido para Decimal

}

void octalToBinary(string number){
    cout << "Converting to Binary..";
}

void binaryToDecimal(string number){
    cout << "Convertendo para Decimal..\n";
    // string number_string = to_string(number); // Converte o número para string
    int number_counter = number.length(); // Contador de tamanho do número original
    vector<int> inversed_number = inversedNumberVecInt(stringToVecInt(number)); // Transforma o número em um array de int
    vector<int> final_sum = {}; // Criado para fazer as somas finais
    int current_number = 0;
    for(int i = 0; i < number_counter; i++){
        current_number = inversed_number[i] * ((int)pow(2, i)); // Pega o número original da direita e multiplica por ("dois"(formato binárop) elevado a sua posição)
        final_sum.push_back(current_number); // Adiciona esse resultado ao array da soma final
    }
    string visual_numbers = "";
    vector<int> final_sum_inverted = inversedNumberVecInt(final_sum);
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

    cout << "Número Binário convertido em: " << decimal_number <<  "\n" ; // Imprime o Número Convertido para Decimal
}

void binaryToOctal(string binary_number){
    cout << "Converting to Octal..";
    
    // pega o "array" tipo string de numeros binarios, converte ele para umt vetor int, e o inverte - Completed
    vector<int> inversed_binary = inversedNumberVecInt(stringToVecInt(binary_number));
    
    // divide em grupos de 3 - Completed
    string inversed_binary_numbers = vecIntToString(inversed_binary);
    
    //
    vector<vector<char>> groups = divideIntoGroups(inversed_binary_numbers, 3);
    
    //
    getGroups(groups);


    // faz a conversao de cada grupo para decimal
    // inverte a ordem dos numeros decimais
    // junta os resultados e printa
}

void decimalToBinary(string number){
    int rest; // valor do resto
    vector<int> restArray; // armazena o resto
    vector<string> resultArray; // armazena o resultado

    int integer_number = stoi(number); // transforma a string de numeros em int

    for(int i = 0; integer_number > 1; i++){ // para cada elemento do input

        float rest = integer_number % 2; // Pega o resto entre a divisão do input e a "base"(2)
        integer_number = integer_number / 2; // Transforma o input no resultado da sua divisão e a "base"(2)
        restArray.push_back(rest); // Pega o resta dessa divisão do input e a base e armazena 
    }
    
    restArray.push_back(integer_number); // No final ele pega o número que sobrou no quociente
    cout << "\n"; // Quebra uma linha
    cout << "Saída (em Binário): "; // Mensagem
    reverse(restArray.begin(), restArray.end()); // Inverte o array que está com os números que sobraram e do último quociente
    for(int num : restArray){ // Para cada valor do array invertido
        cout << num << ""; // Printa cada número
    }
    cout << "\n";
}

bool verifyInput(char input, unordered_map<string, vector<char>> initial_letters){

    for(auto const& [key, value] : initial_letters){
        for(char val : value){
            if(input == val){
                return true; // Encontrou algum? -> Já retorna true automaticamente
            } 
        }
    }
    return false;
}



string input(char answer){
    string input; // <- Trocar o tipo para char
    switch(answer){
        case 'B': // Sem "break" o código automaticamente para o próximo statement
        case 'b':
            cout << "Digite a entrada (em Binário): ";
            cin >> input;
            return input; // string
            break;
        case 'D':
        case 'd':
            cout << "Digite a entrada (em Decimal): ";
            cin >> input;
            return input; // string
            break;
        case 'O':
        case 'o':
            cout << "Digite a entrada (em Octal): ";
            cin >> input;
            return input; // string
            break;
    }
    return 0;
}

char input_question(char answer){
    unordered_map<string, vector<char>> options;
    
    options["Binario"] = {'B', 'b'};
    options["Decimal"] = {'D', 'd'};
    options["Octal"] = {'O', 'o'};

    cout << "Bem vindo ao Conversor de Bases!\n\n";
    cout << "Escolha o tipo de Entrada: ";
    


    int i = 0;
    while(i < options.size() - 1){ // Options -> 3 elementos -> size = 4 -> size real = "3" => (size() - 1)
        for(auto const& [key, val] : options){
            if(i == options.size() - 1){
                cout << "'" << val[0] << "'" << "(" << key << "): ";
                break;     
            } else {
                cout << "'" << val[0] << "'" << "(" << key << "),";
                i++;
            }
        }
    }

    cin >> answer;
    bool verified = verifyInput(answer, options);
    if(!verified){
        while(!verified){
            cout << "Escolha apenas entre: 'B'(binario) ou 'D'(decimal): "; // Automatizar escolhas
            cin >> answer;
            verified = verifyInput(answer, options);
            if(verified){
                break;
            }
        }
    }

    return toupper(answer);
}

char output_question(char answer){
    unordered_map<string, vector<char>> options;
    options["Binario"] = {'B', 'b'};
    options["Decimal"] = {'D', 'd'};
    options["Octal"] = {'O', 'o'};

    cout << "Escolha o tipo de Saída -> ";

    int i = 0;
    while(i < options.size() - 1){ // Options -> 3 elementos -> size = 4 -> size real = "3" => (size() - 1)
        for(auto const& [key, val] : options){
            if(i == options.size() - 1){
                cout << "'" << val[0] << "'" << "(" << key << "): ";
                break;
            } else {
                cout << "'" << val[0] << "'" << "(" << key << "),";
                i++;
            }
        }
    }

    cin >> answer;
    bool verified = verifyInput(answer, options);
    if(!verified){
        while(!verified){
            cout << "Escolha apenas entre: 'B'(binario) ou 'D'(decimal): "; // Automatizar escolhas
            cin >> answer;
            verified = verifyInput(answer, options);
            if(verified){
                break;
            }
        }
    }
    return toupper(answer);
}


int main() {
    char answer_1, answer_2; // Declaradas vazias, mas outros valores serão atribuidos a elas dentro das funções
    answer_1 = input_question(answer_1);
    answer_2 = output_question(answer_2);
    string input_answer = input(answer_1);

    if(answer_1 == 'B' && answer_2 == 'D') {
        binaryToDecimal(input_answer);
    } else if(answer_1 == 'D' && answer_2 == 'B'){
        decimalToBinary(input_answer);
    } else if(answer_1 == 'B' && answer_2 == 'O'){
        // binaryToOctal(input_answer);
        divideIntoGroups(input_answer, 3);
    } else if(answer_1 == 'O' && answer_2 == 'B'){
        octalToBinary(input_answer);
    } else if(answer_1 == 'D' && answer_2 == 'O'){
        decimalToOctal(input_answer);
    } else if(answer_1 == 'O' && answer_2 == 'D'){
        octalToDecimal(input_answer);
    }

    return 0;
}