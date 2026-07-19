// hacktime Calculate calculator project
// i need the hp prime or cx II cas please let me spend 24 hours doing this
// lets init libs already
// i hope i didn't forget how to do this
// i forgot
// alright i remember now
#include <iostream>
#include <string>
// probably want more string utils
#include <sstream>
// i think there is something else i should include
// lets add the math libs
#include <cmath>
#include <random>
// we'll need vectors for this
#include <vector>
using namespace std;
// i guess we need some other ones
#include <algorithm>
#include <ranges>

// LETS ADD COLOR OUTPUT TO LOOK LIKE A REAL TERMINAL
const std::string reset   = "\033[0m";
const std::string red     = "\033[31m";
const std::string green   = "\033[32m";
const std::string yellow  = "\033[33m";
const std::string blue    = "\033[34m";

//global vars
int nextResult = 0;
int recentResult;
vector<string> results = {"recent3", "recent2", "recent1"}; // results will store the number from a calculation after the "recent1" part of the string

//----------FUNCTION DECLARATION SPACE----------
void continueResult() {
    recentResult = nextResult;
    if (nextResult == 2) nextResult = 0;
    else nextResult++;
}

unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double nroot(double base, double n ) {
    if (base <= 0 or n < 1) return 0;
    double result = pow(base, 1.0 / n);
    return result;
}

