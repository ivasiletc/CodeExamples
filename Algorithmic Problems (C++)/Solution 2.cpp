#include <stdio.h>
#include <string.h>

struct Node;
Node* currentNode;

char result[65];
char tmpWord[65];
//Tree
struct Node {
    char value;
    Node* right;
    Node* left;
    Node* parent;

    //Algorhytm
    void search() {
        if (this->left) {
            this->left->search();
        }
        if (this->right) {
            this->right->search();
        }
        else if (!this->left) {
            currentNode = this;
            int i = 0;
            while (currentNode->parent) {
                tmpWord[i] = currentNode->value;
                currentNode = currentNode->parent;
                ++i;
            }
            tmpWord[i] = currentNode->value;
            tmpWord[i + 1] = 0;
            if (strcmp(result, tmpWord) < 0) {
                strncpy(result, tmpWord, 65);
            }
        }
    }
};

int main() {
    char tmpChar;
    char lastChar = getchar_unlocked();

    Node* start = new Node();
    currentNode = start;

    while (tmpChar != EOF) {
        tmpChar = getchar_unlocked();
        if (tmpChar >= 'a' && tmpChar <= 'z') {
            currentNode->value = lastChar;
            currentNode = start;
            lastChar = tmpChar;
        }
        else if (tmpChar == 'R') {
            if (!currentNode->right) {
                currentNode->right = new Node();
                currentNode->right->parent = currentNode;
            }
            currentNode = currentNode->right;
        }
        else if (tmpChar == 'L') {
            if (!currentNode->left) {
                currentNode->left = new Node();
                currentNode->left->parent = currentNode;
            }
            currentNode = currentNode->left;
        }
    }
    currentNode->value = lastChar;
    start->search();

    printf("%s", result);

    return 0;
}