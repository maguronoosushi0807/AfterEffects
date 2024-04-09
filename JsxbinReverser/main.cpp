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

 全部取得
  ↓
 整形する
  ↓
 処理する

*/

// .jsxbin bin
// .jsx    script

int main() {
	std::ifstream file("ExpressionPaster.jsx");
	std::string bin = "";
	std::string script = "";

	//ファイルの読み込み
	if (!file) {
		std::cout << "ファイルを読み込めませんでした。" << std::endl;
		return -1;
	}
	else {
		std::string line;
		while (std::getline(file, line)) {
			bin += line;
		}

		std::cout << "コンパイルを開始します。" << std::endl;
		//std::cout << bin;
	}
	/*
	else {
		std::string line;
		while (std::getline(file, line)) {
			bin += line;
		}

		//先頭部分を削除
		std::string header = "@JSXBIN@ES@2.0@MyB";

		int header_position = bin.find(header);
		if (header_position == std::string::npos) {
			std::cout << "予測された先頭要素が見つかりませんでした。" << std::endl;
		}
		else {
			bin.erase(header_position, header.length() + 14);
		}

		//後端要素を削除
		std::string footer = "ByB";
		int footer_position = bin.find(footer);
		if (footer_position == std::string::npos) {
			std::cout << "予測された後端要素が見つかりませんでした。" << std::endl;
		}
		else {
			bin.erase(footer_position - 7, 7 + footer.length());
		}

		//std::cout << bin;
		std::cout << "逆コンパイルを開始します。" << std::endl << std::endl << std::endl;
	}


	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < CHARACTER_NUM; i++) {
			std::cout << character[0][i][1] << std::endl;
		}
	}


	//改行を置き換える
	std::regex line_break{ R"(.*fJ.*nAjzB)" };	//改行の正規表現（いかつい）
	std::string buf = bin;
	bin = std::regex_replace(buf, line_break, "\n");
	//std::cout << bin;

	//変換処理, 読み込んだバイナリ（？）が空になるまで調べる
	while (!bin.empty()) {
	}
	//2文字取得
	/*
	std::string replaceBuff = bin.substr(0, 2);
	bin.erase(0, 1);

	//一致する文字列がないか調べる
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

		//改行
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


	メモリぶっ壊しゾーン

	int *a=NULL;
	*a = 10;


*/