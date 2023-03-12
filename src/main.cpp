// By HookSandeer

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void print(string text){
    cout << text << endl;
}

int iInput(string text){
    int input;
    print(text);
    cin >> input;
    return input;
}

int randomNumber(){
    int random = rand()%6;
    return random;
}

string randomWord(){
    vector<string> mots{"avion", "voiture", "lit", "chaise", "ordinateur", "maison"};
    string word = mots[randomNumber()];
}


int main(){
    string word = randomWord();
    return 0;
}