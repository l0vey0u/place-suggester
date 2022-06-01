#pragma once
#include "spot.h"
#include <unordered_map>
class SpotFinder {
    public:
        SpotFinder();
        SpotFinder(vector<Spot*> spots);
        vector<Spot*> search(vector<string> words);
    private:
        vector<Spot*> spots;
        unordered_map<string, vector<Spot*>> cache;
        vector<Spot*> searchByArea(vector<string> words);
        vector<Spot*> searchByTag(vector<string> words);
        vector<Spot*> searchAtCache(vector<string> words);
};