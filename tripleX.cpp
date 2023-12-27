#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent tasked with breaking into a level " << Difficulty; 
    std::cout << " secure server room\nYou must enter the correct code to continue\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    const int CodeA = rand() % Difficulty+Difficulty;
    const int CodeB = rand() % Difficulty+Difficulty; 
    const int CodeC = rand() % Difficulty+Difficulty; 
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "There are three numbers in the code\n";
    std::cout << "The numbers add up to: " << CodeSum << "\n";
    std::cout << "The product of the nubmers is: " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC << "\n";

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You Win!";
        return true;
    }
    else
    {
        std::cout << "You Lose!";
        return false;
    }

}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 3;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer
        // system("cls"); // Clears terminal

        if (bLevelComplete)
        {
            // Increase difficulty
            ++LevelDifficulty;
        }
        
    }
    return 0;
}