#include "ftp_client.hpp"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/FileResourceLoader.hpp>
#include <iostream>

Ftp_client::Ftp_client()
	: sfml_main_window(sf::VideoMode(SFML_MAIN_WINDOW_SIZE_WIDTH, SFML_MAIN_WINDOW_SIZE_HEIGHT), "FTP-Client", sf::Style::Titlebar | sf::Style::Close){
}

void Ftp_client::init(){
	running = true;

	sfml_main_window.resetGLStates();

	sfgui_main_window->SetStyle(sfg::Window::Style::BACKGROUND);
	sfgui_main_window->SetRequisition(sf::Vector2f(SFML_MAIN_WINDOW_SIZE_WIDTH, SFML_MAIN_WINDOW_SIZE_HEIGHT));
	
	sfgui_login_window->SetStyle(sfg::Window::Style::BACKGROUND);
	sfgui_login_window->SetRequisition(sf::Vector2f(SFML_LOGIN_WINDOW_SIZE_WIDTH, SFML_LOGIN_WINDOW_SIZE_HEIGHT));

	
	//login_entry->SetText("Login");
	login_entry->SetRequisition(sf::Vector2f());

	//password_entry->SetText("Password");
	password_entry->HideText('*');
	password_entry->SetRequisition(sf::Vector2f());

	//host_entry->SetText("Host");
	host_entry->SetRequisition(sf::Vector2f());

	auto button = sfg::Button::Create();
	button->SetLabel("Login");
	button->GetSignal( sfg::Widget::OnLeftClick ).Connect( [&] {
			init_ftp_connection(login_entry->GetText(), password_entry->GetText(), host_entry->GetText());
	} );
	

	sfg::Box::Ptr box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);

	box->SetSpacing(5.f);

	sfg::Box::Ptr box_login = sfg::Box::Create();
	sfg::Box::Ptr box_password = sfg::Box::Create();
	sfg::Box::Ptr box_host = sfg::Box::Create();

	sfg::Label::Ptr login_label = sfg::Label::Create();
	login_label->SetText("Login");
	login_label->SetRequisition(sf::Vector2f(100, 0));

	sfg::Label::Ptr password_label = sfg::Label::Create();
	password_label->SetText("Password");
	password_label->SetRequisition(sf::Vector2f(100, 0));

	sfg::Label::Ptr host_label = sfg::Label::Create();
	host_label->SetText("Host");
	host_label->SetRequisition(sf::Vector2f(100, 0));

	login_entry->SetRequisition(sf::Vector2f(300, 0));
	password_entry->SetRequisition(sf::Vector2f(300, 0));
	host_entry->SetRequisition(sf::Vector2f(300, 0));

	box_login->Pack(login_label);
	box_login->Pack(login_entry, false, false);

	box_password->Pack(password_label);
	box_password->Pack(password_entry, false, false);

	box_host->Pack(host_label);
	box_host->Pack(host_entry, false, false);

	box->Pack(box_host);
	box->Pack(box_login);
	box->Pack(box_password);
	box->Pack(button);


	sfgui_login_window->Add(box);
	sfgui_login_window->SetRequisition(sf::Vector2f(SFML_MAIN_WINDOW_SIZE_WIDTH / 2 - SFML_LOGIN_WINDOW_SIZE_WIDTH / 2, SFML_MAIN_WINDOW_SIZE_HEIGHT/2 - SFML_LOGIN_WINDOW_SIZE_HEIGHT/2));
	//sfgui_login_window->SetPosition(sf::Vector2f(SFML_MAIN_WINDOW_SIZE_WIDTH / 2 - sfgui_login_window->GetRequisition().x/2, SFML_MAIN_WINDOW_SIZE_HEIGHT/2 - sfgui_login_window->GetRequisition().y/2));

	desktop.Add(sfgui_login_window);
	
	sfml_main_window.setSize(sf::Vector2u(SFML_LOGIN_WINDOW_SIZE_WIDTH, SFML_LOGIN_WINDOW_SIZE_HEIGHT));
}

void Ftp_client::handle_events(){
	sf::Event event;
	while(sfml_main_window.pollEvent(event)){
		if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
			running = false;
		}
		desktop.HandleEvent(event);
	}
}

void Ftp_client::render(std::string state){
	desktop.Update(0.f);
	sfml_main_window.clear();
	sfgui.Display(sfml_main_window);
	sfml_main_window.display();
}

void Ftp_client::update(){

}

void Ftp_client::close(){
	sfml_main_window.close();
}

void Ftp_client::init_ftp_connection(std::string login, std::string password, std::string host){
	sf::Ftp::Response response_connect = ftp.connect(host, 21, sf::seconds(5));
   	if(response_connect.isOk()){
		sf::Ftp::Response response_login  = ftp.login(login, password );
		if(response_login.isOk()){
			std::cout<<"########################\n";
			std::cout<< "Connect to server: " << host << ".\n" << "	Login: " << login << ".\n";
			std::cout<<"########################\n\n";
			state = "main";
			sfml_main_window.setSize(sf::Vector2u(SFML_MAIN_WINDOW_SIZE_WIDTH, SFML_MAIN_WINDOW_SIZE_HEIGHT));
			desktop.Add(sfgui_main_window);
			desktop.BringToFront( sfgui_main_window ); 
			return;
		}else{
			std::cout<< "Login Error.\n\n";

		}
	}else{
		std::cout<< "Connect Error.\n\n";
	}	
	ftp.disconnect();
}

