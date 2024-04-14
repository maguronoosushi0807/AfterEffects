#include<cstdlib>
#include<fstream>
#include<iostream>
#include<regex>
#include<string>

namespace {
	constexpr unsigned int CHARACTER_TYPE = 2;
	constexpr unsigned int CHARACTER_NUM = 26;
}

std::string character[CHARACTER_TYPE][CHARACTER_NUM][2]{
	{
		{"jB","a"},
		{"jC","b"},
		{"jD","c"},
		{"jE","d"},
		{"jF","e"},
		{"jG","f"},
		{"jH","g"},
		{"jI","h"},
		{"jJ","i"},
		{"jK","j"},
		{"jL","k"},
		{"jM","l"},
		{"jN","m"},
		{"jO","n"},
		{"jP","o"},
		{"jQ","p"},
		{"jR","q"},
		{"jS","r"},
		{"jT","s"},
		{"jU","t"},
		{"jV","u"},
		{"jW","v"},
		{"jX","w"},
		{"jY","x"},
		{"jZ","y"},
		{"ja","z"}
	},
	{
		{"iB","A"},
		{"iC","B"},
		{"iD","C"},
		{"iE","D"},
		{"iF","E"},
		{"iG","F"},
		{"iH","G"},
		{"iI","H"},
		{"iJ","I"},
		{"iK","J"},
		{"iL","K"},
		{"iM","L"},
		{"iN","M"},
		{"iO","N"},
		{"iP","O"},
		{"iQ","P"},
		{"iR","Q"},
		{"iS","R"},
		{"iT","S"},
		{"iU","T"},
		{"iV","U"},
		{"iW","V"},
		{"iX","W"},
		{"iY","X"},
		{"iZ","Y"},
		{"ia","Z"}
	}
};

// .jsxbib binary
// .jsx    script


int main() {
	std::string dir = "jsx/string.jsxbin";
	//std::cin >> dir;
	std::ifstream file(dir);

	std::string binary = "";
	std::string script = "";

	if (!file) {
		std::cout << "Failed to read the file." << std::endl;
		return -1;
	}

	//get all lines from the file
	std::string line;
	while (std::getline(file, line)) {
		binary += line;
	}
	std::cout << "Start reverse" << std::endl;


	//Reverse
	//delete front
	std::string front = "@JSXbinary@ES@2.0@MyB";
	binary.erase(0, front.length());


	std::string director = "";
	char text_length = 0;
	bool string_flag = false;

	while (binary!="") {
		director = binary.substr(0, 2);
		// "" string
		if (director == "Fe") {
			string_flag = true;
			binary.erase(0, 2);
			text_length = binary[0];
			text_length -= 65;
			binary.erase(0, 1);
			script += "\"";
		}

		for (int k = 0; k < text_length; k++) {
			for (int j = 0; j < CHARACTER_TYPE; j++) {
				for (int i = 0; i < CHARACTER_NUM; i++) {
					if (binary.substr(0, 2) == character[j][i][0]) {
						script += character[j][i][1];
						script.erase(0, 2);
					}

				}
			}
		}

		if (string_flag == true) {
			script += "\"";
			string_flag = false;
		}

	}

	std::cout << script;

	std::cout << std::endl << std::endl << "----------------" << std::endl << std::endl << std::endl;
	std::system("pause");
	return 0;
}