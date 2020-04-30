
#include "main.h"

/**
 * TODO: Refactor
 */
static char* opt_host_name = NULL;
static char* opt_user_name = NULL;
static char* opt_password = NULL;
static unsigned int opt_port_num = 0;
static char* opt_socket_name = NULL;
static char* opt_db_name = NULL;
static unsigned long opt_flags = 0;

static MYSQL* conn = NULL;

int main(int argc, char *argv[])
{
    /**
     * Get login credentials from command-line input.
     */
    if (argc == 1) {
        fprintf(stderr, "No login credentials provided.\n");
        return EXIT_FAILURE;
    } else if (argc != 3) {
        fprintf(stderr, "Username and password are both required.\n");
        return EXIT_FAILURE;
    }

    opt_user_name = argv[1];
    opt_password = argv[2];

    /**
     * Initialize the client library.
     */
    if (mysql_library_init(0, NULL, NULL)) {
        fprintf(stderr, "mysql_library_init() failed\n");
        return EXIT_FAILURE;
    }

    /**
     * Initialize the connection handler.
     */
    conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    /**
     * Connect to the server.
     */
    conn = mysql_real_connect(conn, opt_host_name, opt_user_name, opt_password, opt_db_name, opt_port_num, opt_socket_name, opt_flags);

    if (conn == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        return EXIT_FAILURE;
    }

    /**
     * TODO: Do the things.
     */
    printf("Successfully connected to the MariaDB server.\n");

    /**
     * Disconnect from the server and terminate the client library.
     */
    mysql_close(conn);
    mysql_library_end();

    return EXIT_SUCCESS;
}
