#include <stdio.h>
#include <string.h>

#include "setup_server.h"
#include "usage_message.h"

#define DEFAULT_PORT 1025

int main(int argc, char* argv[]) {
    int should_print_messages = 0;
    int port_number           = DEFAULT_PORT;

    if (argc > 4) {
        usage_message();
        return 0;
    }

    for (int ix = 1; ix < argc; ix++) {
        if (strcmp(argv[ix], "-v") == 0) {
            should_print_messages = 1;
            continue;
        }

        if (strcmp(argv[ix], "-p") == 0) {
            // TODO compare length parsed to length of string error chekcing
            if (argc <= ix + 1 || !sscanf(argv[ix + 1], "%d", &port_number) ||
                port_number <= 1024) {
                usage_message();
                return 0;
            }

            continue;
        }
    }

    setup_server(port_number, should_print_messages);

    return 0;
}
