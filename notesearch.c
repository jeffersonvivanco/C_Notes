#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

#define FILENAME "/var/notes"

/*
 *This program will read the note data and only display the notes
  written by the user id.
 *Additionally, an optional command-line argument can be supplied
  for a search string. When this is used, only notes matching the
  search string will be displayed.
 * */

int print_notes(int, int, char *); // note printing function
int find_user_note(int, int); // seek in file for a note for user
int search_note(char *, char *); // search for keyword function
void fatal(char *); // fatal error handler

int main(int argc, char *argv[]){
	int userid, printing=1, fd; // File descriptor
	char searchstring[100];

	if(argc > 1) // if there is an arg
		strcpy(searchstring, argv[1]); // that is the search string
	else
		searchstring[0] = 0; // search string is empty

	userid = getuid();
	fd = open(FILENAME, O_RDONLY); // open the file for read only access
	if(fd == -1)
		fatal("in main() while opening file for reading");
	while(printing)
		printing = print_notes(fd, userid, searchstring);
	printf("---------------[end of note data]----------------\n");
	close(fd);
}

// a function to print the notes for a given uid that match an optional search string
// returns 0 at end of file, 1 is there are still more notes
int print_notes(int fd, int uid, char *searchstring){
	int note_length;
	char byte=0, note_buffer[100];

	note_length = find_user_note(fd, uid);
	if(note_length == -1) // if end of file reached
		return 0;
	read(fd, note_buffer, note_length); // read note data
	note_buffer[note_length] = 0; // terminate the string

	if(search_note(note_buffer, searchstring)) // if searchstring found
		printf(note_buffer); // print the note
	return 1;
}

// A function to find the next note for a given userID; returns -1 if the end of file is reached
// otherwise it returns the length of the found note

int find_user_note(int fd, int user_uid){
	int note_uid = -1;
	unsigned char byte;
	int length;

	while(note_uid != user_uid) { // loop until a note for user_uid is found
		if(read(fd, &note_uid, 4) != 4) // read the uid data
			return -1; // if 4 bytes are not found, return end of file code
		if(read(fd, &byte, 1) != 1) // read the newline seperator
			return -1;

		byte = length = 0;
		while(byte != '\n'){ // figure out how many bytes until end of line
			if(read(fd, &byte, 1) != 1) // read a single byte
				return -1; // if byte is not read, return end of file code
			length++;
		}
	}
	lseek(fd, length * -1, SEEK_CUR); // rewind file reading by length bytes

	printf("[DEBUG] found a %d byte note for user id %d\n", length, note_uid);
	return length;
}

// a function to search a note for a given keyword
// returns 1 if match is found, 0 if there is no match

int search_note(char *note, char *keyword){
	int i, keyword_length, match=0;

	keyword_length = strlen(keyword);
	if(keyword_length == 0)
		return 1; // if there is no search string, always match

	for(i = 0; i < strlen(note); i++){ // iterate over bytes in note
		if(note[i] == keyword[match]) // if byte matches keywrod
			match++; // get ready to check the next byte
		else {
			if(note[i] == keyword[0]) // if that byte matches first keyword byte
				match =1; // start the match at count 1
			else
				match = 0; 
		}
		if(match == keyword_length)
			return 1; // if there is a full match
	}
	return 0; // return not matched
}





