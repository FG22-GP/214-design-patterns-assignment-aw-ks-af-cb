#pragma once
#include <string>

class ScoreManager
{
public:
    ScoreManager();

    void IncreaseScore(int score);

    int GetCurrentScore() const;

    void UpdateHighScore();

    int GetHighScore() const;

    void SaveHighScoreToFile(const std::string& filename) const;
    
    void LoadHighScoreFromFile(const std::string& filename);

private:
    int CurrentScore;
    int Highscore;
};
