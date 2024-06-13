//
// Created by AlexGrandbell on 24-6-13.
//

#include "LexicalAnalyzer.h"

//初始化字典和文件路径
LexicalAnalyzer::LexicalAnalyzer() {
    tokenMap ={
            {"begin", 1},
            {"end", 2},
            {"+", 13},
            {"-", 14},
            {"*", 15},
            {"/", 16},
            {";", 17},
            {"=", 18},
            {"<", 19},
            {"<>", 20},
            {"<=", 21},
            {">", 22},
            {">=", 23},
            {"(", 24},
            {")", 25},
            {"#", 26}
    };
    inputFilePath = "testfile.txt";
    outputFilePath = "output.txt";
}

//数字分析
bool LexicalAnalyzer::isNumber(const string &s) {
    regex reg("[0-9]+");
    return regex_match(s, reg);
}

//标识符分析
bool LexicalAnalyzer::isIdentifier(const string &s) {
    regex reg("[a-zA-Z][a-zA-Z0-9]*");
    return regex_match(s, reg);
}

//分析
void LexicalAnalyzer::analyze() {
    ifstream inputFile(inputFilePath);
    ofstream outputFile(outputFilePath);
    if (!inputFile.is_open()||!outputFile.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    string line;
    while (getline(inputFile, line)) {
        int i=0;
        while (i<line.length()){
            if (line[i]=='b'){
                if (line.substr(i,5)=="begin"){
                    outputFile << tokenMap["begin"] << " " << "begin" <<endl;
                    i+=5;
                    continue;
                }
            }
            if(line[i]=='e'){
                if (line.substr(i,3)=="end"){
                    outputFile << tokenMap["end"] << " " << "end" <<endl;
                    i+=3;
                    continue;
                }
            }
            if (tokenMap.find(line.substr(i,2))!=tokenMap.end()){
                outputFile << tokenMap[line.substr(i,2)] << " " << line.substr(i,2) <<endl;
                i+=2;
                continue;
            }
            if (isdigit(line[i])){
                string number;
                while (i < line.length() && isdigit(line[i])) {
                    number += line[i];
                    i++;
                }
                if (isNumber(number)) {
                    outputFile << "11 " << number << endl;
                    continue;
                }
            }
            if(isalpha(line[i])){
                string identifier;
                while (i < line.length() && (isalpha(line[i])||isdigit(line[i]))) {
                    identifier += line[i];
                    i++;
                }
                if (isIdentifier(identifier)) {
                    outputFile << "10 " << identifier << endl;
                    continue;
                }
            }
            if (tokenMap.find(line.substr(i,1))!=tokenMap.end()){
                outputFile<< tokenMap[line.substr(i,1)]<< " " << line[i] <<endl;
                i++;
                continue;
            }
            if (line[i]==' ' || line[i]=='\n'){
                i++;
                continue;
            }
            outputFile << "error" << endl;
            i++;
        }
    }
    inputFile.close();
    outputFile.close();
}