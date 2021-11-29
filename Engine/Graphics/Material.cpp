#include "Material.h"

namespace henry
{
	void Material::Bind()
	{
		for (auto& texture : textures)
		{
			texture->Bind();
		}
	}

	void Material::SetProgram(Program& program)
	{
		program.Use();
	}
}
