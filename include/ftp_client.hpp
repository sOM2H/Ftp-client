#ifndef FC_H
#define FC_H

#define SFML_MAIN_WINDOW_SIZE_WIDTH 800
#define SFML_MAIN_WINDOW_SIZE_HEIGHT 600

#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class Ftp_client{
	public:
		Ftp_client();
		~Ftp_client();

		bool running = false;

		sf::RenderWindow sfml_main_window;
		sfg::SFGUI sfgui;

		sfg::Window::Ptr sfgui_login_window = sfg::Window::Create();

		void init();
		void handle_events();
		void render();
		void update();
		void close();
};

#endif 
