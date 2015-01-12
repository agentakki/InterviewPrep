//schedule programming of least recently aired show
// list of shows in order 
// A B A C : Returns B
//
// A A A B C C B : Returns C

string selectShowToRerun (vector<string> shows){  
 
  unordered_map<string, int> showCounts;
  
  //map shows to number of times aired
for(auto it = shows.begin(); it!= shows.end(); it++){
    auto found = showCounts.find(*it);
    if(found == showCounts.end()){
      showCounts[*it] = 1;
    }
    else{
      found->second++;
    }
}
  
  int minCount = INT_MAX;
  vector<string> minCountShows;
 
//go through show list and find minCount   
  for(auto it = shows.begin(); it!= shows.end(); it++){
      auto found = showCounts.find(*it);
      if(found->second < minCount){
        minCount = found->second;
      }
  }

//make a hashmap and list(for order) of shows with minCount
unordered_map <string, int> minCountShowMap;
list<string> minShows;
for(auto it = shows.begin(); it!= shows.end(); it++){
      auto found = showCounts.find(*it);
      if(found != showCounts.end()){
        if(found->second == minCount){
          minCountShowMap[found->first] = minCount;
          
          minShows.push_back(found->first);
        }
      }  
 }


//Whichever show reaches 0 first is the least recently aired
  for(auto it = minShows.begin() ; it!= minShows.end(); it++){
    auto found = minCountShowMap.find(*it);  
    if(found != minCountShowMap.end()){
      found->second--;
      if(found->second == 0){
        return found->first;
      }
    }
  }
}
