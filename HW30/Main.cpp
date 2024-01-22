#include<iostream>
#include<string>
#include<fstream>

bool overwrite(std::string str, std::string str2) {
	static std::ifstream in;
	in.open(str);
	if (in.is_open()) {
		in.close();
		std::ofstream out;
		out.open(str);
		if (out.is_open()) {
			out << str2;
			return true;
		}
	}
	else
		return false;


}

int main() {
	setlocale(LC_ALL, "ru");

	std::string path = "file.txt";
	//Задача 1.
	std::ofstream out;
	out.open(path, std::ios::app);

	if (out.is_open()) {
		std::string str_out;
		do {
			std::cout << "Введите строку ->\n";
			std::getline(std::cin, str_out);
			out << str_out << '\n';
		} while (str_out != "end");
	}
	else
		std::cout << "Не удалось открыть файл";

	out.close();

	std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::string str;
		while (std::getline(in, str)) 
			std::cout << str << std::endl;
	}
	else
		std::cout << "Ошибка открытия файла";
	in.close();
	
	remove("file.txt");
	
	//Задача 2
	std::string path2 = "Test.txt";
	std::string str_remove = "ERROR";
	
	if (overwrite(path2, str_remove)) {
		std::cout << "True\n";
	}
	else
		std::cout << "False";



	return 0;
}