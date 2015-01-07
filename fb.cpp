/*- task 1
- task 2
- task 3
- task 4

1: depends on 3 and 4
3: depends on 2

2,3,4,1
*/
struct Task{
    int task_num;
    unordered_map <int,Task *> deps; //dependencies
}

vector <Task> createTaskOrder (vector<Task> tasks){
    
    vector <Task> result;
    unordered_set <int> temp //int = task number
    
    //Tasks without any dependencies added
    
    for(std::vector<Task>::iterator it = tasks.begin(); it != tasks.end() ;++it){
        if((*it).deps.size() == 0){
            result.push_back(*it);
            temp.insert((*it).task_num);
            tasks.erase(it);
       }
    }
    
    //Go through each remaining task and if all dependencies are present in result, add it
    int tasksSize = tasks.size();
    
    for(int i = 0; i<tasksSize ; ++i){
        for(std::vector<Task>::iterator it = tasks.begin(); it != tasks.end() ;++it){
            bool allTasksFound = true;
            for(std::vector<Task>::iterator it2 = (*it).deps.begin(); it2 != (*it).deps.end(); it2++){
                
                if(temp.find((*it2).task_num)) == temp.end()){
                     allTasksFound = false;      
                }
            }
        
            if(allTasksFound){
                result.push_back(*it);
                temp.insert((*it).task_num));
                tasks.erase(it);
             }
        }
    }
    
    return result;
}
