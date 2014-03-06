#pragma once
#include <string>

namespace MetaHub {

	class Node
	{
	public:
		Node(void);
		~Node(void);

		std::string name;
		unsigned short id;
	};


}