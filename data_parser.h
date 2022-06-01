#pragma once
#include <string>
#include "spot.h"
using namespace std;

const string DB_FILE_NAME = "place.csv";

class DataParser {
    private:
        vector<string> split(const string& line, const char delimiter);
        Spot* parseFormattedSpot(const string& dummy);
    public:
        vector<Spot*> getSpotListFromFile();
};