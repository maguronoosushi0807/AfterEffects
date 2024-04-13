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

/*

 �S���擾
  ��
 ���`����
  ��
 ��������

*/

// .jsxbin bin
// .jsx    script


int main() {
	std::ifstream file("ExpressionPaster.jsx");
	std::string bin = "";
	std::string script = "";

	//�t�@�C���̓ǂݍ���
	if (!file) {
		std::cout << "�t�@�C����ǂݍ��߂܂���ł����B" << std::endl;
		return -1;
	}
	else {
		std::string line;
		while (std::getline(file, line)) {
			bin += line;
		}

		std::cout << "�R���p�C�����J�n���܂��B" << std::endl;
		//std::cout << bin;
	}
	/*
	else {
		std::string line;
		while (std::getline(file, line)) {
			bin += line;
		}

		//�擪�������폜
		std::string header = "@JSXBIN@ES@2.0@MyB";

		int header_position = bin.find(header);
		if (header_position == std::string::npos) {
			std::cout << "�\�����ꂽ�擪�v�f��������܂���ł����B" << std::endl;
		}
		else {
			bin.erase(header_position, header.length() + 14);
		}

		//��[�v�f���폜
		std::string footer = "ByB";
		int footer_position = bin.find(footer);
		if (footer_position == std::string::npos) {
			std::cout << "�\�����ꂽ��[�v�f��������܂���ł����B" << std::endl;
		}
		else {
			bin.erase(footer_position - 7, 7 + footer.length());
		}

		//std::cout << bin;
		std::cout << "�t�R���p�C�����J�n���܂��B" << std::endl << std::endl << std::endl;
	}


	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < CHARACTER_NUM; i++) {
			std::cout << character[0][i][1] << std::endl;
		}
	}


	//���s��u��������
	std::regex line_break{ R"(.*fJ.*nAjzB)" };	//���s�̐��K�\���i�������j
	std::string buf = bin;
	bin = std::regex_replace(buf, line_break, "\n");
	//std::cout << bin;

	//�ϊ�����, �ǂݍ��񂾃o�C�i���i�H�j����ɂȂ�܂Œ��ׂ�
	while (!bin.empty()) {
	}
	//2�����擾
	/*
	std::string replaceBuff = bin.substr(0, 2);
	bin.erase(0, 1);

	//��v���镶���񂪂Ȃ������ׂ�
	for (int j = 0; j < CHARACTER_TYPE; j++) {
		for (int i = 0; i < CHARACTER_NUM; i++) {
			int replacePos = 0;
			while (bin.find(character[j][i][0]) != std::string::npos) {
				replacePos = bin.find(character[j][i][0]);
				bin.replace(replacePos, 2, character[j][i][1]);
			}


		}
	}
	//break;

	std::cout << bin;
	*/

	uint32_t lineCount = 0;
	script += std::to_string(lineCount) + " ";

	//Compile
	while (!bin.empty()) {

		//���s
		if (bin.find("\n")==0) {
			script += "\n";
			script += std::to_string(++lineCount) + " ";
		}

		//script += ++lineCount;
		for (int j = 0; j < CHARACTER_TYPE; j++) {
			for (int i = 0; i < CHARACTER_NUM; i++) {
				if (bin.substr(0, 1) == character[j][i][1]) {
					script += character[j][i][0];
				}
			}
		}

		bin.erase(0, 1);
	}

	std::cout << script;

	std::cout << std::endl << std::endl << "----------------" << std::endl << std::endl << std::endl;
	std::system("pause");
	return 0;
}

/*


	�������Ԃ��󂵃]�[��

	int *a=NULL;
	*a = 10;


*/