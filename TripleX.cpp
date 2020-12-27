#include <iostream>
#include <windows.h>
#include <ctime>


void PrintIntroduction(int Difficulty) 
{
    std::cout << "\n___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|__\n";
    std::cout << "_|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|\n";
    std::cout << "___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|__\n";
    std::cout << "_|___|___|___|___|________HACKER TIME________|___|___|___|___|___|___|\n";
    std::cout << "___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|__\n";
    std::cout << "_|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|\n";
    std::cout << "___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|__\n";
     // Display info about game to the terminal
    std::cout << "You are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room.. \nEnter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    


    // Declare 3 number code
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;


    // Print CodeSum and product to the terminal
    std::cout << std::endl;
    std::cout << " --| There are 3 numbers in the code";
    std::cout << "\n --| The codes add-up to: " << CodeSum;
    std::cout << "\n --| The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        system("cls");
        std::cout << "\n***You successfully encrypted file!***\n";
        std::cout << "\n***KEEP GOING***\n";
        Sleep(5000);
        system("cls");
        return true;
    }
    else 
    {
        system("cls");
        std::cout << "\n***WRONG CODE***\n";
        std::cout << "\n***TRY  AGAIN***\n";
        Sleep(2500);
        system("cls");
        return false;
    }

}

int main()
{ 
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }
        
    }
    system("cls");
    std::cout << "DOWNLOADING FILES...!\n";
    Sleep(2000);
    system("cls");
    std::cout << "DOWNLOADING COMPLETED!!!\n";
    Sleep(2000);
    std::cout << "___________________________________________\n";
    std::cout << "Great work agent! You got all the files! Now get out of there!\n";
    return 0;
}
