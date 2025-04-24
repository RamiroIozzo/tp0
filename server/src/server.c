#include "server.h"
#include "../../server/compartidos.h"

int main(void) {
	logger = log_create("log.log", "Servidor", 1, LOG_LEVEL_DEBUG);

	int server_fd = iniciar_servidor();
	log_info(logger, "Servidor listo para recibir al cliente");
	int cliente_fd = esperar_cliente(server_fd);


	t_paquete2* paquete = malloc(sizeof(t_paquete2));
	paquete->buffer = malloc(sizeof(t_buffer2));
	paquete->codigo_operacion = 1;
	printf("Cod op recibido: %d\n", paquete->codigo_operacion);
	
	
	

	recv(cliente_fd, &(paquete->codigo_operacion), sizeof(uint8_t), 0);
	recv(cliente_fd, &(paquete->buffer->size), sizeof(uint32_t), 0);
	paquete->buffer->stream = malloc(paquete->buffer->size);
	recv(cliente_fd, &(paquete->buffer->stream), paquete->buffer->size, 0);

	printf("Cod op recibido: %d\n", paquete->codigo_operacion);
	//printf("Bytes_recibidos %d\n", bytes_recibidos);
	printf("paquete: ");
	printf(paquete);
	printf("\n");
	
	//falta deserializar
	return 0;
	char buffer[1024];
	ssize_t bytes_recived;
	while (bytes_recived!=0)
	{
		//bytes_recived = recv(cliente_fd, buffer, sizeof(buffer)-1, 0);
		printf("%s\n", buffer);
	}
	
	


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
