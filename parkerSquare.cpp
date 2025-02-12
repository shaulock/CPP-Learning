#include <iostream>
#include <cstdint>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

bool checkPerfectSquare(uint64_t number) {
    if (number == 0) {
        return false;
    }
    int lastDigit = number % 10;
    if (lastDigit == 2 || lastDigit == 3 || lastDigit == 7 || lastDigit == 8) {
        return false;
    } else if (lastDigit == 5 && number % 100 != 25) {
        return false;
    } else if (lastDigit == 0) {
        while (number > 0) {
            if (number % 10 != 0) {
                break;
            }
            if (number % 100 != 0 && number % 10 == 0) {
                return false;
            }
            number /= 100;
        }
    } 
    uint64_t sqrtNumber = sqrt(number);
    return (sqrtNumber * sqrtNumber) == number;
}

string formatInt(uint64_t number, int offset=0) {
    string formattedNumber = "";
    int count = 0;
    int digitCount = 0;
    int commaCount = 0;
    if (number == 0) {
        formattedNumber = "0";
        for (int i = 0; i < offset - 1; i++) {
            formattedNumber = " " + formattedNumber;
        }
        return formattedNumber;
    }
    while(number > 0) {
        if (count == 3) {
            formattedNumber = "," + formattedNumber;
            commaCount++;
            count = 0;
        }
        formattedNumber = to_string(number%10) + formattedNumber;
        number /= 10;
        count++;
        digitCount++;
    }
    for (int i = 0; i < offset - (digitCount+commaCount); i++) {
        formattedNumber = " " + formattedNumber;
    }
    return formattedNumber;
}

string to_string(int i) {
    string s = "";
    while(i > 0) {
        s = char('0' + (i % 10)) + s;
        i /= 10;
    }
    return s;
}

bool isPowerOfTen(uint64_t number) {
    if (number == 0) {
        return false;
    }
    while (number > 1) {
        if (number % 10 != 0) {
            return false;
        }
        number /= 10;
    }
    return true;
}

