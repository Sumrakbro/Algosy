#include <iostream>
#include <conio.h>
#include <string>
//Чтобы узнать в какой строке будет стоять буква достаточно знать, сколько других букв есть перед ней и сколько раз она уже встретилась в столбце.
//За первый проход по столбцу мы подсчитываем, сколько и каких букв встретилось в строке.
using namespace std;
void solve(int N, int M, int k, string s) {

  int *count = new int[M];

  for (int i = 0; i < M; i++) {
    count[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    count[s[i]]++;
  }

  int sum = 0;
  for (int i = 0; i < M; i++) {
    sum += count[i];
    count[i] = sum - count[i];
  }
  //указывает на строку с предыдущей буквой 
  int *t = new int[M];
  for (int i = 0; i < N; i++) {
    t[count[s[i]]] = i;
    count[s[i]]++;
  }

  int j = t[k];
  char *result = new char[N];
  for (int i = 0; i < N; i++) {
    result[i] = s[j];
    j = t[j];
  }

  for (int i = 0; i < N; i++) {
    cout << result[i];
  }
  cout << endl;
}

int main() { 
  string s;
  int k;
  cin >> k;
  cin >> s;
  solve(s.size(), 1000000, k - 1, s);

  return 0;
}