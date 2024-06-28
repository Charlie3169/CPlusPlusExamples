#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <stdlib.h>

#define MAX_PLAYERS 10

using namespace std;

/*
    Class representing an N-sided die
*/
class Dice{
    private:
        int numSides;
        void seedRandomGenerator() {
            srand((unsigned)time(0));
        }
    public:
        Dice(int numSides){
            this->numSides = numSides;
            seedRandomGenerator();
        }
        // Perform a single roll of the die    
        int roll() {
            return (rand()%numSides)+1; 
        }
};

/*
    Class representing a Game Player
*/
class Player{
    private:
        string name;
        int score;
    public:
        Player(string name, int score){
            this->name = name;
            this->score = score;
        }
        // Getter : Player Name
        string getName() {
            return name;
        }
        // Getter : Score
        int getScore() {
            return score;
        }
        // Increases the player's score by a specified value
        void addToScore(int val){
            score = score + val;            
        }
};

/*
    Abstract class DiceGame
*/
class DiceGame{
    private:
        void getNameAndScore(string line, char delimiter, string &name1, int &score1){
            int delimiterIdx = -1;
            for(int i=0; line[i]!='\0'; i++){
                if(line[i]==delimiter){
                    delimiterIdx = i;
                }
            }
            name1 = line.substr(0, delimiterIdx);
            score1 = atoi(line.substr(delimiterIdx+1, delimiterIdx+2).c_str());
        }
        
    protected:
        Player *players[MAX_PLAYERS];
        Dice *dice;
        int numPlayers, numDice;
        
    public:
        //    Pure virtual function    
        virtual void play() = 0;
        
        void initPlayers() {
            string name;
            int score;
            for(int idx=0; idx<numPlayers; idx++) {
                cout<<"Enter player name:";
                cin>>name;
                cout<<"Enter player score:";
                cin>>score;
                players[idx] = new Player(name, score);
            }
        }
        
        void initPlayersFromFile(char *fileName){
            string line, name1;
            int score1, playerIdx = 0;
            ifstream textFile(fileName);
            if (textFile.is_open(), ios::app)
            {
                while ( getline (textFile,line) )
                {
                  score1 = 0;
                  getNameAndScore(line, ':', name1, score1);
                  cout<<name1<<"\t"<<score1<<"\n";
                  players[playerIdx++] = new Player(name1, score1);
                }
                textFile.close();    
            }
            else cout << "Unable to read from ip file";
        }

        void displayScores() {
            for(int i=0; i<numPlayers; i++){
                cout<<"Name:"<<players[i]->getName()<<"\t"<<"Score:"<<players[i]->getScore()<<"\n";
            }
        }
        
        void writeScoresToFile(char *fileName) {
            ofstream textFile(fileName, ios::app);
            if (textFile.is_open())
            {
                for(int i=0; i<numPlayers; i++){
                    textFile<<players[i]->getName()<<":"<<players[i]->getScore()<<"\n";
                }
                textFile.close();
            }
            else cout << "Unable to open file";
        }
        
        void findHighestScore(char *fileName){
            string line, name, maxName;
            int score, maxScore=0;
            ifstream textFile(fileName);
            if (textFile.is_open())
            {
                while ( getline (textFile,line) )
                {
                  score = 0;
                  getNameAndScore(line, ':', name, score);
                  if(score > maxScore) {
                      maxScore = score;
                      maxName = name;
                  }
                }
                textFile.close();
                cout<<"Player with the highest score:\n"<<maxName<<"\t"<<maxScore;    
            }
            else cout << "Unable to read from ip file";

        }
};

/*
    KnockOut: Each player rolls 'n' dice. If a players roll adds upto a certain number he/she gets knocked out. 
    The last player standing wins.
*/
class KnockOut : public DiceGame {
    private:
        int knockOutSum;
    public:
        KnockOut(Dice dice, int numPlayers, int numDice) {
            this->dice = &dice;
            this->numPlayers = numPlayers;
            this->numDice = numDice;
            this->knockOutSum = dice.roll()*numDice;
        }
        
        void play() 
        {
            int currScore, currPlayers[numPlayers];
            // Array of player indices 0:numPlayers. These will be set to -1 if a player is knocked out.
            for(int idx=0; idx<numPlayers; idx++) {
                currPlayers[idx] = idx;
            }
            int remPlayers = numPlayers;
            while(remPlayers > 1){
                // Compute the score as each player rolls the dice.
                for(int idx=0; idx<numPlayers; idx++) {
                    currScore = 0;
                    for(int idx1=0; idx1<numDice; idx1++){
                        currScore += dice->roll();
                    }
                    // Track the winning score.
                    if(currScore == knockOutSum){
                        remPlayers --;
                        currPlayers[idx] = -1;
                    }    
                }
            }
            // Find the winner and reward the player.
            for(int idx=0; idx<numPlayers; idx++) {
                if(currPlayers[idx] > -1) {
                    players[idx]->addToScore(10);
                    break;
                }
            }
            
        }
};

/*
    BostonDiceGame: Each player rolls 'n' dice. At each roll, preserve the dice with the highest number 
    and roll the remaining dice. The player with the highest score wins.
*/
class BostonDiceGame : public DiceGame{
    public:
        BostonDiceGame(Dice dice, int numPlayers, int numDice) {
            this->dice = &dice;
            this->numPlayers = numPlayers;
            this->numDice = numDice;
        }
        
        void play() {
            int currScore, currRoll=0, maxRoll = 0, maxScore=0, winnerIdx = -1;
            // Compute the score as each player rolls the dice.
            for(int idx=0; idx<numPlayers; idx++) {
                currScore = 0;
                maxRoll = 0;
                for(int idx1=0; idx1<numDice; idx1++){
                    currRoll = 0; maxRoll = 0;
                    // At each turn, one less die is rolled.
                    for(int idx2=numDice-idx1; idx2>0; idx2--){
                        currRoll = dice->roll();
                        if(currRoll > maxRoll) {
                            maxRoll = currRoll;
                        }
                    }
                    currScore += maxRoll;
                }
                // Track the winning score.
                if(currScore > maxScore){
                    maxScore = currScore;
                    winnerIdx = idx;
                }    
            }
            // Reward the player with the highest score.
            players[winnerIdx]->addToScore(10);
        }
    
};

int main() {
    // Base class pointer
    DiceGame *game;
    int choice, numSides, numPlayers, numDice;
    cout<<"What game would you like to play?\n1.Knock Out\n2.Boston Dice Game\n";
    cin>>choice;
    cout<<"You can use a 3-sided, 4-sided or 6-sided die. Enter a number indicating your choice:";
    cin>>numSides;
    cout<<"Number of dice?";
    cin>>numDice;
    cout<<"Number of players?";
    cin>>numPlayers;
    Dice dice(numSides);
    if(choice==1){
        KnockOut obj(dice, numPlayers, numDice);
        game = &obj;
    } else {
        BostonDiceGame obj(dice, numPlayers, numDice);
        game = &obj;
    }
    game->initPlayers();
    game->play();
    game->displayScores();
    game->writeScoresToFile("scorecard.txt");
    game->findHighestScore("scorecard.txt");
}