class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> rows = std::vector<std::unordered_set<char>>(9);
        std::vector<std::unordered_set<char>> columns = std::vector<std::unordered_set<char>>(9);
        std::array<std::unordered_set<char>, 9> subboxes;

        for (int row = 0; row < 9; ++row)
        {
            const auto subboxRowIndex = row / 3;

            for (int col = 0; col < 9; ++col)
            {
                const auto subboxColIndex = col / 3;
                const char cellValue = board[row][col];

                if (std::isdigit(cellValue))
                {
                    const auto wasInsertedInRow = rows[row].insert(cellValue).second;
                    const auto wasInsertedInCol = columns[col].insert(cellValue).second;

                    const auto subboxIndexFlat = subboxRowIndex * 3 + subboxColIndex;

                    const auto wasInsertedInSubbox = subboxes[subboxIndexFlat].insert(cellValue).second;

                    if (!wasInsertedInRow || !wasInsertedInCol || !wasInsertedInSubbox)
                    { return false; }
                }
            }
        }

        return true;
    }
};
