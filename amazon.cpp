// Given filled sudoku, check if it's valid
//
// 1 5 6 7 5 2 3 4 9
// 2 4 7 8 9 3 6 5 1
// 3 8 9 1 4 6
// 4
// 5
// 6
// 7
// 8
// 9


bool isSolutionValid(int **sudoku, int dem){
    
    bool isNumPresent[dem];
    
    
    setArrayToFalse(isNumPresent, dem);
    
    //check each row if it's valid
    for(int i=0; i<dem; i++){
        for(int j=0; j<dem; j++){
            int current = sudoku[i][j];
            if(isNumPresent[current-1] == true)
                return false;
            else
                isNumPresent[current-1] = true;
        }   
        setArrayToFalse(isNumPresent, dem);
 
    }


    //check each column if it's valid
    for(int i=0; i<dem; i++){
        for(int j=0; j<dem ; j++){
            int current = sudoku[j][i];
            if(isNumPresent[current-1] == true)
            return false;
            else
                isNumPresent[current-1] = true;
        }
        setArrayToFalse(isNumPresent, dem);
    }
    
    int dem_root = sqrt(dem);
    //check each 3x3 submatrix if valid
    for(int i=0; i<dem_root; i++){
        for(int j=0; j<dem_root; j++){
            for(int k=0; k<dem_root; k++){
                for(int l=0; l<dem_root; l++){
                     int current = sudoku[(dem_root*i)+k][(dem_root*j)+l];
                     if(isNumPresent[current-1] == true)
                           return false;
                     else
                         isNumPresent[current-1] = true;   
                }
            }
            setArrayToFalse(isNumPresent, dem_root);
       }
    }
    
    return true;
}

void setArrayToFalse (bool input[], int length){
    for(int i=0; i<length; i++){
        input[i] = false;
    }
}
