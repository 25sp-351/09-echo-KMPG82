#include <stdio.h>
#include <string.h>

#define LOWER_BOUND_PORT 1024

int check_additional_characters(const char *buffer) {
    int length_parsed;
    
    sscanf(buffer, "%*d%n", &length_parsed);

    return (strlen(buffer) - length_parsed != 0);
}

int validate_port_number(const char *buffer, int *port_number) {
    return (!sscanf(buffer, "%d", port_number) || *port_number <= LOWER_BOUND_PORT);
}
