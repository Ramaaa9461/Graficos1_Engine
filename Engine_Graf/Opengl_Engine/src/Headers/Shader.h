#pragma once
#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};


class Shader
{
private:

	std::string m_FilepPath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
#pragma region Shaders

	std::string vertexShader =
		//"#shader vertex								\n"
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"};\n";

	std::string fragmentShader =
		//"#shader fragment							\n"
		"#version 330 core\n"
		"\n"
		"	layout(location = 0) out vec4 color;"
		"\n"
		"	uniform vec4 u_Color;"
		"\n"
		"void main()\n"
		"{\n"
		"	color = u_Color;"
		"};\n";

#pragma endregion

public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	//Set uniforms
	void SetUniforms4f(const std::string name, float v0, float v1, float v2, float v3);

private:
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int GetUniformLocation(const std::string& name);
};

