// By HookSandeer

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void print(string text){                        // Permet d'avoir une fonction print comme en python, lorsqu'il faut afficher quelque chose de simple
    cout << text << endl;
}

int randomNumber(const int sizeListWord){       // Génère un nombre aléatoire, entre 0 et la taille de la liste des mots disponible (pas de randint en c++ dommage)
    random_device rd;
    uniform_int_distribution<int> dist(0, sizeListWord-1);
    int random = dist(rd);
    return random;
}

string randomWord(){                            // Renvoie mot aléatoire parmis la liste, utilise la fonction randomNumber
    vector<string> mots{"avion", "voiture", "lit", "chaise", "ordinateur", "maison"};
    const int listSize = mots.size();
    string word = mots[randomNumber(listSize)];
    return word;
}

char askLetter(){                               // Demande et renvoie la lettre que l'utilisateur a entré
    cout << "\n\n----------------------------------------------------------------------\n" << endl;
    char userLetter;
    cout << "Enter une lettre : \n=> ";
    cin >> userLetter;
    return userLetter;
}

bool letterInWord(char letter, string word){            // Renvoie si oui ou non la lettre est dans le mot
    const int wordSize = word.size();
    for(int  i=0; i<wordSize; i++){
        if(word[i]==letter){
            return true;
        }
    }
    return false;
}

bool rightWord(vector<char>& letters, string word){         // Renvoie si oui ou non la liste de lettre forme le mot
    const int wordSize = word.size();
    for(int i=0; i<wordSize; i++){
        if(letters[i]!= word[i]){
            return false;
        }
    }
    return true;
}

void display(string word, vector<char> letters, vector<char> letterUsed, int tryLeft){      // Fonction d'affichage 
    const int wordSize = word.size();
    const int letterUsedSize = letterUsed.size();
    for(int i=0; i<wordSize; i++){
        if(word[i]==letters[i]){
            cout << word[i] << " ";
        }else{
            cout << "_ ";
        }
    }
    cout << "\t\tLettres déjà entrées : ";
    for(int j=0; j<letterUsedSize; j++){
        cout << letterUsed[j] << " / ";
    }
  
    
    cout << "\t\tEssais restant : " << tryLeft << endl;
    print("\n\n");
}

vector<char> addRigtLetter(char letter, vector<char> a, string word){      // Ajoute la lettre juste de l'utilisateur a la bonne place dans la liste
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
    int userTry = 7;                                    // Nombre essais
    string word = randomWord();                         // Mot a deviner
    char currentLetter;                                 // Lettre que l'utilisateur a choisit (initialisation variable)
    vector<char> userWord(word.size());                 // Création liste dynamique de la taille du mot a deviner (pour remplir avec les lettres correct de l'utilisateur)
    vector<char> letterUsed;                            // Création liste dynamique qui va contenir toute les mauvaises lettre de l'utilisateur
    print("Mot a deviner :\n");         
    const int wordSize = word.size();                   // Initialisation de la constante de la taille du mot
    for(int a=0; a<wordSize; a++){                      // Premier affichage console de la taille du mot avec des underscore ( _ )
        cout << "_ ";
    }
    print("\n\n");                                      // Boucle tant que l'utilisateur a encore des essais
    while(userTry != 0){                                
        currentLetter = askLetter();                    // Attribution de la lettre de l'utilisateur a la variable pour chaque tour de boucle
        if(letterInWord(currentLetter, word)){          // Si la lettre est dans le mot a trouver :
            cout << "La lettre " << currentLetter << " est dans le mot !\n" << endl;
            userWord = addRigtLetter(currentLetter, userWord, word);        // On ajoute la lettre juste a la liste des lettres utilisateurs (a la bonne place)
            if(rightWord(userWord, word)){                                  // Si toute les lettres de l'utilisateur correspondent aux mot alors :
                print("\nFélicitations vous avez trouvé le mot !\n");
                cout << "Il vous restait " << userTry << " essais";         // Affichage du nombre d'essais restant
                if(userTry>3){
                    cout << ", pas mal !" << endl;
                }else{
                    cout << ", c'était juste !!" << endl;
                }
                cin.ignore();
                break;                                                      // On arrête la boucle
            }
            display(word, userWord, letterUsed,userTry);                    // Si le mot n'est pas complet, alors on affiche les lettres a leur bonne placce
        }else{
            userTry --;                                                     // Si la lettre est fausse, alors on soustrait 1 aux nombres d'essais
            cout << "La lettre " << currentLetter << " n'est pas dans le mot !" << endl;
            letterUsed.push_back(currentLetter);                            // On ajoute la mauvaise lettre a la liste des lettres déjà entré
            display(word, userWord, letterUsed, userTry);                   // On affiche avec le nombre d'essais et la mauvaise lettre
            if(userTry == 0){                                               // Si il a plus de vie on affiche le message et la boucle s'arretera
                cout << "Vous avez malheureusement perdu, le mot était : " << word << endl;
            }
        }
    }
    return 0;
}