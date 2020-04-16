#include<bits/stdc++.h>

using namespace std;


bool present(int x, int y, int n)
{
  if (x >= 1 && x <= n && y >= 1 && y <= n)
    return true;
  return false;
}

int findShortest(int n, int from[], int to[])
{
  bool visited[1000][1000];
  //copied
  int xdk[] = {-2, -1, 1, 2, -2, -1, 1, 2};
  int ydk[] = {-1, -2, -2, -1, 1, 2, 2, 1};

  queue<pair< pair < int, int>, int >> q;

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      visited[i][j] = false;
    }
  }

  q.push(make_pair(make_pair(from[0], from[1]), 0));

  visited[from[0]][from[1]] = true;

  while(q.empty() == false){

    auto t = q.front();
    q.pop();

    if (t.first.first == to[0] && t.first.second == to[1])
        return t.second;

    for (int i=0; i<8; i++)
    {
      auto x = t.first.first + xdk[i];
      auto y = t.first.second + ydk[i];
      // cout<< x<<endl;
      // cout<< y<<endl;
      if (present(x, y, n) && !visited[x][y]){
        visited[x][y] = true;
        q.push(make_pair(make_pair(x, y), t.second + 1));
      }
    }
  }


}

int main()
{
  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    int gx, gy; cin >> gx >> gy;

    int from[2] = {gx, gy};

    int fx, fy; cin >> fx >> fy;

    int to[2] = {fx, fy};

    int distance = findShortest(n, from, to);

    cout<< distance << endl;

  }
}
