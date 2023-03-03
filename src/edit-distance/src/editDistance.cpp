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
    //
    static int calculateLevenshteinDist1Row(const std::string& str1, const std::string& str2){
        int nbRow = str1.length();
        int nbCol = str2.length();
        //
        std::vector<int> dp(nbCol+1);
        for(int j=0; j<=nbCol; j++){
            dp[j] = j;
        }
        //
        int last;
        for(int i=1;i<=nbRow;i++){
            last = dp[0];
            dp[0] = i;
            for(int j=1;j<=nbCol;j++){
                if(str1[i-1] == str2[j-1]){
                    std::swap(last,dp[j]); 
                } else {
                    int tmp = std::min(last,dp[j]);
                    last = dp[j];
                    dp[j] = std::min(tmp,dp[j-1]) + 1;
                }
            }
        }
        return dp[nbCol];
    }
};

int main(int argc, char** argv){
    // TODO: add test module
    // TODO: add trace-back
    if(argc != 3){
        std::cout << "Use: ./editDist string1 string2" << std::endl;
        return 1;
    }
    std::string str1(argv[1]);
    std::string str2(argv[2]);
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;
    int editDistance = EditDistance::calculateLevenshteinDist(str1,str2);
    int editDistance1Row = EditDistance::calculateLevenshteinDist1Row(str1,str2);
    std::cout << "Edit distance = " << editDistance << std::endl;
    std::cout << "Edit distance 1 Row = " << editDistance1Row << std::endl; 
    return 0;
}