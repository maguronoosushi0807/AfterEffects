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

		//�������\���p�擪����
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
			//�R���p�C���s��
			if (!compiled) {
				unCompileString += script.substr(k, 2) + ", ";
			}
			compiled = false;
		}

		//�N���b�v�{�[�h�ɃR�s�[
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
		std::cout << "�N���b�v�{�[�h�ւ̃R�s�[�p�������̊m�ۂɎ��s���܂���" << std::endl;
		return FALSE;
	}

	buf = reinterpret_cast<char*>(GlobalLock(h_mem));

	if (buf) {

		strcpy_s(buf, buf_size, str);

		// 2024.04.13 14:19
		// strcpy_s()�֐��ŗ�O�������������� : 
		// strcpy_s()�֐��̑�2�����ɁA char* buf  �̎Q�Ɛ�  HANDLE h_mem  �̎Q�Ɛ�̃o�b�t�@�T�C�Y�ł͂Ȃ��A 
		// char* buf ���g�̑傫��(4byte)��n���Ă������߁A�o�b�t�@�[�I�[�o�[�t���[���N����������

		GlobalUnlock(h_mem);
		if (OpenClipboard(NULL)) {
			EmptyClipboard();
			SetClipboardData(CF_TEXT, h_mem);
			CloseClipboard();

			//std::cout << "����" << std::endl;
			return TRUE;
		}
	}

	std::cout << "���s" << std::endl;
	return FALSE;

};