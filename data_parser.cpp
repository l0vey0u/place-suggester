#include "data_parser.h"
#include "spot.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;
vector<string> DataParser::split(const string& line, const char delimiter = ',') {
    vector<string> result;
    stringstream ss(line);
    string item;
    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}
Spot* DataParser::parseFormattedSpot(const string& dummy) {
    vector<string> tokens = split(dummy);
    string name = tokens[0];
    string path = tokens[1];
    string image_url = tokens[2];
    vector<string> tags = split(tokens[3], ' ');
    return new Spot(name, path, image_url, tags);
}
vector<Spot*> DataParser::getSpotListFromFile() {
    string line;
    ifstream readFile;
    vector<Spot*> spotList;
    readFile.open(DB_FILE_NAME);
    if (!readFile.is_open()) {
        return spotList;
    }
    getline(readFile, line); // skip header
    while(!readFile.eof()) {
        getline(readFile, line);
        if (line.empty()) {
            continue;
        }
        Spot* spot = parseFormattedSpot(line);
        if (spot == nullptr) {
            continue;
        }
        spotList.push_back(spot);
    }
    return spotList;
};