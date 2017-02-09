uniform int lightIsOn[8];
varying vec3 N;
varying vec3 E;
varying vec3 L[8];
varying float dist[8];

void main()
{	
	N = normalize(gl_NormalMatrix * gl_Normal);
	
	vec3 ecVertexPos, ecLight;
	ecVertexPos = vec3(gl_ModelViewMatrix * gl_Vertex);
	E = normalize(-ecVertexPos);
	
	for(int i = 0; i < 8; i++) {
		if(lightIsOn[i] == 1) {
			ecLight = gl_LightSource[i].position.xyz - ecVertexPos;
			L[i] = normalize(ecLight);
			dist[i] = length(ecLight);
		}
	}
	
	gl_Position = ftransform();
	gl_FrontColor = gl_Color;
}
