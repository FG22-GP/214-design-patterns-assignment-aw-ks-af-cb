#include "ScoreManager.h"

#include <iostream>

#include "fstream"
ScoreManager::ScoreManager() : CurrentScore(0), Highscore(0)
{
    LoadHighScoreFromFile("highscore.txt");
}

void ScoreManager::IncreaseScore(int score)
{
    CurrentScore += score;
}

int ScoreManager::GetCurrentScore() const
{
    return CurrentScore;
}

void ScoreManager::UpdateHighScore()
{
    if(CurrentScore > Highscore)
    {
        Highscore = CurrentScore;
        SaveHighScoreToFile("highscore.txt");
    }
}

int ScoreManager::GetHighScore() const
{
    return Highscore;
}

void ScoreManager::SaveHighScoreToFile(const std::string& filename) const
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << std::to_string(Highscore);  // Convert int to string before writing
        file.close();
    }
    else
    {
        // Handle the case where the file couldn't be opened for writing
        std::cerr << "Error saving high score to file: " << filename << std::endl;
    }
}

void ScoreManager::LoadHighScoreFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string highScoreStr;
        if (std::getline(file, highScoreStr))
        {
            try
            {
                Highscore = std::stoi(highScoreStr);
            }
            catch (const std::exception& e)
            {
                std::cout << "Error converting high score: " << e.what() << std::endl;
            }
        }
        file.close();
    }
    else
    {
        // If the file doesn't exist, create it and set an initial high score
        SaveHighScoreToFile(filename);
    }
}
