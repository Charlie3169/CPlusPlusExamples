#include <iostream> 
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

		Dice(int numSides)
		{
			this->numSides = numSides;
			seedRandomGenerator();
		}

		// Perform a single roll of the die
		int roll()
		{			
			return rand() % numSides + 1;
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
		Player(string name, int score)
		{
			this->name = name;
			this->score = score;
		}

		// Getter : Player Name
		string getName()
		{
			return name;
		}
		// Getter : Score
		int getScore()
		{
			return score;
		}
		// Increases the player's score by a specified value
		void addToScore(int val)
		{
			score += val;
		}
};


class DiceGame{
	private:
		void getNameAndScore(string line, char delimiter, string &name1, int &score1){
				int delimiterIdx = -1;
				for(int i=0; line[i]!='\0'; i++)
				{
					if(line[i]==delimiter)
					{
						delimiterIdx = i;
					}
				}
                name1 = line.substr(0, delimiterIdx);
                score1 = atoi(line.substr(delimiterIdx+1, delimiterIdx+2).c_str());
		}

	protected:
		Player *players[MAX_PLAYERS];
		Dice *dice;
		int numPlayers;
		int numDice;

	public:
		//	Pure virtual function
		virtual void play() = 0;

		void initPlayers()
		{
			int i = 0;
            while(i < numPlayers)
            {
                cout << "Enter Player #" << i + 1 << " Name: ";
                string name;
                cin >> name;

                cout << "Enter Player #" << i + 1 << " Score: ";
                int score;
                cin >> score;

                players[i] = new Player(name, score);
                i++;
            }

		}

		 void initPlayersFromFile(char *fileName)
		 {
            string line, name1;
            int score1, playerIdx = 0;
            ifstream textFile(fileName);
            if (textFile.is_open(), ios::app)
            {
                while (getline(textFile,line))
                {
                  score1 = 0;
                  getNameAndScore(line, ':', name1, score1);
                  cout << name1 << "\t" << score1 << "\n";
                  players[playerIdx++] = new Player(name1, score1);
                }
                textFile.close();    
            }
            else cout << "Unable to read from ip file";
        }

		void displayScores()
		{
		    cout <<"----------------------" << endl;
			for(int i = 0; i < numPlayers; ++i)
			{
				Player p = *players[i];
				cout << p.getName() << ": " << p.getScore() << endl;
			}
		}

		void writeScoresToFile(char *fileName) 
		{
            ofstream textFile(fileName, ios::app);
            if (textFile.is_open())
            {
                for(int i=0; i<numPlayers; i++)
				{
                    textFile<<players[i]->getName()<<":"<<players[i]->getScore()<<"\n";
                }
                textFile.close();
            }
            else cout << "Unable to open file";
        }

		void findHighestScore(char *fileName)
		{
            string line, name, maxName;
            int score, maxScore=0;
            ifstream textFile(fileName);
            if (textFile.is_open())
            {
                while (getline (textFile,line))
                {
                  score = 0;
                  getNameAndScore(line, ':', name, score);
                  if(score > maxScore) 
				  {
                      maxScore = score;
                      maxName = name;
                  }
                }
                textFile.close();
                cout<<"Player with the highest score: \n"<<maxName<<"\t"<<maxScore;    
            }
            else cout << "Unable to read from ip file";
        }




};

class KnockOut : public DiceGame
{
    private:        
        int knockOutScore;
    public:
        KnockOut(Dice dice, int numPlayers, int numDice)
        {
            this->dice = &dice;
            this->numPlayers = numPlayers;
            this->numDice = numDice;

			int knockOutSum = 0;
            for(int i = 0; i < numDice; ++i)            {
                
                knockOutSum += dice.roll();
            }

            this->knockOutScore = knockOutSum;           
        }


        void play()
        {
            int currScore, currPlayers[numPlayers];
            for(int i = 0; i < numPlayers; ++i)
            {
                currPlayers[i] = i;
            }
            int remPlayers = numPlayers;

            while(remPlayers > 1)
            {                
                for(int i = 0; i < numPlayers; i++) 
                {
                    currScore = 0;
                    for(int j = 0; j < numDice; j++)
                    {
                        currScore += dice->roll();
                    }
                    
                    if(currScore == knockOutScore)
                    {
                        remPlayers--;
                        currPlayers[i] = -1;
                    }    
                }
            }

            for(int i = 0; i < numPlayers; i++) 
            {
                if(currPlayers[i] > -1) {
                    players[i]->addToScore(10);
                    break;
                }
            }           

        }
};

class BostonDiceGame : public DiceGame
{
    public:
        BostonDiceGame(Dice dice, int numPlayers, int numDice) 
        {
            this->dice = &dice;
            this->numPlayers = numPlayers;
            this->numDice = numDice;
        }
        
        void play() 
        {
            int currScore, currRoll=0, maxRoll = 0, maxScore=0, winnerIdx = -1;

            // Compute the score as each player rolls the dice.
            for(int i = 0; i < numPlayers; i++) 
            {
                currScore = 0;
                maxRoll = 0;
                for(int j = 0; j < numDice; j++)
                {
                    currRoll = 0; maxRoll = 0;
                    // At each turn, one less die is rolled.
                    for(int k = numDice - j; k > 0; k--)
                    {
                        currRoll = dice->roll();
                        if(currRoll > maxRoll) 
                        {
                            maxRoll = currRoll;
                        }
                    }
                    currScore += maxRoll;
                }
                // Track the winning score.
                if(currScore > maxScore){
                    maxScore = currScore;
                    winnerIdx = i;
                }    
            }
            // Reward the player with the highest score.
            players[winnerIdx]->addToScore(10);
        }
    
};




int main() {
	// Base class pointer
	DiceGame *game;

    //Part 1
	//Dice die(6);
	//cout << "Dice roll: "  << die.roll() << endl;

    //Part 2
	//Player p("Charlie", 7);
	//Player p2("Sam", 6);
	//cout << p.getName() << " " << p.getScore() << endl;
	//cout << p2.getName() << " " << p2.getScore() << endl;

    //Part 3-7
    int choice, numSides, numPlayers, numDice;
    cout << "Game type?\n1.Knock Out\n2.Boston Dice Game\n";
    cin >> choice;
    cout << "Enter the number of sides on each die:";
    cin >> numSides;
    cout << "Number of dice?" << endl;
    cin >> numDice;
    cout << "Number of players?" << endl;
    cin >> numPlayers;
    Dice dice(numSides);
    if(choice == 1)
    {
        KnockOut obj(dice, numPlayers, numDice);
        game = &obj;
    } 
    else 
    {
        BostonDiceGame obj(dice, numPlayers, numDice);
        game = &obj;
    }

    game->initPlayers();
    game->play();
    game->displayScores();
    game->writeScoresToFile("scorecard.txt");
    game->findHighestScore("scorecard.txt");

	

    return 0;

}
