//eightQueens.cpp
#include <iostream>
#include <vector>
#include <cmath>

struct cell {
    int x, y;
};

class EightQueensSolver {
private:
    int boardSize;
    std::vector<std::vector<cell>> solutions;

public:
    EightQueensSolver(int size) : boardSize(size) {}

    bool noAttack(const std::vector<cell>& queens, const cell& candidate) {
        for (const auto& queen : queens) {
            if (queen.x == candidate.x || queen.y == candidate.y ||
                std::abs(candidate.y - queen.y) == std::abs(candidate.x - queen.x)) {
                return false;
            }
        }
        return true;
    }

    void solve(int row, std::vector<cell>& queens) {
        if (row == boardSize) {
            solutions.push_back(queens);
            return;
        }

        for (int col = 0; col < boardSize; ++col) {
            cell candidate = {row, col};
            if (noAttack(queens, candidate)) {
                queens.push_back(candidate);
                solve(row + 1, queens);
                queens.pop_back();  // Backtrack
            }
        }
    }

    void solve() {
        std::vector<cell> queens;
        solve(0, queens);
    }

    void displaySolutions() const {
        for (const auto& solution : solutions) {
            for (const auto& queen : solution) {
                std::cout << "( " << queen.x << " , " << queen.y << " ) ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    EightQueensSolver solver(8);
    solver.solve();
    solver.displaySolutions();

    return 0;
}
