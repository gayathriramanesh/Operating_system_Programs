#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int option;
    char str[20], str1[40], str2[40], file1[40], file2[40];
printf("Options:\n1.ls\n2.cat\n3.pwd\n4.clear\n5.ps\n6.date\n7.cal\n8.man\n9.cp\n10.r m\n");
printf("Enter your choice:");
scanf("%d",&option);
printf("\n");
switch(option)
{
    case 1:
        printf("\nEnter filename 1: ");
        scanf("%s", str1);
        printf("\nEnter filename 2: ");
        scanf("%s", str2);
        execl("/bin/ls", "ls", str1, str2, NULL);
        break;
    case 2:
        printf("\nEnter the file name 1: ");
        scanf("%s", file1);
        printf("\nEnter the file name 2: ");
        scanf("%s", file2);
        execl("/bin/cat", "cat", file1, file2, NULL);
        break;
    case 3:
        execl("/bin/pwd", "pwd", NULL);
        break;
    case 4:
        execl("/bin/clear", "clear", NULL);
        break;
    case 5:
        execl("/bin/ps", "ps", NULL);
        break;
    case 6:
        printf("Enter type: ");
        scanf("%s", str);
        execl("/bin/date", "date", str, NULL);
        break;
    case 7:
        printf("\nEnter month and year: ");
        scanf("%s %s", str, str1);
        execl("/bin/cal", "cal", str, str1, NULL);
        break;
    case 8:
        printf("Enter the command which you want to search: ");
        scanf("%s", str);
        execl("/bin/man", "man", str, NULL);
        break;
    case 9:
        printf("\nEnter the source file and the destination file: ");
        scanf("%s %s", file1, file2);
        execl("/bin/cp", "cp", file1, file2, NULL);
        break;
    case 10:
        printf("\nEnter file to be removed: ");
        scanf("%s", file1);
        execl("/bin/rm", "rm", file1, NULL);
        break;
    default:
        printf("Please enter a proper choice\n");
}
return 0;
}
