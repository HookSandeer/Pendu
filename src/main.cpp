// By HookSandeer

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void print(string text){
    cout << text << endl;
}

string sInput(string text){
    string input;
    cout << text;
    getline(cin, input);
    return input;
}

int iInput(string text){
    int input;
    cout << text;
    cin >> input;
    return input;
}

void clean(){
    for(int i=0; i<50; i++){
        print("\n");
    }
}

int randomNumber(){
    int random = rand()%6;
    return random;
}

string randomWord(){
    vector<string> mots{"avion", "voiture", "lit", "chaise", "ordinateur", "maison"};
    string word = mots[randomNumber()];
    return word;
}

char askLetter(){
    char userLetter;
    cout << "Enter une lettre : \n=> ";
    cin >> userLetter;
    return userLetter;
}

bool letterInWord(char letter, string word){
    const int wordSize = word.size();
    for(int  i=0; i<wordSize; i++){
        if(word[i]==letter){
            return true;
        }
    }
    return false;
}

bool rightWord(const vector<char> letters, string word){
    const int wordSize = word.size();
    const int letterListSize = letters.size();
    if(wordSize != letterListSize){
        return false;
    }
    for(int i=0; i<wordSize; i++){
        if(letters[i]!=word[i]){
            return false;
        }
    }
    return true;
}

void display(string word, vector<char> letters){
    const int wordSize = word.size();
    for(int i=0; i<wordSize; i++){
        if(word[i]==letters[i]){
            cout << word[i] << " ";
        }else{
            cout << "_ ";
        }
    }
    print("\n\n");
}

vector<char> addRigtLetter(char letter, vector<char> a, string word){
    const int wordSize = word.size();
    for(int i=0; i<wordSize; i++){
        if(letter==word[i]){
            a[i] = letter;
        }
    }
    return a;
}

int main(){
    print("Bienvenu dans le jeu du pendu !\n\n");
    int userTry = iInput("Entrer le nombre d'essais que vous souhaitez : ");
    string word = randomWord();
    char currentLetter;
    print(word);
    vector<char> userWord(word.size());
    bool win = false;
    print("Mot a deviner :\n");
    const int wordSize = word.size();
    for(int a=0; a<wordSize; a++){
        cout << "_ ";
    }
    print("\n\n\n");
    while(win == false || userTry != 0){
        currentLetter = askLetter();
        if(rightWord(userWord, word)){
            win = true;
        }if(letterInWord(currentLetter, word)){
            cout << "La lettre " << currentLetter << " est dans le mot !\n" << endl;
            userWord = addRigtLetter(currentLetter, userWord, word);
            display(word, userWord);
        }else{
            userTry --;
            print("\nCette lettre n'est pas dans le mot !");
            display(word, userWord);
            cout << "Il vous reste maintenant " << userTry << " essais !" << endl;
        }
    }
    return 0;
}