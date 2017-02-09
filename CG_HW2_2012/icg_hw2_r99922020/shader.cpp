
#include "shader.h"
#include "utils.h"
#include <GL/glew.h>

Shader::~Shader() 
{
	glDetachShader(prog, vShader);
	glDetachShader(prog, fShader);
	glDeleteShader(vShader);
	glDeleteShader(fShader);
	glDeleteProgram(prog);
}

void Shader::load(char *vspath,char *fspath)
{
	char *vsSource,*fsSource;
	vsSource = textFileRead(vspath);
	fsSource = textFileRead(fspath);
	vShader = glCreateShader(GL_VERTEX_SHADER);
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* vsSc = vsSource;
	const char* fsSc = fsSource;
	glShaderSource(vShader, 1, &vsSc, NULL);
	glShaderSource(fShader, 1, &fsSc, NULL);
	free(vsSource);
	free(fsSource);
	glCompileShader(vShader);
	glCompileShader(fShader);
	printShaderInfoLog(vShader);
	printShaderInfoLog(fShader);
	prog = glCreateProgram();
	glAttachShader(prog, vShader);
	glAttachShader(prog, fShader);
	glLinkProgram(prog);
	printProgramInfoLog(prog);
}

void Shader::useProgram()
{
	glUseProgram(prog);
}

void Shader::printShaderInfoLog(int obj)
{
	int infologLength = 0;
	int charsWritten  = 0;
	char *infoLog;

	glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &infologLength);

	if(infologLength > 0) {
		infoLog = (char *)malloc(infologLength);
		glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog);
		if(strlen(infoLog) != 0)
			printf("%s\n", infoLog);
		free(infoLog);
	}
}

void Shader::printProgramInfoLog(int obj)
{
	int infologLength = 0;
	int charsWritten  = 0;
	char *infoLog;
	
	glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &infologLength);
	if(infologLength > 0) {
		infoLog = (char *)malloc(infologLength);
		glGetProgramInfoLog(obj, infologLength, &charsWritten, infoLog);
		if(strlen(infoLog) != 0)
			printf("%s\n", infoLog);
		free(infoLog);
	}
}
