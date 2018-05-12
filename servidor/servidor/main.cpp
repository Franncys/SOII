#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <stdio.h>

struct defenders {
	int id;
	int x;
	int y;
	powerups powers[10];
};

struct enemies {
	int id;
	int x;
	int y;
};

struct bombs {
	int id;
	int x;
	int y;
};

struct shots {
	int id;
	int x;
	int y;
};

struct powerups {
	int id;
	int type;
};

