#include "client.h"
#include "../../server/compartidos.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	sleep(2);
	int conexion;

	conexion = crear_conexion("127.0.0.1", "4444");

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje("holaa", conexion);
	
	// t_persona persona;
	// persona = crear_persona("Ramiro", 43988884, 10000, 23);

	// t_buffer2* buffer = malloc(sizeof(t_buffer2));
	// buffer->size = sizeof(uint32_t) * 3
	// 			 + sizeof(uint8_t)
	// 			 + persona.nombre_length;
	// buffer->offset = 0;
	// buffer->stream = malloc(buffer->size);

	// memcpy(buffer->stream + buffer->offset, &persona.dni, sizeof(uint32_t));
	// buffer->stream += sizeof(uint32_t);
	// memcpy(buffer->stream + buffer->offset, &persona.edad, sizeof(uint8_t));
	// buffer->stream += sizeof(uint8_t);
	// memcpy(buffer->stream + buffer->offset, &persona.pasaporte, sizeof(uint32_t));
	// buffer->stream += sizeof(uint32_t);

	// memcpy(buffer->stream + buffer->offset, &persona.nombre_length, sizeof(uint32_t));
	// buffer->offset += sizeof(uint32_t);
	// memcpy(buffer->stream + buffer->offset, &persona.nombre, persona.nombre_length);

	// //free(persona.nombre);

	// t_paquete2* paquete = malloc(sizeof(t_paquete2));

	// paquete->codigo_operacion = 100;
	// printf("codigo de operación 'enviado' %d\n", paquete->codigo_operacion);
	// paquete->buffer = buffer;

	// printf("paquete: ");
	// printf(paquete);
	// printf("\n");
	// void* a_enviar = malloc(buffer->size + sizeof(uint8_t) + sizeof(uint32_t));
	// int offset = 0;

	// memcpy(a_enviar + offset, &(paquete->codigo_operacion), sizeof(uint8_t));

	// offset += sizeof(uint8_t);
	// memcpy(a_enviar + offset, &(paquete->buffer->size), sizeof(uint32_t));
	// offset += sizeof(uint32_t);
	// memcpy(a_enviar + offset, &(paquete->buffer->stream), paquete->buffer->size);

	// printf("a ver...");
	// printf("Contenido de a_enviar: \n");
	// //imprimir_bytes(a_enviar, buffer->size + sizeof(uint8_t) + sizeof(uint32_t));
	// send(conexion, a_enviar, buffer->size + sizeof(uint8_t) + sizeof(uint32_t), 0);


	char* leido = malloc(63);
	while (strcmp(leido, "exit") != 0)
	{
		leido = readline("> "); //sólo se puede hacer si leido se asigna con malloc
		//printf("Tamaño de leido: %d", strlen(leido));
		//send(conexion, leido, strlen(leido)+1, 0);
		uint8_t codop = 23;
		uint8_t tamanio_next = sizeof(uint32_t);
		uint32_t data = 99999;
		polla estructura;
		estructura.codop = 23;
		estructura.size = 4;
		estructura.data = malloc(4);
		strcpy(estructura.data, "asd");
		void* enviar = malloc(1 + 1 + 4);
		memcpy(enviar, &estructura.codop, 1);
		memcpy(enviar + 1, &estructura.size, 1);
		memcpy(enviar + 2, estructura.data, 4);
		printf("Data enviada: %s\n", estructura.data);
		send(conexion, enviar, 6, 0);
		free(enviar);
		free(estructura.data);

	}

	free(leido);

	close(conexion);
	// Armamos y enviamos el paquete
	//paquete(conexion);

}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;
	nuevo_logger = log_create("tp0.log", "Client.c", true, LOG_LEVEL_INFO);
	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;
	char *path= getcwd(NULL, 0);
	string_append(&path, "/cliente.config");
	nuevo_config = config_create(path);
	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");
	
	// El resto, las vamos leyendo y logueando hasta recibir un string vacío
	while (strcmp("", leido)!=0)
	{
		log_info(logger, leido);
		leido = readline("> ");
	}
	
	
	// ¡No te olvides de liberar las lineas antes de regresar!
	free(leido);
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete
	paquete = crear_paquete();
	while (true)
	{
		leido = readline("(·)(·)> ");
		printf("bro said");
		printf(leido);
		agregar_a_paquete(paquete, leido, sizeof(leido)+1);
		if (strcmp(leido, "")==0)
		{
			break;
		}
	}
	enviar_paquete(paquete, conexion);
	
	
	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	free(leido);
	free(paquete);
}
