// My solution----

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& books, int numStudents, int maxPages) {
    int studentCount = 1;
    int pageSum = 0;
    int n = books.size();
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + books[i] <= maxPages) {
            pageSum += books[i];
        }
        else
        {
            studentCount++;
            if(studentCount > numStudents || books[i] > maxPages ) {
                return false;
            }
            pageSum = books[i];
        }
        if(studentCount > numStudents) {
            return false;
        }
    }
    return true;
}

int bookAllocationHelper(vector<int>& books, int numStudents, int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (isPossible(books, numStudents, mid)) {
        // If allocation is possible with mid as maximum pages,
        // try to minimize the maximum pages
        int leftResult = bookAllocationHelper(books, numStudents, left, mid - 1);
        if (leftResult != -1) {
            return leftResult;
        } else {
            return mid;
        }
    } else {
        // If allocation is not possible with mid as maximum pages,
        // try a greater value of maxPages
        return bookAllocationHelper(books, numStudents, mid + 1, right);
    }
}

int bookAllocation(vector<int>& books, int numStudents) {
    int n = books.size();
    if (n < numStudents) {
        return -1; // More students required than books, not possible
    }

    int totalPages = 0;
    for (int i = 0; i < n; i++) {
        totalPages += books[i];
    }

    int left = 0; // Minimum number of pages a student can read
    int right = totalPages; // Maximum number of pages a student can read
    return bookAllocationHelper(books, numStudents, left, right);
}

int main() {
    int numStudents=2;

    vector<int> books = {10, 20, 30, 40};

    int result = bookAllocationHelper(books, numStudents, 0, 100);
    cout << "Minimum number of pages a student needs to read: " << result << endl;

    return 0;
}
//------****-----------------------------------------------------


#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& books, int numStudents, int maxPages) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < books.size(); i++) {
        if (books[i] > maxPages) {
            return false; // A book has more pages than maxPages, not possible
        }

        if (currentPages + books[i] > maxPages) {
            students++;
            currentPages = books[i];

            if (students > numStudents) {
                return false; // Too many students required, not possible
            }
        } else {
            currentPages += books[i];
        }
    }

    return true; // Allocation is possible with numStudents and maxPages
}

int bookAllocationHelper(vector<int>& books, int numStudents, int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (isPossible(books, numStudents, mid)) {
        // If allocation is possible with mid as maximum pages,
        // try to minimize the maximum pages
        int leftResult = bookAllocationHelper(books, numStudents, left, mid - 1);
        if (leftResult != -1) {
            return leftResult;
        } else {
            return mid;
        }
    } else {
        // If allocation is not possible with mid as maximum pages,
        // try a greater value of maxPages
        return bookAllocationHelper(books, numStudents, mid + 1, right);
    }
}

int bookAllocation(vector<int>& books, int numStudents) {
    int n = books.size();
    if (n < numStudents) {
        return -1; // More students required than books, not possible
    }

    int totalPages = 0;
    for (int i = 0; i < n; i++) {
        totalPages += books[i];
    }

    int left = 0; // Minimum number of pages a student can read
    int right = totalPages; // Maximum number of pages a student can read
    return bookAllocationHelper(books, numStudents, left, right);
}

int main() {
    int n, numStudents;
    cout << "Enter the number of books: ";
    cin >> n;

    vector<int> books(n);
    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    cout << "Enter the number of students: ";
    cin >> numStudents;

    int result = bookAllocation(books, numStudents);
    if (result == -1) {
        cout << "Not possible to allocate books with given number of students." << endl;
    } else {
        cout << "Minimum number of pages a student needs to read: " << result << endl;
    }

    return 0;
}
