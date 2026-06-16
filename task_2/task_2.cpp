#include <iostream>
#include <vector>

// Класс графа
class Graph {
  int count_vertex = 0;
  std::vector<std::vector<int>> edges;

 public:
  // Конструктор преобразования
  Graph(int v) : count_vertex(v), edges(v) {
  }

  // Добавление ребра
  void AddEdge(int from, int to) {
    edges[from].push_back(to);
    edges[to].push_back(from);
  }

  // Получение смежных вершин
  std::vector<int> GetChildren(int v) {
    return edges[v];
  }

  // Обход в глубину
  void DFS(int v, std::vector<int>& visited) {
    visited[v] = 1;
    std::vector<int> children = GetChildren(v);
    for (int i = 0; i < children.size(); ++i) {
      if (visited[children[i]] == 0) {
        DFS(children[i], visited);
      }
    }
  }
};

int main() {

  int n, m;
  std::cin >> n >> m;

  Graph graph = n;
  std::vector<int> visited(n, 0);

  //Чтение графа
  int to, from;
  for (int i = 0; i < m; ++i) {
    std::cin >> from >> to;
    graph.AddEdge(from - 1, to - 1);
  }

  int cnt_components = 0;

  for (int i = 0; i < n; ++i) {
    if (visited[i] == 0) {
      graph.DFS(i, visited);
      ++cnt_components;
    }
  }

  std::cout << cnt_components - 1;
}
