// To implement the dynamics programming based algorithm to 
// find the Levenshtein distance between 2 text strings
#include<iostream>
#include<vector>
#include<string>

class EditDistance {
public:
    static int calculateLevenshteinDist(const std::string& str1, const std::string& str2){
        int nbRow = str1.length();
        int nbCol = str2.length();
        std::vector<std::vector<int>> dp(nbRow+1,std::vector<int>(nbCol+1));
        // initialization
        for(int row=0;row<=nbRow;row++) dp[row][0] = row;
        for(int col=0;col<=nbCol;col++) dp[0][col] = col;
        // calculate the dp matrix
        for(int row=1;row<=nbRow;row++){
            for(int col=1;col<=nbCol;col++){
                if(str1[row-1] == str2[col-1]){
                    dp[row][col] = dp[row-1][col-1];
                }
                else{
                    int tmp = std::min(dp[row-1][col-1],dp[row][col-1]); // either substitution or insertion
                    dp[row][col] = std::min(tmp,dp[row-1][col]) + 1;     // or deletion
                }
            }
        }
        // 
        return dp[nbRow][nbCol];
    }
};

int main(int argc, char** argv){
    // TODO: add test module
    // TODO: add trace-back
    std::string str1("element");
    std::string str2("evidence");
    int editDistance = EditDistance::calculateLevenshteinDist(str1,str2);
    std::cout << "Edit distance = " << editDistance << std::endl; 
    return 0;
}