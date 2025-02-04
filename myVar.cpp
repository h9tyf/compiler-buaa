//
// Created by h on 2020/10/20.
//
#include <vector>
#include <string>
#include <stack>
#include "myVar.h"


int transNum(std::string str) {
    int res = 0;
    int i;
    int length = str.length();
    for(i = 0; i < length; i++){
        res = res * 10 + (str[i] - '0');
    }
    return res;
}

std::string myTolower(std::string myStr){
    std::string temp = myStr; //NOLINT
    transform(temp.begin(),temp.end(),temp.begin(),::tolower);
    return temp;
}
void finishCountSpace(){
    globalSigTab[myTolower(func_name)]._spaceCount = spCount;
}

void funcAddSpaceForSp(){
    spCount++;
}

void funcSubSpaceForSp(){
    spCount--;
}

void funcInitialSpaceForSp(){
    spCount = 0;
}

//void addVarToSp(std::string name){
//    varLoc[name] = varDefCount;
//    varDefCount++;
//}

std::string names[50];
std::vector<Word>words;
std::vector<Error>errors;
std::map<std::string, Signal>globalSigTab;
std::map<std::string, Signal>funcSigTab;
std::map<std::string, std::map<std::string, Signal>>funcSigTabMap;

std::ofstream output_error("error.txt");//NOLINT

std::vector<IntermediateCode> intermediateCodes;

//in parse
int loc_f_p;
SYMBOL symbol_p;
std::string name_p;
int line_p;
Signal newSig = Signal();//NOLINT
SIG_SYM prev_type;
bool isGlobal = true;
std::string func_name;//def
std::stack<std::string> call_func_name;//NOLINT
bool hasReturn = false;

//get interCode
IntermediateCode newIntermediateCode;//NOLINT
std::stack<IntermediateCode> ICodesStack;//NOLINT
int regNum = 0;
int expRegNum = 0;
int ifExpIsCon = 0;
int expValue = 0;

//getMIPS
int strCount = 0;
std::map<std::string, int>stringList;
int labelCount = 0;
std::stack<int>endLabelStack;
std::stack<int>labelStack;

std::stack<int>lastICNum;

int spCount = 0;