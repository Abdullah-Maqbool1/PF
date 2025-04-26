#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];

int player1Wins = 0;
int player2Wins = 0;
int draws = 0;

void drawBoard(char(*board)[SIZE], int winner);
int checkWin(char(*board)[SIZE]);
void resetBoard(char(*board)[SIZE]);
bool isValidMove(char(*board)[SIZE], int choice);
void updateBoard(char(*board)[SIZE], int choice, char mark);
void displayStats(int player1Wins, int player2Wins, int draws);
void saveStatsToFile(int player1Wins, int player2Wins, int draws);
void loadStatsFromFile(int& player1Wins, int& player2Wins, int& draws);
void readInitialBoardFromFile(char(*board)[SIZE], const char* filename);
void writeBoardToFile(const char(*board)[SIZE], const char* filename);
void playGame(char(*board)[SIZE], int& player1Wins, int& player2Wins, int& draws);

void drawBoard(char(*board)[SIZE], int winner)
{
    cout << "  ******      Tic Tac Toe Board     ******* " << endl;
    cout << "\n";
    for (int i = 0; i < SIZE; ++i)
    {
        cout << "\t\t\t\t\t\t";
        for (int j = 0; j < SIZE; ++j)
        {
            cout << " " << board[i][j];
            if (j < SIZE - 1)
                cout << " |";
            else if (j == SIZE - 1 && i < SIZE - 1)           cout << endl << "\t\t\t\t\t\t" << "---|---|---" << endl;
        }
        cout << endl;
    }
    cout << "\n\n\n\n\n";

    if (winner == 1) {
        cout << "\t\t\t\t\t Player 1 (X) wins!\n\n\n";
    }
    else if (winner == 2) {
        cout << "\t\t\t\t\t Player 2 (O) wins!\n\n\n";
    }
}

int checkWin(char(*board)[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            if (board[i][0] == 'X')
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            if (board[0][i] == 'X')
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        if (board[0][0] == 'X')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        if (board[0][2] == 'X')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    bool full = true;
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (board[row][col] == ' ')
            {
                full = false;
                break;
            }
        }
        if (!full)
        {
            break;
        }
    }

    if (full)
    {
        return 0;
    }

    return -1;
}

void resetBoard(char(*board)[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

bool isValidMove(char(*board)[SIZE], int choice)
{
    if (choice < 1 || choice > 9)
    {
        return false;
    }
    int row = (choice - 1) / SIZE;
    int col = (choice - 1) % SIZE;

    if (board[row][col] != ' ')
    {
        cout << "\n\n\n\t\t\t\tThis position is already taken. Please choose another.\n\n\n";
        return false;
    }

    return true;
}

void updateBoard(char(*board)[SIZE], int choice, char mark)
{
    int row = (choice - 1) / SIZE;
    int col = (choice - 1) % SIZE;
    board[row][col] = mark;
}

void displayStats(int player1Wins, int player2Wins, int draws)
{
    cout << "\t\t\t\t\t **  Game Statistics: **\n";
    cout << "\t\t\t\t\t ----------------\n";
    cout << "\t\t\t\t\t  Player 1 (X) wins:  " << player1Wins << endl;
    cout << "\t\t\t\t\t  Player 2 (O) wins: " << player2Wins << endl;
    cout << "\t\t\t\t\t  Draws:  " << draws << endl;
    cout << "\t\t\t\t\t ----------------\n\n";
}

void saveStatsToFile(int player1Wins, int player2Wins, int draws)
{
    ofstream outFile("game_stats.txt");
    if (outFile.is_open())
    {
        outFile << " Player 1 Wins : " << player1Wins << "\n" << "Player 2 Wins : " << player2Wins << "\n" << "Draw Games : " << draws << endl;
        outFile.close();
    }
    else
    {
        cout << "\t\t\t\tUnable to save game statistics to file." << endl;
    }
}

void loadStatsFromFile(int& player1Wins, int& player2Wins, int& draws)
{
    ifstream inFile("game_stats.txt");
    if (inFile.is_open())
    {
        inFile >> player1Wins >> player2Wins >> draws;
        inFile.close();
    }
    else
    {
        cout << "\t\t\t\tUnable to load game statistics from file." << endl;
    }
}

void readInitialBoardFromFile(char(*board)[SIZE], const char* filename)
{
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                inFile >> board[i][j];
            }
        }
        inFile.close();
    }
    else
    {
        cout << "\t\t\t\tUnable to open file: " << filename << endl;
    }
}

void writeBoardToFile(const char(*board)[SIZE], const char* filename)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                outFile << board[i][j];
                if (j < SIZE - 1)
                {
                    outFile << " ";
                }
            }
            outFile << endl;
        }
        outFile.close();
    }
    else
    {
        cout << "\t\t\t\tUnable to save the current board to file." << endl;
    }
}


bool canWin(char(*board)[SIZE], char player)
{
    int winCondition;
    if (player == 'X')
    {
        winCondition = 1;
    }
    else
    {
        winCondition = 2;
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = player;
                if (checkWin(board) == winCondition)
                {
                    board[i][j] = ' ';
                    return true;
                }
                board[i][j] = ' ';
            }
        }
    }
    return false;
}


