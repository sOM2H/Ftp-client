#include "ftp_client.hpp"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/FileResourceLoader.hpp>
#include <iostream>

Ftp_client::Ftp_client()
	: sfml_main_window(sf::VideoMode(800, 600), "FTP-Client", sf::Style::Titlebar | sf::Style::Close){
}

void Ftp_client::init(){
	running = true;

	sfml_main_window.resetGLStates();

	sfgui_login_window->SetStyle(sfg::Window::Style::BACKGROUND);
	sfgui_login_window->SetRequisition(sf::Vector2f(SFML_MAIN_WINDOW_SIZE_WIDTH, SFML_MAIN_WINDOW_SIZE_HEIGHT));
}

void Ftp_client::handle_events(){
	sf::Event event;
	while(sfml_main_window.pollEvent(event)){
		if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
			running = false;
		}
		sfgui_login_window->HandleEvent(event);
	}
}

void Ftp_client::render(){
	sfgui_login_window->Update(0.f);
	sfml_main_window.clear();
	sfgui.Display(sfml_main_window);
	sfml_main_window.display();
}

void Ftp_client::update(){

}

void Ftp_client::close(){
	sfml_main_window.close();
}
