uniform vec4 lightPos[8];
varying vec3 normal,eyeVec;
varying vec3 lightDir1,lightDir2,lightDir3,lightDir4,lightDir5,lightDir6,lightDir7,lightDir8;


void main()
	{
	vec4 final_color=vec4(0.0);
	//vec4 final_color=gl_LightSource[0].ambient;
	//(gl_FrontLightModelProduct.sceneColor * gl_FrontMaterial.ambient) + 
	//vec4 final_color=vec4(0);
	//vec3 E=normalize(eyeVec);
							
							
	vec3 N=normalize(normal);
	
	
	vec3 L;
	float lambertTerm;
	float attenuation;
	
	if(lightPos[0].w!=0.0)
		{
		float d=length(lightDir1);
		attenuation = 1.0 / (gl_LightSource[0].constantAttenuation +
                         gl_LightSource[0].linearAttenuation * d +
                         gl_LightSource[0].quadraticAttenuation * d * d);
		final_color+=(gl_LightSource[0].ambient*gl_FrontMaterial.ambient)*attenuation;
		
		L=normalize(lightDir1);
		lambertTerm=dot(N,L);
	
		if(lambertTerm>0.0)
			{
			final_color+=gl_Color*gl_LightSource[0].diffuse*lambertTerm*attenuation;	
		
			vec3 E=normalize(eyeVec);
			vec3 R=reflect(-L,N);
			float specular=pow(max(dot(R,E),0.0),gl_FrontMaterial.shininess);
			final_color+=gl_LightSource[0].specular*gl_FrontMaterial.specular*specular*attenuation;	
			}
		}
	
	if(lightPos[1].w!=0.0)
		{
		float d=length(lightDir1);
		attenuation = 1.0 / (gl_LightSource[0].constantAttenuation +
                         gl_LightSource[0].linearAttenuation * d +
                         gl_LightSource[0].quadraticAttenuation * d * d);
		final_color+=(gl_LightSource[1].ambient*gl_FrontMaterial.ambient*attenuation);
		L=normalize(lightDir2);
		lambertTerm=dot(N,L);
	
		if(lambertTerm>0.0)
			{
			final_color+=gl_Color*gl_LightSource[1].diffuse*lambertTerm*attenuation;	
		
			vec3 E=normalize(eyeVec);
			vec3 R=reflect(-L,N);
			float specular=pow(max(dot(R,E),0.0),gl_FrontMaterial.shininess);
			final_color+=gl_LightSource[1].specular*gl_FrontMaterial.specular*specular*attenuation;	
			}
		}
		
	if(lightPos[2].w!=0.0)
		{
		final_color+=(gl_LightSource[2].ambient*gl_FrontMaterial.ambient);
		L=normalize(lightDir3);
		lambertTerm=dot(N,L);
	
		if(lambertTerm>0.0)
			{
			final_color+=gl_Color*gl_LightSource[2].diffuse*lambertTerm;	
		
			vec3 E=normalize(eyeVec);
			vec3 R=reflect(-L,N);
			float specular=pow(max(dot(R,E),0.0),gl_FrontMaterial.shininess);
			final_color+=gl_LightSource[2].specular*gl_FrontMaterial.specular*specular;	
			}
		}
		
		if(lightPos[3].w!=0.0)
		{
		final_color+=(gl_LightSource[3].ambient*gl_FrontMaterial.ambient);
		L=normalize(lightDir4);
		lambertTerm=dot(N,L);
	
		if(lambertTerm>0.0)
			{
			final_color+=gl_Color*gl_LightSource[3].diffuse*lambertTerm;	
		
			vec3 E=normalize(eyeVec);
			vec3 R=reflect(-L,N);
			float specular=pow(max(dot(R,E),0.0),gl_FrontMaterial.shininess);
			final_color+=gl_LightSource[3].specular*gl_FrontMaterial.specular*specular;	
			}
		}
		
	
	

	gl_FragColor=final_color;		
	//gl_FragColor=vec4(L,0);	
	//gl_FragColor=gl_LightSource[0].diffuse;
	}