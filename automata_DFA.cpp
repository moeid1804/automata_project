#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a state in the DFA
struct State {
bool isAcceptState;
map<char, int> transitions;
};

int main() {
// Read the number of states in the DFA from the user
int numStates;
cout << "Enter the number of states: ";
cin >> numStates;

// Read the alphabet used by the DFA from the user
string alphabet;
cout << "Enter the alphabet symbols: ";
cin >> alphabet;

// Read the transition function for the DFA from the user
vector<State> states(numStates);
for (int i = 0; i < numStates; i++) {
cout << "Enter transitions for state " << i << ": ";
for (char c : alphabet) {
int nextState;
cout << "Enter next state for input " << c << ": ";
cin >> nextState;
states[i].transitions[c] = nextState;
}
}

// Read the start state and accept states for the DFA from the user
int startState;
cout << "Enter the start state: ";
cin >> startState;

cout << "Enter the accept states: ";
string acceptStatesStr;
cin >> acceptStatesStr;
for (char c : acceptStatesStr) {
int acceptState = c - '0';
states[acceptState].isAcceptState = true;
}
while(true){
// Read the string to be tested from the user
string str;
cout << "Enter the string to test: ";
cin >> str;

// Check whether the DFA accepts the string
int currentState = startState;
for (char c : str) {
currentState = states[currentState].transitions[c];
}
if (states[currentState].isAcceptState) {
cout << "The DFA accepts the string." << endl;
} else {
cout << "The DFA does not accept the string." << endl;
}
cout<<"if you want to test other string press c if you dont press x"<<endl;
char zz;
cin>>zz;
if(zz=='x'){break;}

}
return 0;
}
