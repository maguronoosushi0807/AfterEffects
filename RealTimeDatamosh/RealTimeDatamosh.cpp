#include<Windows.h>
#include<lua.hpp>

struct Pixel {
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

int mosh(lua_State* L) {
	Pixel* pixels = reinterpret_cast<Pixel*>(lua_touserdata(L, 1));
	int w = static_cast<int>(lua_tointeger(L, 2));
	int h = static_cast<int>(lua_tointeger(L, 3));

	HANDLE hHeap = GetProcessHeap();
	if (hHeap == NULL) return -1;

	Pixel* mem = (Pixel*)HeapAlloc(hHeap, 0, sizeof(Pixel) * w * h);
	if (mem == NULL) return -1;

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int i = x + y * w;
			pixels[i].r = mem[i].r * 10;
			pixels[i].g = mem[i].g * 10;
			pixels[i].b = mem[i].b * 10;
		}
	}

	HeapFree(hHeap, 0, mem);

	return 0;
}

static luaL_Reg functions[] = {
	{ "mosh", mosh },
	{ nullptr, nullptr }
};

extern "C" {
	__declspec(dllexport) int luaopen_RealTimeDatamosh(lua_State* L) {
		luaL_register(L, "RealTimeDatamosh", functions);
		return 1;
	}
}