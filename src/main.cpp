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
    cout << text << endl;
    getline(cin, input);
    return input;
}

int iInput(string text){
    int input;
    print(text);
    cin >> input;
    return input;
}

void clean(){
    for(int i=0; i<50; i++){
        print("\n");
    }
}

void display(int size, int tryLeft){
    print("Entrer votre lettre en minuscule :");
    print("Mot a trouver :\n\n");
    for(int i=0; i<size; i++){
        cout << "_ ";
    }
    print("\n\n\n");
    cout << "Il vous reste " << tryLeft << " essais." << endl;
}

int randomNumber(){
    int random = rand()%6;
    return random;
}

string randomWord(){
    vector<string> mots{"avion", "voiture", "lit", "chaise", "ordinateur", "maison"};
    string word = mots[randomNumber()];
}

char askLetter(){
    char userLetter;
    cout << "Enter une lettre : \n=> " << endl;
    cin >> userLetter;
    return userLetter;
}

bool letterInWord(char letter, string word){
    const int wordSize = word.size();
    for(int  i=0; i<wordSize; i++){
        if(word[i]==letter){
            return true;
        }else{
            return false;
        }
    }
}

int main(){
    print("Bienvenu dans le jeu du pendu !\n\n");
    int userTry = iInput("Entrer le nombre d'essais que vous souhaitez :");
    string word = randomWord();
    vector<char> findLetter;
    const int wordSize = word.size();
    bool win = false;
    while(win == false || userTry != 0){
        char currentLetter = askLetter();
        if(letterInWord(currentLetter, word)){
            cout << "La lettre " << currentLetter << " est dans le mot !" << endl;
            findLetter.insert(findLetter.end(), currentLetter);
        }else{
            userTry --;
            print("\nCette lettre n'est pas dans le mot !");
            cout << "Il vous reste maintenant " << userTry << " essais restant !" << endl;
        }
    }
    return 0;
}