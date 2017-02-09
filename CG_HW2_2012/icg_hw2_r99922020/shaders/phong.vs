#define MAX_LIGHTS 8

uniform int lightIsOn[MAX_LIGHTS];
varying vec3 N;
varying vec3 E;
varying vec3 L[MAX_LIGHTS];
varying float dist[MAX_LIGHTS];

void main()
{	
	N = normalize(gl_NormalMatrix * gl_Normal);
	
	vec3 ecVertexPos, ecLight;
	ecVertexPos = vec3(gl_ModelViewMatrix * gl_Vertex);
	E = normalize(-ecVertexPos);
	
	for(int i = 0; i < MAX_LIGHTS; i++) {
		if(lightIsOn[i] == 1) {
			ecLight = gl_LightSource[i].position.xyz - ecVertexPos;
			L[i] = normalize(ecLight);
			dist[i] = length(ecLight);
		}
	}
	
	gl_Position = ftransform();
	gl_FrontColor = gl_Color;
}