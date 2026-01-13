#include <fstream>
#include <iostream>

using namespace std;

class Player
{
public:
    int matches;
    int *score;
    int *balls;

    Player(int size = 1)
    {
        matches = size;
        score = new int[matches];
        balls = new int[matches];
        for (int i = 0; i < matches; i++)
        {
            score[i] = i * 6 + 1;
            balls[i] = i + 1;
        }
    }
    void copyFrom(const Player &p)
    {
        matches = p.matches;
        score = new int[matches];
        balls = new int[matches];
        for (int i = 0; i < matches; i++)
        {
            this->score[i] = p.score[i];
            this->balls[i] = p.balls[i];
        }
    }
    Player(const Player &p)
    {
        copyFrom(p);
    }

    Player &operator=(const Player &p)
    {
        delete[] score;
        delete[] balls;
        copyFrom(p);
        return *this;
    }

    ~Player()
    {
        delete[] score;
        delete[] balls;
    }
};

void save_player(const Player p[])
{
    ofstream out("data.bin", ios::binary);
    for (int i = 0; i < 5; i++)
    {
        out.write((char *)&p[i].matches, sizeof(int));
        out.write((char *)(p[i].score), sizeof(int) * p[i].matches);
        out.write((char *)(p[i].balls), sizeof(int) * p[i].matches);
    }
    out.close();
}

void read_player(Player *p)
{
    ifstream in("data.bin", ios::binary);
    for (int i = 0; i < 5; i++)
    {
        in.read((char *)&p[i].matches, sizeof(int));

        p[i].score = new int[p[i].matches];
        p[i].balls = new int[p[i].matches];

        in.read((char *)(p[i].score), sizeof(int) * p[i].matches);
        in.read((char *)(p[i].balls), sizeof(int) * p[i].matches);
    }

    in.close();
}

int main()
{
    Player *p = new Player[5];
    for (int i = 0; i < 5; i++)
    {
        p[i] = Player(i + 10);
    }

    save_player(p);
    Player *loadedPlayers = new Player[5];

    read_player(loadedPlayers);

    for (int i = 0; i < 5; i++)
    {
        cout << "Player " << i + 1 << " - Matches: " << loadedPlayers[i].matches << endl;
        for (int j = 0; j < loadedPlayers[i].matches; j++)
        {
            cout << "Score: " << loadedPlayers[i].score[j] << ", Balls: " << loadedPlayers[i].balls[j] << endl;
        }
    }

    delete[] p;
    for (int i = 0; i < 5; i++)
    {
        delete[] loadedPlayers[i].score;
        delete[] loadedPlayers[i].balls;
    }
    delete[] loadedPlayers;

    return 0;
}