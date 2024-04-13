#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>

namespace Constants {
	constexpr unsigned int TYPE = 3;
	constexpr unsigned int CHARACTER_NUM=26;
}

std::string character[Constants::TYPE][Constants::CHARACTER_NUM][2]{
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
	},
	{

	}
};

/*
std::string upper[26][2]{
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
	{"iz","Z"},
};
*/



int main() {
	std::ifstream file("jsx/ExpressionPaster.jsxbin");
	std::string line;

	if (!file) {
		std::cout << "�t�@�C����ǂݍ��߂܂���ł����B" << std::endl;
	}
	else {
		unsigned int lineCount = 1;
		//bool isSearching = true;
		bool hasEnteredOneCharacter = false;
		std::string kaigyouBuff = "";

		while (true) {
			//�s����
			if (!std::getline(file, line))	break;

			//1�s�ڂ̏ꍇ�A�O�̕s�v�ȕ������폜
			if (lineCount == 1) {

				//std::getline(file, line);

				int headerEnd = line.find("MyB");
				line.erase(0, headerEnd + 18);
			}
			//�I�[��T���A�폜
			int eof = line.find("ByB");
			if (eof != std::string::npos) {
				line.erase(eof - 1, 10);
			}

			//�s����ɂȂ�܂Œ��ׂ�
			while (!line.empty()) {
				//�c��1�����ŉ��s���ꂽ
				if (!kaigyouBuff.empty()) {
					line = kaigyouBuff + line;
					kaigyouBuff.erase(0, 1);
					//std::cout << "�c��1�����ŉ��s����܂���" << line << std::endl;
				}


				//������̎c�肪1����
				if (line.size() == 1) {
					kaigyouBuff = line.substr(0, 1);
					//std::cout << "�̂���1���� : " << kaigyouBuff << std::endl;
					line.erase(0, 2);
				}

				//2�����擾
				std::string replaceBuff = line.substr(0, 2);
				line.erase(0, 1);

				//��v���镶���񂪂Ȃ������ׂ�
				for (int j = 0; j < Constants::TYPE; j++) {
					unsigned int searchedCount = 0;
					for (int i = 0; i < Constants::CHARACTER_NUM; i++) {
						if (replaceBuff == character[j][i][0]) {

							replaceBuff = character[j][i][1];
							std::cout << replaceBuff;
						}
						else {
							searchedCount++;
						}
					}

					//if (searchedCount == 26) std::cout << "��v���镶���񂪌�����܂���ł����B" << std::endl;
				}
			}
			//std::cout << std::endl;

			lineCount++;
		}
	}

	std::cout << std::endl << std::endl << "----------------" << std::endl << std::endl << std::endl;

	std::system("pause");
	return 0;
}

/*
int *a=NULL;
*a = 10;
*/


/*
			//�s��ϊ�
			while (!line.empty()) {

				std::string buff;
				lineBuff = line;
				std::cout << "�c��1�����ł�" << std::endl;

				//�c��1�����̏ꍇ

				buff = line.substr(0, 2);
				line.erase(0, 2);
				for (int i = 0; i < 26; i++) {
					if (buff == lower[i][0]) {
						buff = lower[i][1];
					}
				}

				std::cout << buff;
			}

			std::cout << std::endl;

			if (!std::getline(file, line)) {
				isSearching = false;
			}
*/