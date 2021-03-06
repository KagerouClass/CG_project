#ifndef GLF_MAIN
#define GLF_MAIN

#define _CRT_SECURE_NO_WARNINGS
#define GLM_FORCE_RADIANS
#define FREEGLUT_STATIC
#define FIRENUM 1000

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <glfw/glew.h>
#include <gl/glaux.h> 
#include <gl/freeglut.h>

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#ifndef GL_Lib
#ifdef _DEBUG
#define GL_Lib(name) name "d.lib"
#else
#define GL_Lib(name) name ".lib"
#endif
#endif
#pragma comment(lib, GL_Lib("freeglut_static"))
#pragma comment(lib,"glew32.lib")

#define GLF_KEY_F1 0x01
#define GLF_KEY_F2 0x02
#define GLF_KEY_F3 0x03
#define GLF_KEY_F4 0x04
#define GLF_KEY_F5 0x05
#define GLF_KEY_F6 0x06
#define GLF_KEY_F7 0x07
#define GLF_KEY_F8 0x08
#define GLF_KEY_F9 0x09
#define GLF_KEY_F10 0x0A
#define GLF_KEY_F11 0x0B
#define GLF_KEY_F12 0x0C
#define GLF_KEY_LEFT 0x64
#define GLF_KEY_UP 0x65
#define GLF_KEY_RIGHT 0x66
#define GLF_KEY_DOWN 0x67
#define GLF_KEY_PAGEUP 0x68
#define GLF_KEY_PAGEDOWN 0x69
#define GLF_KEY_HOME 0x6A
#define GLF_KEY_END 0x6B
#define GLF_KEY_INSERT 0x6C
#define GLF_KEY_SHIFT 0x70
#define GLF_KEY_CTRL 0x72
#define GLF_KEY_ALT 0x74

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::list;

#define PI 3.14159265359

#define SHADOW_WIDTH 8192
#define SHADOW_HEIGHT 8192

template <typename T>
T *toArray(vector<T> *v) {
	return &((*v)[0]);
}
template <typename T>
T clamp(T low, T high, T input) {
	if (input < low)return low;
	if (input > high)return high;
	return input;
}
template <typename T>
T min(T x, T y) {
	return x < y ? x : y;
}
template <typename T>
T max(T x, T y) {
	return x > y ? x : y;
}
template <typename T>
T interpolate(float prop, T x, T y) {
	return x*prop + y*(1 - prop);
}

struct Mouse {
	glm::vec2 pre, tmp;
	int state[3];
	Mouse() {
		state[0] = state[1] = state[2] = 1;
	}
};
struct Keyboard {
	bool shift;
	bool ctrl;
	bool alt;
};

#endif