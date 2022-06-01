#include "dialog.h"
#include "spot_finder.h"
#include "data_parser.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void Dialog::printMenu(int case_num) {
    // TODO: 데이터가 있는지역만 출력하기
    string area[] = {"서울", "경기", "인천", "대구", "부산", "강원", "제주"};
    // TODO: 테마목록을 받아오기
    string theme[] = {"힐링", "호캉스", "액티비티", "역사여행"};
    switch (case_num) {
        case MAIN_MENU:
            cout << "=== 여행지를 부탁해! ===" << endl;
            cout << " 1. 지역은 정했어!" << endl;
            cout << " 2. 테마는 정했어!" << endl;
            cout << " 3. 아무거나 보여줘!" << endl;
            cout << " 4. MT 장소 추천해줘!" << endl;
            cout << " 0. 그만 할래." << endl;
            cout << endl;
            break;
        case SELECT_AREA:
            cout << "=== 원하는 지역을 모두 골라주세요 ===" << endl;
            cout << " ";
            for(int i = 0; i < 7; i++) {
                cout << i + 1 << ". " << area[i] << " ";
            }
            cout << endl;
            cout << endl;
            break;
        case SELECT_THEME:
            cout << "=== 원하는 테마를 모두 골라주세요 ===" << endl;
            cout << " ";
            for(int i = 0; i < 4; i++) {
                cout << i + 1 << ". " << theme[i] << " ";
            }
            cout << endl;
            cout << endl;
            break;
        case SUGGEST_EVALUATION:
            cout << "=== 이 여행지가 맘에 드나요? ===" << endl;
            cout << " 1. 네\t2.다른 곳 볼래요" << endl;
            cout << endl;
            break;
        case CHECK_NEED_MORE:
            cout << "=== 더 보고 싶으신가요? ===" << endl;
            cout << " 1. 네\t2. 아니요 충분해요" << endl;
            cout << endl;
            break;
        case NOT_IMPLEMENTED:
            cout << "=== 아직 구현되지 않았어요. ===" << endl;
            cout << endl;
            break;
    }
}

void Dialog::printSuggestion(Spot* spot) {
    cout << "=== 이 여행지 어때요? ===" << endl;
    cout << " " << spot->getName() << endl;
    cout << " 주소 : " << spot->getPath() << endl;
    string img_url = spot->getImageUrl();
    if(img_url != "")
        cout << " 장소 이미지 : https://" << spot->getImageUrl() << endl;
    vector<string> tags = spot->getTags();
    cout << " 장소 설명 : ";
    for(int i = 0; i < tags.size(); i++) {
        cout << tags[i] << " ";
    }
    cout << endl;
    cout << endl;
}

void Dialog::printShareInfo(Spot* spot) {
    string name = spot->getName();
    string img_url = spot->getImageUrl();
    vector<string> tags = spot->getTags();
    cout << "====== 이 여행지를 공유해보세요! ======" << endl;
    cout << endl;
    cout << " " << name << endl;
    cout << endl;
    cout << " 주소 : " << spot->getPath() << endl;
    if(img_url != "")
        cout << " 뷰 보러가기 : https://" << spot->getImageUrl() << endl;
    cout << " 장소 설명 : ";
    for(int i = 0; i < tags.size(); i++) {
        cout << tags[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << string(39, '=') << endl;
    cout << endl;
}
int Dialog::getSingleChoice() {    
    int choice;
    cout << "선택 : ";
    cin >> choice;
    cout << endl;
    return choice;
}

string Dialog::getMultiChoice() {    
    string input;
    cout << "선택(숫자입력) : ";
    cin >> input;
    cout << endl;
    return input;
}
vector<string> Dialog::getWordTbl(int case_num) {
    // TODO: 데이터가 있는지역만 출력하기
    string area[] = {"서울", "경기", "인천", "대구", "부산", "강원", "제주"};
    // TODO: 테마목록을 받아오기
    string theme[] = {"힐링", "호캉스", "액티비티", "역사여행"};
    vector<string> word_tbl;
    switch (case_num) {
        case SELECT_AREA:
            word_tbl.push_back("NOT_USE_ZERO");
            for(int i = 0; i < 7; i++) {
                word_tbl.push_back(area[i]);
            }
            break;
        case SELECT_THEME:
            word_tbl.push_back("NOT_USE_ZERO");
            for(int i = 0; i < 4; i++) {
                word_tbl.push_back(theme[i]);
            }
            break;
    }
    return word_tbl;
}
vector<string> Dialog::parseChoice(int case_num, string choice) {
    vector<string> words;
    stringstream ss(choice);
    string token;
    vector<string> wordTbl = getWordTbl(case_num);
    while(getline(ss, token, ',')) {
        words.push_back(wordTbl[stoi(token)]);
    }
    return words;
}