#include <iostream>
#include <limits>
#include <queue>
#include <vector>

template<typename D>
struct link
{
  D destination;
  int length;
};

struct node
{
  int name;
  std::vector<link<node*>> links;
  int distance_from_root{std::numeric_limits<int>::max()};
};

void solve(std::vector<node>& nodes, node& root)
{
  std::queue<node*> queue;

  root.distance_from_root = 0;
  queue.push(&root);

  while (!queue.empty()) {
    auto* target = queue.front();
    queue.pop();

    for (const auto& link : target->links) {
      auto* neighbor = link.destination;
      const auto d = target->distance_from_root + link.length;
      if (neighbor->distance_from_root <= d) continue;
      neighbor->distance_from_root = d;
      queue.push(neighbor);
    }
  }
}

std::string distance_string(int distance)
{
  return distance == std::numeric_limits<int>::max()
      ? "INF"
      : std::to_string(distance);
}

int main()
{
  int node_count, link_count, root_name;
  std::cin >> node_count >> link_count >> root_name;

  std::vector<node> nodes(node_count);
  for (int i = 0; i < link_count; ++i) {
    int s, t, d;
    std::cin >> s >> t >> d;
    auto& n = nodes.at(s);
    n.name = s;
    n.links.push_back(link<node*>{&nodes.at(t), d});
  }

  solve(nodes, nodes.at(root_name));

  for (const auto& n : nodes) {
    std::cout << distance_string(n.distance_from_root) << std::endl;
  }
}

