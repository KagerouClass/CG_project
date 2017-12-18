#include <GL/glew.h>
//#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <gl/glew.h>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>
#include <string>
#define WAVE_COUNT		6
#define STRIP_COUNT		80
#define STRIP_LENGTH	50
static const GLfloat gerstner_pt_a[22] = {
	0.0,0.0, 41.8,1.4, 77.5,5.2, 107.6,10.9,
	132.4,17.7, 152.3,25.0, 167.9,32.4, 179.8,39.2,
	188.6,44.8, 195.0,48.5, 200.0,50.0
};
static const GLfloat gerstner_pt_b[22] = {
	0.0,0.0, 27.7,1.4, 52.9,5.2, 75.9,10.8,
	97.2,17.6, 116.8,25.0, 135.1,32.4, 152.4,39.2,
	168.8,44.8, 184.6,48.5, 200.0,50.0
};
static GLfloat wave_strip[STRIP_COUNT * STRIP_LENGTH * 3];
static struct wave
{
	GLfloat time[WAVE_COUNT];
	GLfloat wave_len[WAVE_COUNT];
	GLfloat wave_amp[WAVE_COUNT];
	GLfloat wave_speed[WAVE_COUNT];
	GLfloat wave_dir[WAVE_COUNT];
	GLfloat wave_start[WAVE_COUNT * 2];
}waveValues;
static GLfloat calcu_GerstnerZ(GLfloat length, GLfloat amplitude, GLfloat xy_result, const GLfloat Gerstner[22])
{//�����ڲ庯������Gerstner������ά�����ϵĸ߶�z��������������Ҫ���빫ʽһ��һ�����㣬Ϊ���Ż�������
//�����ڲ�ķ������ơ��˷��ɴ�����Ч�ʡ�
	//xy_resultΪ����ά�ռ��е�x y���꾭��һ��ת������ת�����ɵ����꣬������ɵ���x��������ά��
	//Gerstner�����̴Ӷ�������߶�ֵz
	xy_result = xy_result * 400.0 / length;
	//�˴��Ƚ�������xy_resultֵ����[0, 400]��domain, map����Ӧ����ֵ��
	while (xy_result < 0.0)//�������ԣ���ʱ������࣬�ƶ���0��400֮��
		xy_result += 400.0;
	while (xy_result > 400.0)//�������ԣ���ʱ�����Ҳ࣬�ƶ���0��400֮��
		xy_result -= 400.0;
	if (xy_result > 200.0)//���ڸò��ϰ��������°����ڶԳƣ�������������°����ڣ��ƶ��ص�һ�ϰ�����
		xy_result = 400.0 - xy_result;
	//
	int i = 0;
	while (i <= 18 && xy_result < Gerstner[i] || xy_result >= Gerstner[i+2])
		i += 2;
	//���Բ�ֵ����ʹ������������Ѱ�ҵ�һ�齫������м��2����
	if(xy_result == Gerstner[i])
		return Gerstner[i] * (amplitude / 50.0);
	if (xy_result > Gerstner[i])
		return ((Gerstner[i+3] - Gerstner[i+1]) * (Gerstner[i+2] - Gerstner[i])
		     / (Gerstner[i+2] - Gerstner[i])
			 + Gerstner[i+3]) * amplitude / 50.0;
	//z'=(y1-y0)(x1-x0)
	//   --------------  + y1
	//      (x1-x0)
	//z = z' * ��� / 50
}

static void calcu_Wave()
{
	GLfloat d, waveZ;
	int i = 0, w = 0;
	d = (wave_strip[i] - waveValues.wave_amp[w*2]) + (wave_strip[i+1] - waveValues.wave_amp[w*2+1]) * tan(waveValues.wave_dir[w])
		* cos(waveValues.wave_dir[w]);
	waveZ += waveValues.wave_amp[w] - calcu_GerstnerZ(waveValues.wave_len[w], waveValues.wave_amp[w], d + waveValues.wave_speed[w], gerstner_pt_a);
	return;
}
int main()
{

	return 0;
}
