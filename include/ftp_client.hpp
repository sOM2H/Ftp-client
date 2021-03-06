#ifndef FC_H
#define FC_H

#define SFML_MAIN_WINDOW_SIZE_WIDTH 800
#define SFML_MAIN_WINDOW_SIZE_HEIGHT 600

#define SFML_LOGIN_WINDOW_SIZE_WIDTH sfgui_login_window->GetAllocation().width
#define SFML_LOGIN_WINDOW_SIZE_HEIGHT sfgui_login_window->GetAllocation().height


#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class Ftp_client{
	public:
		Ftp_client();
		~Ftp_client();

		sf::Ftp ftp;

		bool running = false;

		sf::RenderWindow sfml_main_window;
		sfg::SFGUI sfgui;

		sfg::Desktop desktop;
		
		std::string state;
		
		sfg::Window::Ptr sfgui_login_window = sfg::Window::Create();
		sfg::Window::Ptr sfgui_main_window = sfg::Window::Create();

		sfg::Entry::Ptr login_entry = sfg::Entry::Create();
		sfg::Entry::Ptr password_entry = sfg::Entry::Create();
		sfg::Entry::Ptr host_entry = sfg::Entry::Create();

		sfg::Label::Ptr status_label = sfg::Label::Create();


		void init();
		void init_ftp_connection(std::string, std::string, std::string);
		void get_list_directory();
		std::string  get_current_name_directory();
		void handle_events();
		void render(std::string);
		void update();
		void close();
};

#endif 
