#ifndef COMPARTIDOS_H
#define COMPARTIDOS_H

typedef struct{
    char nombre[14];
    uint32_t nombre_length;
    uint32_t dni;
    uint32_t pasaporte;
    uint8_t edad;
} t_persona;

t_persona crear_persona(char *nombre, uint32_t dni, uint32_t pasaporte, uint8_t edad){
    t_persona persona;
    persona.dni = dni;
    persona.edad = edad;
    persona.pasaporte = pasaporte;
    strncpy(persona.nombre, nombre, 14);
    persona.nombre_length = string_length(nombre) + 1;
    return persona;
}

typedef struct{
    char* username;
    uint32_t username_length;
    char* message;
    uint32_t message_length;
} t_package;

t_package package_create(char *username, char* message){
    t_package package;
    package.username = string_duplicate(username);
    package.username_length = string_length(username);
    package.message = string_duplicate(message);
    package.message_length = string_length(message);
    return package;
}

typedef struct{
    uint32_t size; 
    uint32_t offset;
    void* stream;
}t_buffer2;

typedef struct{
    uint8_t codigo_operacion;
    t_buffer2* buffer;
} t_paquete2;

// t_paquete2 crear_paquete2(t_persona){
//     t_paquete2 paquete
// }


void imprimir_bytes(void* ptr, size_t size){
    printf("bytes: ");
	unsigned char* byte_ptr = (unsigned char*)ptr;
	for (int i = 0; i<size; i++){
		printf("%02X ", byte_ptr[i]);
	}
	printf("\n");
}

typedef struct{
	uint8_t codop;
	uint8_t size;
	char* data;
} polla;


#endif
