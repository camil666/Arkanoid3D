varying vec3 vertex_light_position;
varying vec3 vertex_light_half_vector;
varying vec3 vertex_normal;
void main() {
	//even more magic!
    vec4 ambient_color = gl_FrontMaterial.ambient * gl_LightSource[0].ambient + gl_LightModel.ambient * gl_FrontMaterial.ambient;
    vec4 diffuse_color = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
    vec4 specular_color = gl_FrontMaterial.specular * gl_LightSource[0].specular * pow(max(dot(vertex_normal, vertex_light_half_vector), 0.0) , gl_FrontMaterial.shininess);
    float diffuse_value = max(dot(vertex_normal, vertex_light_position), 0.0);
    gl_FragColor = ambient_color + diffuse_color * diffuse_value + specular_color;
}