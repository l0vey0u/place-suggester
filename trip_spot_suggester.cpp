#include "dialog.h"
#include "data_parser.h"
#include "spot.h"
#include "spot_finder.h"
#include <iostream>
#include <cstdlib>
#include <vector> 

int main(void) {
    Dialog dialog;
    DataParser dataParser;
    SpotFinder spotFinder = SpotFinder(dataParser.getSpotListFromFile());
    string input;
    vector<string> words;
    vector<Spot*> spots;
    int choice;
    int randomIdx;
    do {
        dialog.printMenu(MAIN_MENU);
        choice = dialog.getSingleChoice();
        switch(choice) {
            case 1:
                dialog.printMenu(SELECT_AREA);
                input = dialog.getMultiChoice();
                words = dialog.parseChoice(SELECT_AREA, input);
                spots = spotFinder.search(words);
                if(spots.size() == 0) {
                    cout << "=== 검색결과가 없습니다 ===" << endl << endl;
                    break;
                }
                while(spots.size() != 0) {
                    randomIdx = rand() % spots.size();
                    dialog.printSuggestion(spots[randomIdx]);
                    dialog.printMenu(SUGGEST_EVALUATION);
                    choice = dialog.getSingleChoice();
                    if(choice == 1) {
                        dialog.printShareInfo(spots[randomIdx]);
                        dialog.printMenu(CHECK_NEED_MORE);
                        choice = dialog.getSingleChoice();
                        if(choice == 2) break;
                    }
                    spots.erase(spots.begin() + randomIdx);
                }
                if(choice == 1)
                    cout << "=== 모든 결과를 보여드렸습니다. ===" << endl << endl;
                break;
            case 2:
                dialog.printMenu(SELECT_THEME);
                input = dialog.getMultiChoice();
                words = dialog.parseChoice(SELECT_THEME, input);
                spots = spotFinder.search(words);
                if(spots.size() == 0) {
                    cout << "=== 검색결과가 없습니다 ===" << endl << endl;
                    break;
                }
                while(spots.size() != 0) {
                    randomIdx = rand() % spots.size();
                    dialog.printSuggestion(spots[randomIdx]);
                    dialog.printMenu(SUGGEST_EVALUATION);
                    choice = dialog.getSingleChoice();
                    if(choice == 1) {
                        dialog.printShareInfo(spots[randomIdx]);
                        dialog.printMenu(CHECK_NEED_MORE);
                        choice = dialog.getSingleChoice();
                        if(choice == 2) break;
                    }
                    spots.erase(spots.begin() + randomIdx);
                }
                if(choice == 1)
                    cout << "=== 모든 결과를 보여드렸습니다. ===" << endl << endl;
                break;
            case 3:
                dialog.printMenu(NOT_IMPLEMENTED);
                break;
            case 4:
                dialog.printMenu(NOT_IMPLEMENTED);
                break;
            case 0:
                break;
            default:
                cout << "=== 메뉴에 있는 번호만 입력해주세요 : ) ===" << endl;
                cout << endl;
        }
    } while(choice != 0);
    return 0;
}