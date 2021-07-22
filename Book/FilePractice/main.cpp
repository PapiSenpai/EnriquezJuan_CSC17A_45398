// fstream::open / fstream::close
#include <fstream>      // std::fstream

int main () {

  std::fstream fs;
  fs.open ("test2.txt", std::fstream::in| std::fstream::out| std::fstream::app);

  fs << "My butt is really fat.";

  fs.close();

  return 0;
}