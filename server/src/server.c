#include "server.h"
#include "../../server/compartidos.h"
//server
int main(void) {
	logger = log_create("log.log", "Servidor", 1, LOG_LEVEL_DEBUG);

	int server_fd = iniciar_servidor();
	log_info(logger, "Servidor listo para recibir al cliente");
	int cliente_fd = esperar_cliente(server_fd);

	
	// t_paquete2* paquete = malloc(sizeof(t_paquete2));
	// paquete->buffer = malloc(sizeof(t_buffer2));
	// paquete->codigo_operacion = 1;
	// printf("Cod op recibido: %d\n", paquete->codigo_operacion);



	// recv(cliente_fd, &(paquete->codigo_operacion), sizeof(uint8_t), 0);
	// recv(cliente_fd, &(paquete->buffer->size), sizeof(uint32_t), 0);
	// paquete->buffer->stream = malloc(paquete->buffer->size);
	// recv(cliente_fd, &(paquete->buffer->stream), paquete->buffer->size, 0);

	// printf("Cod op recibido: %d\n", paquete->codigo_operacion);
	// //printf("Bytes_recibidos %d\n", bytes_recibidos);
	// printf("paquete: "); printf(paquete); printf("\n"); printf("HOOOOOOOOLAAAAAAAAAA\n");
	// free(logger);
	// //free(paquete->buffer->stream);
	// free(paquete->buffer);
	// free(paquete);
	// //falta deserializar
	// //return 0;
	char buffer[64]={0};
	int bytes_recived = 1;
	bytes_recived = recv(cliente_fd, &buffer, 64, 0);
	printf("Buffer: %s\n", buffer);
	while (bytes_recived != 0)
	{

		

		uint8_t codop;
		uint8_t tamanio_next;
		bytes_recived = recv(cliente_fd, &codop, 1, 0);
		bytes_recived = recv(cliente_fd, &tamanio_next, 1, 0);
		printf("codop: %d\ntamanio: %d\n", codop, tamanio_next);
		
 		char* data=malloc(4);
		bytes_recived = recv(cliente_fd, data, 4, 0);
		printf("DATA: %s\n", data);
		free(data);
	}

	//free(buffer);




	//t_list* lista;
	// while (1) {
	// 	int cod_op = recibir_operacion(cliente_fd);
	// 	switch (cod_op) {
	// 	case MENSAJE:
	// 		recibir_mensaje(cliente_fd);
	// 		//break;
	// 	case PAQUETE:
	// 		lista = recibir_paquete(cliente_fd);
	// 		log_info(logger, "Me llegaron los siguientes valores:\n");
	// 		list_iterate(lista, (void*) iterator);
	// 		//break;
	// 	case -1:
	// 		log_error(logger, "el cliente se desconecto. Terminando servidor");
	// 		return EXIT_FAILURE;
	// 	default:
	// 		log_warning(logger,"Operacion desconocida. No quieras meter la pata");
	// 		break;
	// 	}
	// }
	// return EXIT_SUCCESS;
}

void iterator(char* value) {
	log_info(logger,"%s", value);
}
