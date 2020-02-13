#include <stdio.h>
#include <string.h>

struct Uzel;

Uzel* aktualnyUzel;

char result[65];
char tmpSlowo[65];
//Tree
struct Uzel {
    char value;
    Uzel* right;
    Uzel* left;
    Uzel* parent;

    //Algorhytm
    void search() {
        if (this->left) {
            this->left->search();
        }
        if (this->right) {
            this->right->search();
        }
        else if (!this->left) {
            aktualnyUzel = this;
            int i = 0;
            while (aktualnyUzel->parent) {
                tmpSlowo[i] = aktualnyUzel->value;
                aktualnyUzel = aktualnyUzel->parent;
                ++i;
            }
            tmpSlowo[i] = aktualnyUzel->value;
            tmpSlowo[i + 1] = 0;
            if (strcmp(result, tmpSlowo) < 0) {
                strncpy(result, tmpSlowo, 65);
            }
        }
    }
};

int main() {
    char tmpChar;
    char lastChar = getchar_unlocked();

    Uzel* start = new Uzel();
    aktualnyUzel = start;

    while (tmpChar != EOF) {
        tmpChar = getchar_unlocked();
        if (tmpChar >= 'a' && tmpChar <= 'z') {
            aktualnyUzel->value = lastChar;
            aktualnyUzel = start;
            lastChar = tmpChar;
        }
        else if (tmpChar == 'R') {
            if (!aktualnyUzel->right) {
                aktualnyUzel->right = new Uzel();
                aktualnyUzel->right->parent = aktualnyUzel;
            }
            aktualnyUzel = aktualnyUzel->right;
        }
        else if (tmpChar == 'L') {
            if (!aktualnyUzel->left) {
                aktualnyUzel->left = new Uzel();
                aktualnyUzel->left->parent = aktualnyUzel;
            }
            aktualnyUzel = aktualnyUzel->left;
        }
    }
    aktualnyUzel->value = lastChar;
    start->search();

    printf("%s", result);

    return 0;
}