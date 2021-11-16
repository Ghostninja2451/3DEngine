#pragma once
#include"Math/MathTypes.h"
#include"document.h"
#include<vector>
#include<string>

#define JSON_READ(value, data) henry::json::Get(value, #data, data);

namespace henry
{
	namespace json
	{
		bool Load(const std::string& filename, rapidjson::Document& document);
		bool Get(const rapidjson::Value& value, const std::string& name, int& key);

		bool Get(const rapidjson::Value& value, const std::string& name, float& data);
		bool Get(const rapidjson::Value& value, const std::string& name, bool& data);
		bool Get(const rapidjson::Value& value, const std::string& name, std::string& data);
		bool Get(const rapidjson::Value& value, const std::string& name, glm::vec2& data);	
		bool Get(const rapidjson::Value& value, const std::string& name, glm::vec3& data);
		bool Get(const rapidjson::Value& value, const std::string& name, glm::vec4& data); 
		bool Get(const rapidjson::Value& value, const std::string& name, std::vector<int>& data);
		bool Get(const rapidjson::Value& value, const std::string& name, std::vector<std::string>& data);

	}
}