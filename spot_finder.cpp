#include "spot_finder.h"
#include "spot.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
SpotFinder::SpotFinder() {
    this->spots = {};
}
SpotFinder::SpotFinder(vector<Spot*> spots) {
    this->spots = spots;
}
vector<Spot*> SpotFinder::search(vector<string> words) {
    vector<Spot*> cachedResult = searchAtCache(words);
    vector<Spot*> result = cachedResult; // 캐시 검색결과 벡터 재사용
    vector<Spot*> tagsResult = searchByTag(words);
    vector<Spot*> areaResult = searchByArea(words);
    result.insert(result.end(), tagsResult.begin(), tagsResult.end());
    result.insert(result.end(), areaResult.begin(), areaResult.end());
    return result;
}
vector<Spot*> SpotFinder::searchAtCache(vector<string> words) {
    for(string word : words) {
        if(cache.find(word) != cache.end()) {
            return cache[word];
        }
    }
    return {};
}
vector<Spot*> SpotFinder::searchByArea(vector<string> words) {
    vector<Spot*> result;
    for(string word : words) {
        for(Spot* spot : spots) {
            string full_path = spot->getPath();
            if(full_path.find(word) != string::npos) {
                if(find(result.begin(), result.end(), spot) == result.end()) {
                    result.push_back(spot);
                }
            }
        }
    }
    return result;
}
vector<Spot*> SpotFinder::searchByTag(vector<string> words) {
    vector<Spot*> result;
    for(string word : words) {
        for(Spot* spot : spots) {
            for(string tag : spot->getTags()) {
                if(tag.find(word) != string::npos) {
                    if(cache.count(tag) == 0) {
                        cache[tag] = {spot};
                    } else {
                        if(find(cache[tag].begin(), cache[tag].end(), spot) == cache[tag].end()) {
                            cache[tag].push_back(spot);
                        }
                    }
                    if(find(result.begin(), result.end(), spot) == result.end()) {
                        result.push_back(spot);
                    }
                }
            }
        }
    }
    return result;
}