
#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
	const char *path = "./helloCPP.txt";
	std::string str = "Hello, world";

	std::ofstream ofs(path);
	ofs << str << std::endl;

	std::ifstream ifs(path);
	std::string buf((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

	std::cout << "read " << buf << std::endl;
	return 0;
}
