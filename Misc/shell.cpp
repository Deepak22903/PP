#include <cctype>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sys/wait.h> // for wait()
#include <unistd.h>
#include <vector>
using namespace std;

vector<string> takeInput() {
  cout << "Prompt> ";
  string input;
  getline(cin, input);
  vector<string> arguments;
  for (int i = 0; i < input.size(); i++) {
    string argv{};
    while (i < input.size() && !isspace(input[i])) {
      argv += input[i];
      i++;
    }
    arguments.push_back(argv);
  }
  return arguments;
}

int main(int argc, char *argv[]) {
  vector<string> argvMy;
  while (1) {
    argvMy = takeInput();
    string command = argvMy[0];
    argvMy.erase(argvMy.begin());
    vector<char *> args;
    args.push_back(const_cast<char *>(command.c_str()));
    for (auto &arg : argvMy) {
      args.push_back(const_cast<char *>(arg.c_str()));
    }
    int pid = vfork();
    if (pid == 0) {
      execvp(command.c_str(), args.data());
    } else {
      wait(NULL);
    }
  }

  return 0;
}