void makeBestMove(char(*board)[SIZE], char currentMark)
{
    int bestMove = -1;
    int center = 5;
    char opponentMark;
    if (currentMark == 'X')
    {
        opponentMark = 'O';
    }
    else
    {
        opponentMark = 'X';
    }



    for (int i = 1; i <= 9; i++)
    {
        if (isValidMove(board, i))
        {
            int row = (i - 1) / SIZE;
            int col = (i - 1) % SIZE;
            board[row][col] = currentMark;
            if (checkWin(board) == 1)
            {
                board[row][col] = ' ';
                bestMove = i;
                break;
            }
            board[row][col] = ' ';
        }
    }

    if (bestMove == -1)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (isValidMove(board, i))
            {
                int row = (i - 1) / SIZE;
                int col = (i - 1) % SIZE;
                board[row][col] = opponentMark;
                if (checkWin(board) == 2)
                {
                    board[row][col] = ' ';
                    bestMove = i;
                    break;
                }
                board[row][col] = ' ';
            }
        }
    }


    if (bestMove == -1)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (isValidMove(board, i))
            {
                int row = (i - 1) / SIZE;
                int col = (i - 1) % SIZE;
                board[row][col] = currentMark;
                if (canWin(board, currentMark))
                {
                    board[row][col] = ' ';
                    bestMove = i;
                    break;
                }
                board[row][col] = ' ';
            }
        }
    }
    if (bestMove == -1 && isValidMove(board, center))
    {
        bestMove = center;
    }
    if (bestMove == -1)
    {
        if (board[0][0] == opponentMark && isValidMove(board, 9))
        {
            bestMove = 9;
        }
        else if (board[0][2] == opponentMark && isValidMove(board, 7))
        {
            bestMove = 7;
        }
        else if (board[2][0] == opponentMark && isValidMove(board, 3))
        {
            bestMove = 3;
        }
        else if (board[2][2] == opponentMark && isValidMove(board, 1))
        {
            bestMove = 1;
        }
    }
    if (bestMove == -1)
    {
        if (isValidMove(board, 1))
        {
            bestMove = 1;
        }
        else if (isValidMove(board, 3))
        {
            bestMove = 3;
        }
        else if (isValidMove(board, 7))
        {
            bestMove = 7;
        }
        else if (isValidMove(board, 9))
        {
            bestMove = 9;
        }
    }
    if (bestMove == -1)
    {
        for (int i = 2; i <= 8; i += 2)
        {
            if (isValidMove(board, i))
            {
                bestMove = i;
                break;
            }
        }
    }
    if (bestMove != -1)
    {
        updateBoard(board, bestMove, currentMark);
    }
    else
    {

        for (int i = 1; i <= 9; i++)
        {
            if (isValidMove(board, i))
            {
                updateBoard(board, i, currentMark);
                break;
            }
        }
    }
}

void playGame(char(*board)[SIZE], int& player1Wins, int& player2Wins, int& draws)
{
    int currentPlayer = 1;
    int choice;
    int winner = -1;

    while (winner == -1)
    {
        drawBoard(board, winner);
        char currentMark;
        if (currentPlayer == 1)
        {
            currentMark = 'X';
        }
        else
        {
            currentMark = 'O';
        }

        if (currentPlayer == 1)
        {
            cout << "\n\t\t\t\tPlayer 1 (X), enter your move (1-9): ";
            cin >> choice;
            if (!isValidMove(board, choice))
            {
                continue;
            }
        }
        else {
            cout << "\n\t\t\tPlayer 2 (O), is making a move...\n";
            makeBestMove(board, currentMark);
            drawBoard(board, winner);
        }

        if (currentPlayer == 1)
        {
            updateBoard(board, choice, currentMark);
        }

        winner = checkWin(board);
        currentPlayer = (currentPlayer % 2) + 1;
    }

    drawBoard(board, winner);

    if (winner == 1)
    {
        player1Wins++;
    }
    else if (winner == 2)
    {
        player2Wins++;
    }
    else
    {
        draws++;
    }

    saveStatsToFile(player1Wins, player2Wins, draws);
}

int main()
{
    char board[SIZE][SIZE];
    int player1Wins = 0;
    int player2Wins = 0;
    int draws = 0;
    char playAgain = 'y';
    cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t\t\t                           Welcome to The Game                         " << endl;
    cout << "\t\t\t\t                               TIC TAC TOE                             " << endl;
    cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    loadStatsFromFile(player1Wins, player2Wins, draws);

    while (playAgain == 'y' || playAgain == 'Y') {
        resetBoard(board);
        playGame(board, player1Wins, player2Wins, draws);
        writeBoardToFile(board, "final_board.txt");
        displayStats(player1Wins, player2Wins, draws);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }
    cout<<"\n\n\n";
    cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t\t\t                           THANKS FOR PLAYING                         " << endl;
    cout << "\t\t\t\t                               TIC TAC TOE                             " << endl;
    cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    return 0;
}
