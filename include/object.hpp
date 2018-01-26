#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/FileResourceLoader.hpp>

class Object{
	public:
		Object(){}
		~Object();
		std::string name;
		sfg::Label label_text;
};

class File: public Object{
	public:
		File(){}
		~File();
};

class Folder: public Object{
	public:
		Folder(){}
		~Folder();
};

#endif
