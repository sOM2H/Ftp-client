#include "ftp_client.hpp"

int main(void){
	Ftp_client* ftp_client = new Ftp_client();
	ftp_client->init();
	while(ftp_client->running){
		ftp_client->handle_events();
		ftp_client->update();
		ftp_client->render();
	}
	ftp_client->close();
}
