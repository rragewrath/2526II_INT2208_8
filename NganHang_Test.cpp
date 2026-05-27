#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Hàm xử lý logic phê duyệt khoản vay
string processLoan(int age, double income, int credit_score, char employment) {
    if (age < 18 || age > 65) return "Invalid Input";
    if (income < 5.0 || income > 500.0) return "Invalid Input";
    if (credit_score < 300 || credit_score > 850) return "Invalid Input";
    if (employment != 'C' && employment != 'F') return "Invalid Input";

    string risk_level;
    if (credit_score >= 300 && credit_score <= 500) {
        risk_level = "High";
    } else if (credit_score >= 501 && credit_score <= 700) {
        risk_level = "Medium";
    } else { // 701 - 850
        risk_level = "Low";
    }

    if (risk_level == "High") {
        return "REJECT";
    }

    if (income < 15.0) {
        if (risk_level == "Medium" || employment == 'F') {
            return "REJECT";
        }
        return "MANUAL REVIEW";
    } else { // income >= 15.0
        if (employment == 'C') {
            return "APPROVE";
        } else { // employment == 'F'
            return "MANUAL REVIEW";
        }
    }
}

int main() {
    assert(processLoan(17, 20.0, 600, 'C') == "Invalid Input");  // TC 01
    assert(processLoan(66, 20.0, 600, 'C') == "Invalid Input");  // TC 02
    assert(processLoan(30, 4.9, 600, 'C') == "Invalid Input");   // TC 03
    assert(processLoan(30, 500.1, 600, 'C') == "Invalid Input"); // TC 04
    assert(processLoan(30, 20.0, 299, 'C') == "Invalid Input");  // TC 05
    assert(processLoan(30, 20.0, 851, 'C') == "Invalid Input");  // TC 06
    assert(processLoan(30, 20.0, 600, 'X') == "Invalid Input");  // TC 07

    assert(processLoan(18, 5.0, 300, 'F') == "REJECT");          // TC 08 (High Risk)
    assert(processLoan(65, 500.0, 500, 'C') == "REJECT");        // TC 09 (High Risk)
    assert(processLoan(30, 14.9, 501, 'C') == "REJECT");         // TC 10 (Med Risk, Inc < 15)
    assert(processLoan(30, 10.0, 701, 'F') == "REJECT");         // TC 11 (Low Risk, Inc < 15, 'F')
    assert(processLoan(30, 5.0, 850, 'C') == "MANUAL REVIEW");   // TC 12 (Low Risk, Inc < 15, 'C')
    assert(processLoan(30, 15.0, 600, 'C') == "APPROVE");        // TC 13 (Med/Low Risk, Inc >= 15, 'C')
    assert(processLoan(30, 500.0, 701, 'F') == "MANUAL REVIEW"); // TC 14 (Med/Low Risk, Inc >= 15, 'F')

    cout << "passed" << endl;
    return 0;
}
