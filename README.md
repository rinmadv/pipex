# pipex

Purpose : This project aims at simulating pipes, redirections and heredoc. 

Exec name : pipex

**Execution exemple**

***Simple handle :***
$> ./pipex file1 cmd1 cmd2 file2
will act like 
$> < file1 cmd1 | cmd2 > file2

$> ./pipex infile "ls -l" "wc -l" outfile
will act like
$> ./pipex infile "grep a1" "wc -w" outfile

***Bonus handle :***

*- Multiple pipes*
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdN file2
will act like 
$> < file1 cmd1 | cmd2 | cmd3 | cmdN > file2

*- Here_doc and redirection with append mode*
$> ./pipex here_doc LIMITER cmd cmd1 file
will act like 
$> cmd << LIMITER | cmd1 >> file