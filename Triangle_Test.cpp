#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Hàm xử lý logic phân loại tam giác
string classifyTriangle(int a, int b, int c) {
    if (a < 1 || a > 100 || b < 1 || b > 100 || c < 1 || c > 100) {
        return "Invalid Input";
    }

    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        return "Not a Triangle";
    }

    if (a == b && b == c) {
        return "Equilateral";
    } else if (a == b || b == c || a == c) {
        return "Isosceles";
    } else {
        return "Scalene";
    }
}

void runTests() {
    // ---------------------------------------------------------
    // Nhóm 1: Invalid Inputs - Dựa trên biên
    // ---------------------------------------------------------
    assert(classifyTriangle(0, 50, 50) == "Invalid Input");   // TC 01: a < 1
    assert(classifyTriangle(101, 50, 50) == "Invalid Input"); // TC 02: a > 100
    assert(classifyTriangle(50, 0, 50) == "Invalid Input");   // TC 03: b < 1
    assert(classifyTriangle(50, 50, 101) == "Invalid Input"); // TC 04: c > 100

    // ---------------------------------------------------------
    // Nhóm 2: Kiểm tra logic nghiệp vụ dựa trên Decision Table
    // ---------------------------------------------------------
    // Rule 1: Không phải tam giác
    assert(classifyTriangle(10, 20, 50) == "Not a Triangle"); // TC 05: Tổng 2 cạnh nhỏ hơn cạnh còn lại
    assert(classifyTriangle(1, 2, 3) == "Not a Triangle");    // TC 06: Chạm biên bất đẳng thức (1+2=3)

    // Rule 2: đều
    assert(classifyTriangle(50, 50, 50) == "Equilateral");    // TC 07: Giá trị giữa hợp lệ
    assert(classifyTriangle(100, 100, 100) == "Equilateral"); // TC 08: Chạm biên lớn nhất

    // Rule 3, 4, 5: cân
    assert(classifyTriangle(50, 50, 40) == "Isosceles");      // TC 09: Cân tại c (a=b)
    assert(classifyTriangle(40, 50, 50) == "Isosceles");      // TC 10: Cân tại a (b=c)
    assert(classifyTriangle(50, 40, 50) == "Isosceles");      // TC 11: Cân tại b (a=c)

    // Rule 6: thường
    assert(classifyTriangle(3, 4, 5) == "Scalene");           // TC 12: 3 cạnh khác nhau
    assert(classifyTriangle(98, 99, 100) == "Scalene");       // TC 13: 3 cạnh khác nhau, áp sát biên trên

    cout << "passed" << endl;
}

int main() {
    runTests();
    return 0;
}
