#include <iostream>
#include <string>

std::string spaces_str(std::string str);

bool is_spam(std::string str);

int main() {
	setlocale(LC_ALL, "Russian");

	system("chcp 1251 > null");
	int n;

	// Задача 1. Добавление пробелов после каждого символа

	/*std::cout << "Задача 1.\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);

	std::cout << spaces_str(str1) << "\n\n";*/

	// Задача 2. Проверка на спам

	/*std::cout << "Задача 2.\nВведите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);

	if (is_spam(str2))
		std::cout << "Обнаружен спам!\n\n";
	else
		std::cout << "Спам не обнаружен!\n\n";*/


	// Задача 3. URL страницы

	/*std::cout << "Задача 3.\nАдрес: ";
	std::string URL = "https://vk.com/home/music";

	int domen_index = URL.find("://") + 3;
	int path_index = URL.find('/', domen_index) + 1;

	std::cout << URL << std::endl;

	std::string protocol = URL.substr(0,domen_index - 3);
	std::string domen = URL.substr(domen_index,path_index - 1 - domen_index);
	std::string path = URL.substr(path_index);

	std::cout << "Протокол: " << protocol << std::endl;
	std::cout << "Доменн:   " << domen << std::endl;
	std::cout << "Путь:     " << path << "\n\n";*/


	// Задача 4. 






	return 0;
}

bool is_spam(std::string str) {
	// приведение строки к нижнему регитру для 
	// осуществления нерегистрозависимости
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);

	const int spams_number = 4;
	std::string spams[spams_number]{
		"100% free",
		"sales increase",
		"only today",
		"black friday"
	};

	for (int i = 0; i < spams_number; i++)
		if (str.find(spams[i]) < str.length())
			return true;
	return false;
}

std::string spaces_str(std::string str) {
	for (int i = str.length() - 1; i > 0; i--)
		str.insert(i," ");

	return str;
}
