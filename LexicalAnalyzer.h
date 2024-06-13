//
// Created by AlexGrandbell on 24-6-13.
//

#ifndef LEXICALANALYSIS_LEXICALANALYZER_H
#define LEXICALANALYSIS_LEXICALANALYZER_H

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <unordered_map>

using namespace std;

class LexicalAnalyzer {
private:
    unordered_map<string, int> tokenMap;
    bool isNumber(const string &s);//数字正则匹配
    bool isIdentifier(const string &s);//标识符正则匹配

    string inputFilePath;
    string outputFilePath;
public:
    LexicalAnalyzer();
    void analyze();
};


#endif //LEXICALANALYSIS_LEXICALANALYZER_H
