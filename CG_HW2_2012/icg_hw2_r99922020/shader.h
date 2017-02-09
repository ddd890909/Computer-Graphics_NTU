
#ifndef SHADER_H
#define SHADER_H

class Shader {
public:
	int vShader, fShader, prog;
	
	Shader() {};
	~Shader();
	void load(char *vspath, char *fspath); 
	void useProgram();
	void printShaderInfoLog(int obj);
	void printProgramInfoLog(int obj);
};


#endif