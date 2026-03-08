#include <iostream>
#include <cmath>
using namespace std;

// armstrong number is a number that equals the sum of its own digits each raised to the power of the total number of digits in the number
// For a 3-digit number like 153, verify it as 1^3 + 5^3 + 3^3 = 1+125+27 = 153

// function to find total digits
int digits (int num){
    int n = 0;
    while (num != 0) {
        num /= 10;
        n++;
    }
    return n;
}

// armstrong function core
bool isArmstrong(int num){
    int totalDigits = digits(num);
    int answer = 0, an = 0, power, rem;
    int originalNum = num;
    
    while (num!=0) {
        rem = num % 10;
        power = (int) (pow(rem, totalDigits) + 0.5);
        answer += power;
        num /= 10;
    }
    return answer == originalNum;
}

int main(){
    int number;
    cout << "Enter number : ";
    cin >> number;
    if (isArmstrong(number)){
        cout << "The number is an armstrong number." << endl;
    } else {
        cout << "The number is not an armstrong number." << endl;
    }
    return 0;
}