#include "ftp_client.hpp"

int main(void){
	Ftp_client* ftp_client = new Ftp_client();
	ftp_client->init();
	ftp_client->state = "login";
	while(ftp_client->running){
		ftp_client->handle_events();
		ftp_client->update();
		ftp_client->render(ftp_client->state);
	}
	ftp_client->close();
}
