// By HookSandeer

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void print(string text){
    cout << text << endl;
}

void clear(){
    for(int i=0; i<30; i++){
        print("\n");
    }
}

int randomNumber(const int sizeListWord){
    random_device rd;
    uniform_int_distribution<int> dist(0, sizeListWord-1);
    int random = dist(rd);
    return random;
}

string randomWord(){
    vector<string> mots{"avion", "voiture", "lit", "chaise", "ordinateur", "maison"};
    const int listSize = mots.size();
    string word = mots[randomNumber(listSize)];
    return word;
}

char askLetter(){
    char userLetter;
    cout << "Enter une lettre : \n=> ";
    cin >> userLetter;
    clear();
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

bool rightWord(vector<char>& letters, string word){
    const int wordSize = word.size();
    for(int i=0; i<wordSize; i++){
        if(letters[i]!= word[i]){
            return false;
        }
    }
    return true;
}

void display(string word, vector<char> letters, int tryLeft){
    const int wordSize = word.size();
    for(int i=0; i<wordSize; i++){
        if(word[i]==letters[i]){
            cout << word[i] << " ";
        }else{
            cout << "_ ";
        }
        
    }
    cout << "\t\tEssais restant : " << tryLeft << endl;
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
    int userTry = 7;
    string word = randomWord();
    char currentLetter;
    vector<char> userWord(word.size());
    print("Mot a deviner :\n");
    const int wordSize = word.size();
    for(int a=0; a<wordSize; a++){
        cout << "_ ";
    }
    print("\n\n");
    while(userTry != 0){
        currentLetter = askLetter();
        if(letterInWord(currentLetter, word)){
            cout << "La lettre " << currentLetter << " est dans le mot !\n" << endl;
            userWord = addRigtLetter(currentLetter, userWord, word);
            if(rightWord(userWord, word)){
                print("\nFélicitations vous avez trouvé le mot !\n");
                cout << "Il vous restait " << userTry << " essais";
                if(userTry>3){
                    cout << ", pas mal !" << endl;
                }else{
                    cout << ", c'était juste !!" << endl;
                }
                cin.ignore();
                break;
            }
            display(word, userWord, userTry);
        }else{
            userTry --;
            cout << "La lettre " << currentLetter << " n'est pas dans le mot !" << endl;
            display(word, userWord, userTry);
            if(userTry == 0){
                cout << "Vous avez malheureusement perdu, le mot était : " << word << endl;
            }
        }
    }
    return 0;
}