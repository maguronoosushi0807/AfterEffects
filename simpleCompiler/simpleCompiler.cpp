#include<iostream>

namespace {
	constexpr int TYPE = 2;
	constexpr int CHARACTER_NUM = 26;
}

std::string dictionary[TYPE][CHARACTER_NUM][2]{
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

int main() {
	std::string script = "";
	std::string binary = "";

	while (script != "end") {
		std::cin >> script;
		binary = "";

		int length = script.length();
		for (int k = 0; k < length; k++) {
			for (int j = 0; j < TYPE; j++) {
				for (int i = 0; i < CHARACTER_NUM; i++) {

					if (script.substr(k, 1) == dictionary[j][i][1]) {
						binary += dictionary[j][i][0];
						//script.erase(0, 1);

						break;
					}

				}
			}
		}


		std::cout << binary << std::endl << std::endl;
	}

	return 0;
}