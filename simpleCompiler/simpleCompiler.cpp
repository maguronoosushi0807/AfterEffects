#include<cstdlib>
#include<iostream>
#include<sstream>
#include<Windows.h>

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

BOOL setClipboardText(std::string string);

int main() {
	std::string script = "";
	std::string binary = "";
	std::string unCompileString = "";
	bool compiled = false;

	while (script != "end") {
		std::cout << "src : ";
		std::cin >> script;
		binary = "";
		unCompileString = "";

		//文字数表示用先頭文字
		char front = script.length() + 65;
		binary += front;

		int length = script.length();
		for (int k = 0; k < length; k++) {
			for (int j = 0; j < TYPE; j++) {
				for (int i = 0; i < CHARACTER_NUM; i++) {

					if (script.substr(k, 1) == dictionary[j][i][1]) {
						binary += dictionary[j][i][0];

						compiled = true;
						break;
					}

				}
			}
			//コンパイル不可
			if (!compiled) {
				unCompileString += script.substr(k, 2) + ", ";
			}
			compiled = false;
		}

		//クリップボードにコピー
		setClipboardText(binary);

		std::cout << "bin : " << binary << std::endl;
		std::cout << "length : " << script.length();

		std::cout << ", uncompiled : ";
		std::cout << "\x1b[41m" << "";
		std::cout << unCompileString;
		std::cout << "\x1b[40m" << "";

		std::cout << std::endl << std::endl;

	}

	return 0;
}

BOOL setClipboardText(std::string string) {
	int buf_size;
	char* str = const_cast<char*>(string.c_str());
	char* buf;
	HANDLE h_mem;

	buf_size = strlen(str) + 1;
	h_mem = GlobalAlloc(GMEM_SHARE | GMEM_MOVEABLE, buf_size);
	if (!h_mem) {
		std::cout << "クリップボードへのコピー用メモリの確保に失敗しました" << std::endl;
		return FALSE;
	}

	buf = reinterpret_cast<char*>(GlobalLock(h_mem));

	if (buf) {

		strcpy_s(buf, buf_size, str);

		// 2024.04.13 14:19
		// strcpy_s()関数で例外が発生した原因 : 
		// strcpy_s()関数の第2引数に、 char* buf  の参照先  HANDLE h_mem  の参照先のバッファサイズではなく、 
		// char* buf 自身の大きさ(4byte)を渡していたため、バッファーオーバーフローを起こしたから

		GlobalUnlock(h_mem);
		if (OpenClipboard(NULL)) {
			EmptyClipboard();
			SetClipboardData(CF_TEXT, h_mem);
			CloseClipboard();

			//std::cout << "成功" << std::endl;
			return TRUE;
		}
	}

	std::cout << "失敗" << std::endl;
	return FALSE;

};