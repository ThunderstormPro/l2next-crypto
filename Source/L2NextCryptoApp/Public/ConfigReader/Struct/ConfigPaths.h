#ifndef H_CONFIG_PATHS
#define H_CONFIG_PATHS

#include <string>
#include <iostream>
#include "yaml-cpp/yaml.h"

using namespace std;
using namespace YAML;

struct ConfigPaths
{
public:
	string src;
	string out;
};

template<> struct convert<ConfigPaths> {
	static Node encode(const ConfigPaths& rhs) {
		Node node;
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
			cout << "-- src field does not exist in node.\n";
			return false;
		}

		if (!node["out"])
		{
			cout << "-- out field does not exist in node.\n";
			return false;
		}

		// Both `src` and `out` fields should not be empty strings.
		if (node["src"].as<string>().empty())
		{
			cout << "-- src field cannot be an empty string.\n";
			return false;
		}

		if (node["out"].as<string>().empty())
		{
			cout << "-- out field cannot be an empty string.\n";
			return false;
		}
	
		rhs.src = node["src"].as<string>();
		rhs.out = node["out"].as<string>();

		return true;
	}
};

#endif //H_CONFIG_PATHS