int countDigits(uint64_t number) {
    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

class threeNumberSum {
    public:
        uint64_t a;
        uint64_t b;
        uint64_t c;

        list<threeNumberSum> generateAllPermutations() {
            list<threeNumberSum> permutations;
            threeNumberSum perm1;
            perm1.a = a;
            perm1.b = b;
            perm1.c = c;
            permutations.push_back(perm1);
            threeNumberSum perm2;
            perm2.a = a;
            perm2.b = c;
            perm2.c = b;
            permutations.push_back(perm2);
            threeNumberSum perm3;
            perm3.a = b;
            perm3.b = a;
            perm3.c = c;
            permutations.push_back(perm3);
            threeNumberSum perm4;
            perm4.a = b;
            perm4.b = c;
            perm4.c = a;
            permutations.push_back(perm4);
            threeNumberSum perm5;
            perm5.a = c;
            perm5.b = a;
            perm5.c = b;
            permutations.push_back(perm5);
            threeNumberSum perm6;
            perm6.a = c;
            perm6.b = b;
            perm6.c = a;
            permutations.push_back(perm6);
            return permutations;
        }
};


class threeNumberSumArray {
    private:
        list<threeNumberSum> array;
        int size;
        int biggestACount;
        int biggestBCount;
        int biggestCCount;

    public:
        uint64_t commonSum;
        threeNumberSumArray(uint64_t sum) {
            size = 0;
            biggestACount = 0;
            biggestBCount = 0;
            biggestCCount = 0;
            commonSum = sum;
            array = {};
        }

        int getSize() {
            return size;
        }

        uint64_t getCommonSum() {
            return commonSum;
        }

        list<threeNumberSum> getArray() {
            return array;
        }

        void addToArray(threeNumberSum sum) {
            array.push_back(sum);
            size++;
            updateBiggestACount(countDigits(sum.a));
            updateBiggestBCount(countDigits(sum.b));
            updateBiggestCCount(countDigits(sum.c));
        }

        void updateBiggestACount(int count) {
            if (count > biggestACount) {
                biggestACount = count;
            }
        }

        void updateBiggestBCount(int count) {
            if (count > biggestBCount) {
                biggestBCount = count;
            }
        }

        void updateBiggestCCount(int count) {
            if (count > biggestCCount) {
                biggestCCount = count;
            }
        }

        void printArray() {
            cout << endl;
            cout << "Common Sum: " << commonSum << endl;
            cout << "Size: " << size << endl;
            for (auto it = array.begin(); it != array.end(); it++) {
                cout << "a: " << formatInt(it->a, biggestACount) << " b: " << formatInt(it->b, biggestBCount) << " c: " << formatInt(it->c, biggestCCount) << endl;
            }
            cout << endl;
        }

        threeNumberSum getElementAt(int index) {
            int count = 0;
            for (auto it = array.begin(); it != array.end(); it++, count++) {
                if (count == index) {
                    return *it;
                }
            }
            return {};
        }
};

bool findThreeNumberSums(uint64_t number, threeNumberSumArray* sumArray) {
    for (uint64_t i = 1; i <= number; i++) {
        for (uint64_t j = 1; j <= number; j++) {
            for (uint64_t k = 1; k <= number; k++) {
                if (i + j + k == number && i != j && j != k && i != k) {
                    threeNumberSum sum;
                    sum.a = i;
                    sum.b = j;
                    sum.c = k;
                    sumArray->addToArray(sum);
                }
            }
        }
    }
    bool found = sumArray->getSize() > 0;
    return found;
}

struct threeNumbers {
    uint64_t a;
    uint64_t b;
    uint64_t c;
};

struct magicSquare {
    uint64_t row1column1;
    uint64_t row1column2;
    uint64_t row1column3;
    uint64_t row2column1;
    uint64_t row2column2;
    uint64_t row2column3;
    uint64_t row3column1;
    uint64_t row3column2;
    uint64_t row3column3;
};

bool findThreeNumberSquareSums(uint64_t number, threeNumberSumArray* sumArray) {
    for (uint64_t i = 1; i <= number; i++) {
        for (uint64_t j = 1; j <= number; j++) {
            for (uint64_t k = 1; k <= number; k++) {
                if (i + j + k == number && checkPerfectSquare(i) && checkPerfectSquare(j) && checkPerfectSquare(k) && i != j && j != k && i != k) {
                    threeNumberSum sum;
                    sum.a = i;
                    sum.b = j;
                    sum.c = k;
                    sumArray->addToArray(sum);
                }
            }
        }
    }
    bool found = sumArray->getSize() > 0;
    return found;
}

magicSquare generateMagicSquare(uint64_t number) {
    threeNumberSumArray sumArray = threeNumberSumArray(number);
    if (!findThreeNumberSquareSums(number, &sumArray)) {
        return {0, 0, 0, 0, 0, 0, 0, 0, 0};
    }
    if (sumArray.getSize() < 8) {
        return {0, 0, 0, 0, 0, 0, 0, 0, 0};
    }
    list<uint64_t> array = {};
    for (uint64_t i = 1; i <= sumArray.getSize(); i++) {
        array.push_back(i);
    }
    for (auto it = array.begin(); it != array.end(); it++) {
        for (auto it2 = array.begin(); it2 != array.end(); it2++) {
            for (auto it3 = array.begin(); it3 != array.end(); it3++) {
                if (it != it2 && it2 != it3 && it != it3) {
                    list<uint64_t> perm;
                    perm.push_back(*it);
                    perm.push_back(*it2);
                    perm.push_back(*it3);
                    list<struct threeNumbers> threeNumbers = {};
                    bool skipFlag = false;
                    for (auto it142 = perm.begin(); it142 != perm.end(); it142++) {
                        struct threeNumbers threeNumberArray = {};
                        threeNumberSum sum = sumArray.getElementAt(*it142);
                        threeNumberArray.a = sum.a;
                        threeNumberArray.b = sum.b;
                        threeNumberArray.c = sum.c;

                        for (auto it143 = threeNumbers.begin(); it143 != threeNumbers.end(); it143++) {
                            if (it143->a == sum.a || it143->a == sum.b || it143->a == sum.c || it143->b == sum.a || it143->b == sum.b || it143->b == sum.c || it143->c == sum.a || it143->c == sum.b || it143->c == sum.c) {
                                skipFlag = true;
                                break;
                            }
                        }
                        if (skipFlag) {
                            break;
                        }
                        threeNumbers.push_back(threeNumberArray);
                    }
                    if (skipFlag) {
                        continue;
                    }
                    magicSquare square = {};
                    int count = 0;
                    for (auto it142 = threeNumbers.begin(); it142 != threeNumbers.end(); it142++) {
                        if (count == 0) {
                            square.row1column1 = it142->a;
                            square.row2column1 = it142->b;
                            square.row3column1 = it142->c;
                        } else if (count == 1) {
                            square.row1column2 = it142->a;
                            square.row2column2 = it142->b;
                            square.row3column2 = it142->c;
                        } else if (count == 2) {
                            square.row1column3 = it142->a;
                            square.row2column3 = it142->b;
                            square.row3column3 = it142->c;
                        }
                        count++;
                    }
                    if (square.row1column1 == 0 || square.row1column2 == 0 || square.row1column3 == 0 || square.row2column1 == 0 || square.row2column2 == 0 || square.row2column3 == 0 || square.row3column1 == 0 || square.row3column2 == 0 || square.row3column3 == 0) {
                        continue;
                    }
                    uint64_t sum = number;
                    if (square.row1column1 + square.row1column2 + square.row1column3 != sum) {
                        continue;
                    }
                    if (square.row2column1 + square.row2column2 + square.row2column3 != sum) {
                        continue;
                    }
                    if (square.row3column1 + square.row3column2 + square.row3column3 != sum) {
                        continue;
                    }
                    if (square.row1column1 + square.row2column2 + square.row3column3 != sum) {
                        continue;
                    }
                    if (square.row1column3 + square.row2column2 + square.row3column1 != sum) {
                        continue;
                    }
                    return square;
                }
            }
        }
    }
    return {0, 0, 0, 0, 0, 0, 0, 0, 0};
}

int main() {
    cout << "Maximum Number Possible: " << formatInt(UINT64_MAX) << endl;
    cout << "Common Sum Checking\t" << endl;
    srand(time(0));
    while (true) {
        uint64_t number = rand() % UINT64_MAX;
        while (number < 2917) {
            number = rand() % UINT64_MAX;
        }
        cout << formatInt(number, 26) << ": ";
        auto generatedMagicSquare = generateMagicSquare(number);
        if (generatedMagicSquare.row1column1 != 0) {
            cout << "Successful!" << endl;
            int biggestA = countDigits(generatedMagicSquare.row1column1) > countDigits(generatedMagicSquare.row1column2) ? countDigits(generatedMagicSquare.row1column1) : countDigits(generatedMagicSquare.row1column2);
            biggestA = biggestA > countDigits(generatedMagicSquare.row1column3) ? biggestA : countDigits(generatedMagicSquare.row1column3);
            biggestA += (biggestA - 1) / 3;
            int biggestB = countDigits(generatedMagicSquare.row2column1) > countDigits(generatedMagicSquare.row2column2) ? countDigits(generatedMagicSquare.row2column1) : countDigits(generatedMagicSquare.row2column2);
            biggestB = biggestB > countDigits(generatedMagicSquare.row2column3) ? biggestB : countDigits(generatedMagicSquare.row2column3);
            biggestB += (biggestB - 1) / 3;
            int biggestC = countDigits(generatedMagicSquare.row3column1) > countDigits(generatedMagicSquare.row3column2) ? countDigits(generatedMagicSquare.row3column1) : countDigits(generatedMagicSquare.row3column2);
            biggestC = biggestC > countDigits(generatedMagicSquare.row3column3) ? biggestC : countDigits(generatedMagicSquare.row3column3);
            biggestC += (biggestC - 1) / 3;
            cout << formatInt(generatedMagicSquare.row1column1, biggestA) << "\t" << formatInt(generatedMagicSquare.row2column1, biggestB) << "\t" << formatInt(generatedMagicSquare.row3column1, biggestC) << endl;
            cout << formatInt(generatedMagicSquare.row1column2, biggestA) << "\t" << formatInt(generatedMagicSquare.row2column2, biggestB) << "\t" << formatInt(generatedMagicSquare.row3column2, biggestC) << endl;
            cout << formatInt(generatedMagicSquare.row1column3, biggestA) << "\t" << formatInt(generatedMagicSquare.row2column3, biggestB) << "\t" << formatInt(generatedMagicSquare.row3column3, biggestC) << endl;
            cout << endl;
            exit(0);
        } else {
            cout << "Failed!" << endl;
        }
    }
    // for (uint64_t i = 1364; i < UINT64_MAX; i++) {
        // 2917
    // }
    return 0;
}