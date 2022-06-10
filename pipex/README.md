Pipex was about recoding the pipe command. The usage is different from the "normal" pipe command.

Mandatory where to handle one pipe. The bonus part of this project was to be able to handle multiple pipes.

Usage: pipex "infile" "command1" ... "commandN" "outfile"

-------------------------------------------------------

It works by first opening the pipes. After that a the first command is build using the binary provided or, in case of an relative path, using the PATH variable. Then it creates a child-process and sets STDIN to the infile-fd an STDOUT to in-fd of the first pipe and them executing the command. Second command is handled the same except STDIN  is pipe1-out and STDOUT is pipe2-in. This is repeated until the last command where STDOUT is set to outfile-fd.
