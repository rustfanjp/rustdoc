#include <iostream>
#include <fstream>
#include <string>
#include <deque>

bool isvalid (std::string const & line)
{
  for (auto c : line) {
    if (!std::isalnum(c) && c != ' ' && c != '`' && c != ':' && c!= '-' && c != '#') {
      return false;
    }
  }
  return true;
}

void proc (std::string const & text, std::string & path)
{
  path.clear();
  for (auto c : text) {
    if ('a' <= c && c <= 'z') {
      path.push_back(c);
    } else if ('A' <= c && c <= 'Z') {
      path.push_back(c + ('a' - 'A'));
    } else if ('0' <= c && c <= '9') {
      path.push_back(c);
    } else if (c == ' ') {
      path.push_back('-');
    } else if (c == '-') {
      path.push_back('-');
    }
  }
  path.append(".md");
}

int parse_head (std::string const & line, std::string & text)
{
  if (line.size() == 0) { return 0; }
  auto it = line.begin();
  while (it != line.end() && *it == '#') { ++it; }
  if (it == line.begin()) { return 0; }
  int n = std::distance(line.begin(), it);
  if (n < 0 || n > 3) { return false; }
  while (it != line.end() && *it == ' ') { ++it; }
  if (!isvalid(line)) { return 0; } 
  text.assign(it, line.end());

  return n;
}

int main (int argc, char ** argv)
{
  if (argc < 2) { return 0; }

  std::ifstream ifs(argv[1]);
  std::ofstream ofs;
  std::string line;
  std::string text;
  std::string path;

  while (std::getline(ifs, line)) {
    int n = parse_head(line, text);
    if (n > 0) {
      proc(text, path);

      for (int i = 0; i < n - 1; ++i) {
        std::cout << "    ";
      }
      std::cout << "* " << "[" << text << "](" << path << ")" << std::endl;

      ofs.close();
      ofs.open(path);
      ofs << "% " << text << std::endl << std::endl;

      for (int i = 0; i < n; ++i) {
        ofs << "#";
      }
      ofs << " " << text << std::endl;
    } else {
      if (ofs.is_open()) {
        ofs << line << std::endl;
      }
    }
  }
}
