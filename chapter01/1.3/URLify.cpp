/*
 * Chapter 1: Arrays and Strings
 * -----------------------------
 *
 * Problem: URLify
 * Write a method to replace all spaces in a string with `%20`. You main assume 
 * that the string has sufficient space at the end to hold the additional 
 * characters, and that you are given the "true" length of the string. 
 * (Note: If implementing in Java,  please use a character array so that you can 
 * perform this operation in place.)
 *
 * Example:
 * Input:   "Mr John Smith      ", 13
 * Output:  "Mr%20John%20Smith"
 */
#include <iostream>
#include <string>
using namespace std;

void urlify(char *word, int len) {
    int spaceCounts = 0;
    for (int i = 0; i < len; i++) {
        if (word[i] == ' ') {
            spaceCounts++;
        }
    }

    int extendedLen  = len + 2 * spaceCounts;
    int i = extendedLen - 1;
    for (int j = len-1; j >= 0; j--) {
        if (word[j] != ' ') {
            word[i--] = word[j];
        } else {
            word[i--] = '0';
            word[i--] = '2';
            word[i--] = '%';
        }
    }
}

int main() {
    char str[] = "Mr John Smith    ";                       
    cout << "Actual string   : " << str << endl;
    urlify(str, 13);
    cout << "URLified string : " << str << endl;

    return 0;
}