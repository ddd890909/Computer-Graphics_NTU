uniform int lightIsOn[8];
varying vec3 N;
varying vec3 E;
varying vec3 L[8];
varying float dist[8];

void main()
{
	//vec4 ambientGlobal = gl_LightModel.ambient * gl_FrontMaterial.ambient;
	vec4 ambientGlobal = gl_LightModel.ambient * gl_Color;
	vec4 ambient, diffuse, specular;
	vec4 color = ambientGlobal;
	
	vec3 Normal, Half, Light, Eye;
	float NdotL, NdotHV;
	float att;
		
	Normal = normalize(N);
	Eye = normalize(E);
	
	for(int i = 0; i < 8; i++) {
		if(lightIsOn[i] == 1) {
			Light = normalize(L[i]);
			NdotL = max(dot(Normal, Light), 0.0);
			// ignore light from the back side
			if (NdotL > 0.0) {
				//ambient = gl_FrontLightProduct[i].ambient;
				ambient = gl_LightSource[i].ambient * gl_Color;
			
				diffuse = gl_LightSource[i].diffuse * gl_Color * NdotL;
			
				//Half = normalize(gl_LightSource[i].halfVector.xyz);
				Half = normalize(Eye + Light);
				NdotHV = max(dot(Normal, Half), 0.0);
				specular = gl_FrontLightProduct[i].specular * pow(NdotHV, gl_FrontMaterial.shininess);
			
				att = 1.0 / (gl_LightSource[i].constantAttenuation +
							 gl_LightSource[i].linearAttenuation * dist[i] +
							 gl_LightSource[i].quadraticAttenuation * dist[i] * dist[i]);
				color += att * (ambient + diffuse + specular);
			}
		}
	}

	gl_FragColor = color;
}
