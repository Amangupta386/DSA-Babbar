#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& books, int numStudents, int mid) {
    int paintersCount = 1;
    int boardSum = 0;
    int n = board.size();
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + board[i] <= mid) {
            boardSum += board[i];
        }
        else
        {
            paintersCount++;
            if(paintersCount > numPainters || board[i] > mid ) {
                return false;
            }
            boardSum = board[i];
        }
        if(paintersCount > numPainters) {
            return false;
        }
    }
    return true;
}

int painterPartionHelper(vector<int>& boards, int numPainters, int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (isPossible(boards, numPainters, mid)) {
        // If allocation is possible with mid as maximum pages,
        // try to minimize the maximum pages
        int leftResult = painterPartionHelper(boards, numPainters, left, mid - 1);
        if (leftResult != -1) {
            return leftResult;
        } else {
            return mid;
        }
    } else {
        // If allocation is not possible with mid as maximum pages,
        // try a greater value of maxPages
        return painterPartionHelper(boards, numPainters, mid + 1, right);
    }
}

int bookAllocation(vector<int>& boards, int numPainters) {
    int n = boards.size();
    if (n < numPainters) {
        return -1; // More students required than books, not possible
    }

    int totalBoards = 0;
    for (int i = 0; i < n; i++) {
        totalBoards += boards[i];
    }

    int left = 0; // Minimum number of pages a student can read
    int right = totalBoards; // Maximum number of pages a student can read
    return painterPartionHelper(boards, numPainters, left, right);
}

int main() {
    int numStudents=2;

    vector<int> boards = {5, 5, 5, 5};

    int result = painterPartionHelper(boards, numPainters, 0, 20);
    cout << "Minimum number of pages a student needs to read: " << result << endl;

    return 0;
}
