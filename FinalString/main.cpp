#include <iostream>
#include <string>

std::string spaces_str(std::string str);

bool is_spam(std::string str);

int str_sum(std::string str);

std::string lowerCamelCase(std::string str);

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


	// Задача 4. Результат из строки суммы чисел

	/*std::cout << "Задача 4.\nВведите строку -> ";
	std::string str4;
	std::getline(std::cin, str4);

	std::cout << "Summ value = " << str_sum(str4) << "\n\n";*/

	// Задача 5. lowerCamelCase желаемое имя переменной

	std::cout << "Задача 5.\n";

	std::cout << "Hello World = " << lowerCamelCase("Hello World") << "\n\n";
	std::cout << "my old friends = " << lowerCamelCase("my old friends") << "\n\n";
	std::cout << "Oranges = " << lowerCamelCase("Oranges") << "\n\n";



	return 0;
}


std::string lowerCamelCase(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = std::tolower(str[i]);
	}
	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < str.length(); i++) {
		index2 = str.find(" ", index1);
		if (index2 != -1) {
			str[index2 + 1] = std::toupper(str[index2 + 1]);
			str.replace(index2,1,"");
			index1 = index2;
		}
	}
	return str;
}


int str_sum(std::string str) {
	int index1 = 0;
	int index2 = 0;
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		
		if (index2 != -1) {
			index2 = str.find("+", index1);
			sum += std::stoi(str.substr(index1, index2 - index1));
			index1 = index2 + 1;
		}
		
	}
	
	return sum;
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
