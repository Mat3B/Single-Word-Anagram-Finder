/*
 * Name: Mathew Breland
 * Date Submitted: 3/5/2023
 * Assignment Name: Single-Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

//

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if (inFile.is_open())
    {
        while (getline(inFile, word))
        {
            if (word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist) {

    vector<string> result;

    // this is in include algorithm
    sort(word.begin(), word.end());                 // sort the letters of the input word

    for (const auto& wordIt : wordlist) {           // iterating over each word in the list 

        string sortedWord = wordIt;                 // creating a string that is the sorted word and setting it equal to the iterator
        sort(sortedWord.begin(), sortedWord.end()); // sort the letters of the word in the list 

        if (sortedWord == word) {

            result.push_back(wordIt);               // pushing back the word if it is an anagram

        }
    }

    return result;  // returning the result 
}