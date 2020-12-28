#ifndef H_CONFIG_PATHS
#define H_CONFIG_PATHS

#include <string>
#include <iostream>
#include "yaml-cpp/yaml.h"

struct ConfigPaths
{
public:
	std::string src;
	std::string out;
};

template<> struct YAML::convert<ConfigPaths> {
	static YAML::Node encode(const ConfigPaths& rhs) {
		YAML::Node node;
		node["src"] = rhs.src;
		node["out"] = rhs.out;
		return node;
	}

	static bool decode(const Node& node, ConfigPaths& rhs) {
		
		/*
		* Parser validations.
		*/

		// Both `src` and `out` fields are mandatory.
		if (!node["src"])
		{
			std::cout << "-- src field does not exist in node.\n";
			return false;
		}

		if (!node["out"])
		{
			std::cout << "-- out field does not exist in node.\n";
			return false;
		}

		// Both `src` and `out` fields should not be empty strings.
		if (node["src"].as<std::string>().empty())
		{
			std::cout << "-- src field cannot be an empty string.\n";
			return false;
		}

		if (node["out"].as<std::string>().empty())
		{
			std::cout << "-- out field cannot be an empty string.\n";
			return false;
		}
	
		rhs.src = node["src"].as<std::string>();
		rhs.out = node["out"].as<std::string>();

		return true;
	}
};

#endif //H_CONFIG_PATHS
