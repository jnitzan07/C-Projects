#ifndef EE200_LOGGER_H
#define EE200_LOGGER_H

//either write to file or create if !exists
void set_output_file(char* filepath);

//throws error to output file
void throw_error();

//basically just tries to figure out what caused the error
void catch_error();

#endif //EE200_LOGGER_H
