#include <fstream>
#include <iostream>

void  transformInput(std::string& outInput, const std::string& s1, const std::string& s2)
{
  size_t  pos(0);
  do
  {
    pos = outInput.find(s1);
    if (pos == outInput.npos)
      break;
    outInput.erase(pos, s1.length());
    outInput.insert(pos, s2);
  }while (pos != outInput.npos);
}

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    std::cerr << "You need 3 arguments\n";
    return (1);
  }
  std::string fileName(argv[1]);
  std::ifstream infile(fileName.c_str());
  std::ofstream outfile(fileName.append(".replace").c_str());
  if (infile.is_open() && outfile.is_open())
  {
    std::string input;
    while (std::getline(infile, input))
    {
      transformInput(input, argv[2], argv[3]);
      outfile << input;
      outfile << std::endl;
    }
    infile.close();
    outfile.close();
  }
  else
  {
    std::cerr << "Error when opening the file" << std::endl;
    return (1);
  }
  return (0);
}
