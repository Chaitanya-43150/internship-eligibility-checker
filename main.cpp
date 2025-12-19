#include <bits/stdc++.h>
using namespace std;

bool isBranchEligible(const string &branch, const vector<string> &branches) {
    for (string b : branches) {
        if (branch == b)
            return true;
    }
    return false;
}

int main() {
    double cgpa;
    int backlogs, year, choice;
    string branch;

    cout << "Enter CGPA: ";
    cin >> cgpa;

    cout << "Enter number of backlogs: ";
    cin >> backlogs;

    cout << "Enter year of study: ";
    cin >> year;

    cout << "Enter branch (CSE/ECE/EEE/DSAI/MnC/ME/CIVIL): ";
    cin >> branch;

    cout << "\nSelect Company Profile:\n";
    cout << "1. Company A\n";
    cout << "2. Company B\n";
    cout << "3. Company C\n";
    cout << "Enter choice: ";
    cin >> choice;

    double minCGPA;
    int maxBacklogs, minYear;
    vector<string> eligibleBranches;

    if (choice == 1) {
        minCGPA = 7.0;
        maxBacklogs = 0;
        minYear = 2;
        eligibleBranches = {"CSE", "ECE", "EEE"};
    } 
    else if (choice == 2) {
        minCGPA = 7.5;
        maxBacklogs = 1;
        minYear = 2;
        eligibleBranches = {"CSE", "DSAI", "MnC"};
    } 
    else if (choice == 3) {
        minCGPA = 6.5;
        maxBacklogs = 0;
        minYear = 3;
        eligibleBranches = {"CSE", "ECE", "EEE", "DSAI", "MnC", "ME", "CIVIL"};
    } 
    else {
        cout << "\nInvalid company selection\n";
        return 0;
    }

    bool eligible =
        cgpa >= minCGPA &&
        backlogs <= maxBacklogs &&
        year >= minYear &&
        isBranchEligible(branch, eligibleBranches);

    cout << "\nResult:\n";
    if (eligible) {
        cout << "Eligible for internship\n";
    } else {
        cout << "Not eligible for internship\n";

        if (cgpa < minCGPA)
            cout << "Reason: CGPA below required threshold\n";
        if (backlogs > maxBacklogs)
            cout << "Reason: Backlogs exceed allowed limit\n";
        if (year < minYear)
            cout << "Reason: Not in eligible year of study\n";
        if (!isBranchEligible(branch, eligibleBranches))
            cout << "Reason: Branch not eligible\n";
    }

    return 0;
}