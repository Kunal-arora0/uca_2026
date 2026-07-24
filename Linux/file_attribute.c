#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[]) {
  struct stat fileInfo;

  if (argc != 2) {
    printf("Usage: %s <file_path>\n", argv[0]);
    exit(-1);
  }

  if (stat(argv[1], &fileInfo) == -1) {
    printf("Error Opening File");
    exit(-1);
  }

  printf("\n === FILE ATTRIBUTES FOR : %s ===\n", argv[1]);

  if (S_ISREG(fileInfo.st_mode)) {
    printf("File type : Regular file\n");
  } else if (S_ISDIR(fileInfo.st_mode)) {
    printf("File type : Directory \n");
  } else if (S_ISLNK(fileInfo.st_mode)) {
    printf("File type : Symbolic Link\n");
  } else {
    printf("File type : Other\n");
  }
  printf("Permission : %04o\n", fileInfo.st_mode & 0777);
  printf("File size %ld bytes\n", fileInfo.st_size);
  printf("Hard Links Count : %u\n", fileInfo.st_nlink);
  printf("Owner(UID) : %d\n", fileInfo.st_uid);
  printf("Group(UID) : %u\n", fileInfo.st_gid);
  printf("Last Access Time :%s", ctime(&fileInfo.st_atime));
  printf("Last Modification Time :%s", ctime(&fileInfo.st_mtime));
  printf("Status Change Time : %s", ctime(&fileInfo.st_ctime));

  return 0;
}
