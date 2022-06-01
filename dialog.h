#pragma once
#include "spot.h"
#include <string>

enum CASE {
    MAIN_MENU,
    SELECT_AREA,
    SELECT_THEME,
    SUGGEST_EVALUATION,
    CHECK_NEED_MORE,
    NOT_IMPLEMENTED,
};
class Dialog {
    public:
        void printMenu(int case_num);
        void printSuggestion(Spot* spot);
        void printShareInfo(Spot* spot);
        int getSingleChoice();
        string getMultiChoice();
        vector<string> parseChoice(int case_num, string choice);
    private:
        vector<string> getWordTbl(int case_num);
};