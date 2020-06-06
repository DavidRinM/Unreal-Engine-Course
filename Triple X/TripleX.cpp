#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    //Explains game instroduction
    std::cout<< "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout<< "secure server room....\nYou need to enter the correct codes to continue....\n\n";
}


bool PlayGame(int Difficulty){

    PrintIntroduction(Difficulty);

    //
    //Values 0,1,2,3,4
    const int CodeA = rand() % Difficulty + Difficulty ; //Cannot chnage variable value
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout<< std::endl;
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "The codes add-up to: " << CodeSum;
    std::cout << "\nThe codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "\n\nYou entered: " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
 
    //Check Answer
    if(CodeSum == GuessSum && CodeProduct == GuessProduct){
        std::cout << "\nYou won!";
        return true;
    }
    else{
        std::cout << "\nGAME OVER";
        return false;
    }
}


int main(){

    srand(time(NULL));//Random sequences based on time fo the day

    int LevelDifficulty = 1;
    const int maxDifficulty = 10;

    while(LevelDifficulty <= maxDifficulty){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete){
            LevelDifficulty++;
        }
        
    }

    std::cout << "Great Work Agent!!";
    return 0;

}