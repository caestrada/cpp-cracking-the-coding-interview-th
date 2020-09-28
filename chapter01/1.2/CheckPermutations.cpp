/*
 * Chapter 1: Arrays and Strings
 * -----------------------------
 *
 * Problem: Check Permutations
 * Given two strings, write a method to decide if one is a permutation of the 
 * other.
 * Hints: #1, #84, #122, #131
 * 
 * #1: Describe what it means for two strings to be permutations of each other. 
 * Now, look at that definition you provided. Can you check the strings against
 * that definition?
 * In this context a permutation is a variation of characters in a different 
 * order from the original.
 */
#include <iostream>
#include <vector>
using namespace std;

bool checkPermutation(string word1, string word2) {
    // If size don't match then it's not a permutation.
    if (word1.length() != word2.length()) {
        return false;
    }

    // If words are equals then it's not a permutation.
    if (word1 == word2) {
        return false;
    }

    int count[128] = {0};
    for (int i=0; i<word1.length(); i++) {
        int character = word1[i];
        count[character]++;
    }

    for (int i=0; i<word2.length(); i++) {
        int character = word2[i];
        count[character]--;

        if (count[character] < 0)
            return false;
    }

    return true;
}

int main() {
    string word1 = "abc";
    string word2 = "123";
    cout << "Check Permutations (" << word1 << ", " << word2 << "): " << boolalpha << checkPermutation(word1, word2) << endl;

    word1 = "abc";
    word2 = "abc";
    cout << "Check Permutations (" << word1 << ", " << word2 << "): " << boolalpha << checkPermutation(word1, word2) << endl;


    word1 = "abc";
    word2 = "cba";
    cout << "Check Permutations (" << word1 << ", " << word2 << "): " << boolalpha << checkPermutation(word1, word2) << endl;
    return 0;
}
