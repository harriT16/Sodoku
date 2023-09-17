#include <iostream>
#include <vector>

const int N = 9;
int board[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

void printBoard() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << board[i][j] << ' ';
            if ((j + 1) % 3 == 0 && j < N - 1) std::cout << "| ";
        }
        std::cout << std::endl;
        if ((i + 1) % 3 == 0 && i < N - 1) {
            std::cout << std::string(21, '-') << std::endl;
        }
    }
}

bool isValid(int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) return false;
        if (board[x][col] == num) return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

int main() {
    int row, col, num;
    char choice;
    while (true) {
        printBoard();
        std::cout << "Enter the row (1-9) and column (1-9) where you want to place the number: ";
        std::cin >> row >> col;
        std::cout << "Enter the number (1-9) you want to place: ";
        std::cin >> num;

        if (row >= 1 && row <= 9 && col >= 1 && col <= 9 && num >= 1 && num <= 9) {
            if (isValid(row-1, col-1, num)) {
                board[row-1][col-1] = num;
            } else {
                std::cout << "Invalid move. Try again.\n";
            }
        } else {
            std::cout << "Invalid input. Try again.\n";
        }

        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') break;
    }
    return 0;
}