int main() {
    cout << "Termulator\nMade for hackclub calculate\nall code hand made by me :)" << endl;
    //init vars
    double a,b,c;
    int num1, num2;
    string currentFunction, uname, dir, input, arg1, arg2, calcInput, operation;
    vector<string> filesystem = {"results", "functions", "programs"};
    vector<string> functions = {"add", "subtract", "multiply", "divide", "power", "factorial", "root", "sin", "cos", "tan", "asin", "acos", "atan"};
    vector<string> programs = {"calculator", "pythagorean", "quadsolve", "randomnum"};
    bool inLoop = true;
    bool inCalc = false;
    //get username
    cout << "What would you like your username to be?";
    cin >> uname;
    cin.ignore(256, '\n'); //we need to ignore the newline in the buffer i guess
    while (inLoop) {
        cout << green << uname << "@termulator" << reset << ":"<< blue << "~" << reset << ((dir != "") ? "/" : "") << dir << "$";
        getline(cin, input);
        //time to start a really long if-else chain because c++ switch cases don't support std::string :(
        // ----------------------------------------help logic----------------------------------------
        if (input == "help") {
            cout << "Command list" << endl
            << "help: Displays list of commands" << endl
            << "dir: Lists directories" << endl 
            << "cd: changes current directory to specified one (usage: cd <directory>" << endl
            << "run: executes the given function or program (usage: run <program/function> <arg1> <arg2>)" << endl
            << "res: parses .res file (usage res <file.res>)" << endl
            << "clear: clears the terminal" << endl
            << "exit: ends the program" << endl
            << "";
        }
        // ----------------------------------------dir logic----------------------------------------
        else if (input == "dir") {
            if (dir == "") {
                for (const auto& folder : filesystem) {
                    cout << folder << " ";
                }
            }
            else if (dir == "functions") {
                for (const auto& function : functions) {
                    cout << function << " ";
                }
            }
            else if (dir == "programs") {
                for (const auto& program : programs) {
                    cout << program << " ";
                } 
            }
            else if (dir == "results") {
                cout << "result1.res " << "result2.res " << "result3.res";
            }
            cout << endl;
        }
        // ----------------------------------------cd logic----------------------------------------
        else if (input.starts_with("cd")) {
            if (input == "cd") dir = "";
            else if (std::find(filesystem.begin(), filesystem.end(), input.substr(3)) != filesystem.end()) { dir = input.substr(3); }
            else cout << "Destination does not exist in this directory" << endl;
        }
        // ----------------------------------------exit logic----------------------------------------
        else if (input == "exit") {
            inLoop = false;
        }
        // ----------------------------------------clear logic----------------------------------------
        else if (input == "clear") cout << "\033[2J\033[1;1H";
        // ----------------------------------------run logic----------------------------------------
        else if (input.starts_with("run")) {
            if (input == "run") { cout << "Usage: run <name>"; continue; }
            else if (dir == "" or dir == "results") { cout << "Program does not exist in this directory" << endl; continue; }
            stringstream ss(input);
            ss >> arg1 >> arg2 >> num1 >> num2;
            //-------------------------------------functions inside of run-------------------------------------
            if (dir == "functions") {
                if (arg2 == functions[0]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(num1 + num2));
                    cout << num1 + num2 << endl;
                    continueResult();
                }
                else if (arg2 == functions[1]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(num1 - num2));
                    cout << num1 - num2 << endl;
                    continueResult();
                }
                else if (arg2 == functions[2]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(num1 * num2));
                    cout << num1 * num2 << endl;
                    continueResult();
                }
                else if (arg2 == functions[3]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    if (num2 == 0) cout << "cannot divide by 0";
                    else {
                        results[nextResult].append(to_string(num1 / num2));
                        cout << num1 / num2 << endl;
                        continueResult();
                    }
                }
                else if (arg2 == functions[4]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(pow(num1, num2)));
                    cout << pow(num1, num2) << endl;
                    continueResult();
                }
                else if (arg2 == functions[5]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(factorial(num1)));
                    cout << factorial(num1) << endl;
                    continueResult();
                }
                else if (arg2 == functions[6]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(nroot(num1, num2)));
                    cout << nroot(num1, num2) << endl;
                    continueResult();
                }
                else if (arg2 == functions[7]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(sin(num1)));
                    cout << sin(num1) << endl;
                    continueResult();
                }
                else if (arg2 == functions[8]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(cos(num1)));
                    cout << cos(num1) << endl;
                    continueResult();
                }
                else if (arg2 == functions[9]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(tan(num1)));
                    cout << tan(num1) << endl;
                    continueResult();
                }
                else if (arg2 == functions[10]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(asin(num1)));
                    cout << asin(num1) << endl;
                    continueResult();
                }
                else if (arg2 == functions[11]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(acos(num1)));
                    cout << acos(num1) << endl;
                    continueResult();
                }
                else if (arg2 == functions[12]) {
                    results[nextResult] = ("recent" + to_string(nextResult));
                    results[nextResult].append(to_string(atan(num1)));
                    cout << atan(num1) << endl;
                    continueResult();
                }
            }
            else if (dir == "programs") {
                stringstream ss2(input);
                ss2 >> arg1 >> arg2;
                if (arg2 == "calculator") {
                    inCalc = true;
                    cout << endl << "Format for calculator use: '1 + 1'. Supported operations: +,-,*,/" << endl << "Note:Only integers are supported right now." << endl << "Run 'exit' to exit back to home" << endl;
                    while (inCalc) {
                        cout << endl;
                        getline(cin, calcInput);
                        if (calcInput == "exit") { inCalc = false; continue; }
                        stringstream ss3(calcInput);
                        ss3 >> arg1 >> operation >> arg2;
                        if (operation == "+") cout << (stoi(arg1) + stoi(arg2));
                        else if (operation == "-") cout << (stoi(arg1) - stoi(arg2));
                        else if (operation == "*") cout << (stoi(arg1) * stoi(arg2));
                        else if (operation == "/") {
                            if (arg2 == "0") cout << "cannot divide by zero";
                            else cout << (stoi(arg1) / stoi(arg2));
                        }
                        else cout << "Operation does not exist.";
                    }
                }
                else if (arg2 == "pythagorean") {
                    cout << "Enter '0' for the unknown value" << endl;
                    cout << "a:";
                    cin >> a;
                    cout << "b:";
                    cin >> b;
                    cout << "c:";
                    cin >> c;
                    cin.ignore(256, '\n');
                    if (a == 0) cout << nroot(pow(b, 2) + pow(c, 2), 2) << endl;
                    else if (b == 0) cout << nroot(pow(a, 2) + pow(c, 2), 2) << endl;
                    else if (c == 0) cout << nroot(pow(a, 2) + pow(b, 2), 2) << endl;
                }
                else if (arg2 == "quadsolve") {
                    cout << "format: ax^2 + bx + c = 0" << endl;
                    cout << "a:";
                    cin >> a;
                    cout << "b:";
                    cin >> b;
                    cout << "c:";
                    cin >> c;
                    cin.ignore(256, '\n');
                    if (a == 0) cout << "Not a quadratic equation" << endl;
                    else if ((pow(b, 2) - (4 * a * c)) <= 0) cout << "Result is nonreal" << endl;
                    else {
                        cout << ((0 - b) + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a) << endl;
                        cout << "or" << endl;
                        cout << ((0 - b) - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a) << endl;
                    }
                }
                else if (arg2 == "randomnum") {
                    cout << "only use integers" << endl;
                    cout << "lower limit:";
                    cin >> a;
                    cout << endl << "upper limit:";
                    cin >> b;
                    cin.ignore(256, '\n');
                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<int> distrib((int)a, (int)b);
                    int rand_result = distrib(gen);
                    cout << rand_result << endl;
                }
            }
        }
        // ----------------------------------------res logic----------------------------------------
        else if (input.starts_with("res")) {
            stringstream ss(input);
            ss >> arg1 >> arg2;
            if (arg2 == "result1.res") cout << results[0] << endl;
            else if (arg2 == "result2.res") cout << results[1] << endl;
            else if (arg2 == "result3.res") cout << results[2] << endl;
            else cout << "File does not exist" << endl;
        }
        // ----------------------------------------undefined logic----------------------------------------
        else { cout << "Command does not exist, run 'help' for a list of commands." << endl; }
    }
    return 0;
}