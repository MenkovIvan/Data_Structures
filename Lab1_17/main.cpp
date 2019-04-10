#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    int n; // number of numbers
    int number; // number
    cout << "Write number of numbers" << endl;
    cin >> n;

    for ( int i = 0; i < n; i ++){
        cout << "Write number" << endl;
        cin >> number;
        Stack<int> stack1;
        Stack<int> stack2;
        int count = 0; //shetchik;
        while (number > 0){
            stack1.push(number%10);
            number=number/10;
            count++;
        }
        stack1.printStack();
        for (int j = 0; j < count; j++){
            stack2.push(stack1.pop());
        }
        cout << endl;
        stack2.printStack();
        int numberOut = 0;
        for (int j = 0; j < count; j++){
            numberOut = numberOut * 10;
            numberOut = numberOut + stack2.pop();
        }
        cout << numberOut << endl;
    }


    return 0;
}