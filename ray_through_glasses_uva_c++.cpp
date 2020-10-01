#include<iostream>
using namespace std;

int main()
{
    // Generating Large Numbers (Fibonacci Series) With c++
    // Digit by Digit addition technique

    short int input;
    
    while (cin >> input)
    {
        if(input == 0)
        {
            cout << 1 <<endl;
            continue;
        }

        if(input == 1)
        {
            cout << 2 <<endl;
            continue;
        }

        input--;

        string num1, num2, result;
        num1 = "1", num2 = "2", result = "";
        short int tempResult;
        bool overflow = false;
        char tmpChar;

        while(input--)
        {
            int num1Len = num1.size() - 1;
            int num2Len = num2.size() - 1;

            while (num1Len >= 0)
            {
                tempResult = overflow == true ? (num2[num2Len] - '0') + (num1[num1Len] - '0') + 1 
                                            : (num2[num2Len] - '0') + (num1[num1Len] - '0');
                
                if(tempResult > 9)
                {
                    overflow = true;
                    tmpChar = (tempResult%10) + '0';
                }
                else
                {
                    overflow = false;
                    tmpChar = tempResult + '0';
                }

                result = tmpChar + result;

                num1Len--;
                num2Len--;
                
            } //num1 length ends here

            while (num2Len >= 0) //num2 length check
            {
                if(overflow)
                    tempResult = (num2[num2Len] - '0') + 1;
                else
                    break;

                if(tempResult > 9)
                {
                    overflow = true;
                    result = '0' + result;
                }
                else
                {
                    overflow = false;
                    tmpChar = tempResult + '0';
                    result = tmpChar + result;
                }
                
                num2Len--;
            }

            if(num2Len < 0) //if num2 length still persists
            {
                if(overflow)
                    result = '1' + result;
            }
            else
            {
                while (num2Len >= 0) // handling the rest of numbers with no overflow 
                {
                    result = num2[num2Len] + result;
                    num2Len--;
                }
            }

            num1 = num2;
            num2 = result;
            result = "";
            overflow = false;
        }

        cout << num2 <<endl;
    }

    return 0;
}